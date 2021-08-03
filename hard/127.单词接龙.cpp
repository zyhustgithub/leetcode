/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

constexpr int NUM_WORDS = 26;  // 26个小写英文字母
struct Node {
    struct Node* next[NUM_WORDS] = { nullptr };
    bool isEnd = false;
};

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList)
    {
        Node* rootNode = new Node();
        CreatePrefixTree(wordList, rootNode);

        if (!Find(rootNode, endWord)) {
            return 0;
            FreeNode(rootNode);
        }

        int res = BFS(rootNode, beginWord, endWord);
        FreeNode(rootNode);
        return res;
    }

    int BFS(Node* rootNode, const std::string& beginWord, const std::string& endWord)
    {
        std::queue<std::string> queueStr{};
        queueStr.push(beginWord);
        m_setVisited.insert(beginWord);

        int steps = 1;
        while (!queueStr.empty()) {
            std::queue<std::string> queueSwap{};
            queueSwap.swap(queueStr);
            while (!queueSwap.empty()) {
                std::string strWord = queueSwap.front();
                queueSwap.pop();
                if (strWord == endWord) {
                    return steps;
                }

                for (int idx = 0; idx < strWord.size(); ++idx) {
                    std::string strCheck{ strWord };
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == strWord[idx]) {
                            continue;
                        }
                        strCheck[idx] = ch;
                        if ((Find(rootNode, strCheck)) && (m_setVisited.count(strCheck) == 0)) {
                            m_setVisited.insert(strCheck);
                            queueStr.push(strCheck);
                        }
                    }
                }
            }

            ++steps;
        }

        return 0;
    }

    // 构造前缀树
    void CreatePrefixTree(const std::vector<std::string>& wordList, Node* rootNode)
    {
        for (const auto& word : wordList) {
            Node* curNode = rootNode;
            for (char itChar : word) {
                uint32_t idx = itChar - 'a';
                if (curNode->next[idx] == nullptr) {
                    Node* newNode = new Node();
                    curNode->next[idx] = newNode;
                }

                curNode = curNode->next[idx];
            }

            curNode->isEnd = true;
        }
    }

    bool Find(Node* rootNode, const std::string& strWord)
    {
        if (strWord.empty()) {
            return false;
        }

        Node* curNode = rootNode;
        for (auto itChar : strWord) {
            int idx = itChar - 'a';
            if (curNode->next[idx] == nullptr) {
                return false;
            }

            curNode = curNode->next[idx];
        }

        return true;
    }

    void FreeNode(Node* node)
    {
        if (node == nullptr) {
            return;
        }

        for (int idx = 0; idx < NUM_WORDS; ++idx) {
            FreeNode(node->next[idx]);
        }

        delete node;
    }

private:
    std::unordered_set<std::string> m_setVisited{};
};
// @lc code=end

