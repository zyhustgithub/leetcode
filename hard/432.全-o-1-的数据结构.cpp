/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start
struct Node {
    int val;
    unordered_set<string> keys;
    Node(int n) : val(n) {}
};

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {}
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (mp.count(key) != 0) {
            auto oldNode = mp[key];
            auto newNode = next(oldNode, 1);
            if (newNode == lst.end() || oldNode->val + 1 < newNode->val) {
                newNode = lst.insert(newNode, Node(oldNode->val + 1));
            }
            newNode->keys.insert(key);
            mp[key] = newNode;
    
            oldNode->keys.erase(key);
            if (oldNode->keys.empty()) {
                lst.erase(oldNode);
            }
        } else {
            if (lst.empty() || lst.begin()->val > 1) {
                lst.insert(lst.begin(), Node(1));
            }
            lst.begin()->keys.insert(key);
            mp[key] = lst.begin();
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (mp.count(key) != 0) {
            auto cur = mp[key];
            if (cur->val == 1) {
                mp.erase(key);
            } else {
                auto pre = next(cur, -1);
                if ((cur == lst.begin()) || (pre->val < cur->val - 1)) {
                    pre = lst.insert(cur, Node(cur->val - 1));
                }
                mp[key] = pre;
                pre->keys.insert(key);
            }

            cur->keys.erase(key);
            if (cur->keys.empty()) {
                lst.erase(cur);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (lst.empty()) {
            return "";
        }
        return *(lst.rbegin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (lst.empty()) {
            return "";
        }
        return *(lst.begin()->keys.begin());
    }

private:
    list<Node> lst;
    unordered_map<string, list<Node>::iterator> mp;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

