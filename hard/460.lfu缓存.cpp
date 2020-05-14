/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU缓存
 */

// @lc code=start
struct Node {
    int key;
    int value;
    int refs;

    Node(int _key, int _value, int _refs) : key(_key), value(_value), refs(_refs) {}
};

class LFUCache {
public:
    LFUCache(int capacity) : capacity(capacity), minRefs(0) {
        keyMp.clear();
        refMp.clear();
    }
    
    int get(int key) {
        if (keyMp.count(key) == 0) {
            return -1;
        }
        auto oldNode = keyMp[key];
        int oldRefs = oldNode->refs;
        int oldValue = oldNode->value;
        refMp[oldRefs].erase(oldNode);
        keyMp[key] = refMp[oldRefs + 1].insert(refMp[oldRefs + 1].begin(),
            Node(key, oldValue, oldRefs + 1));
        if (refMp[oldRefs].empty()) {
            refMp.erase(oldRefs);
            if (minRefs == oldRefs) {
                ++minRefs;
            }
        }

        return oldValue;
    }
    
    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (keyMp.count(key) != 0) {
            auto oldNode = keyMp[key];
            int oldRefs = oldNode->refs;
            keyMp[key] = refMp[oldRefs + 1].insert(refMp[oldRefs + 1].begin(),
                Node(key, value, oldRefs + 1));
            refMp[oldRefs].erase(oldNode);
            if (refMp[oldRefs].empty()) {
                refMp.erase(oldRefs);
                if (minRefs == oldRefs) {
                    ++minRefs;
                }
            }
        } else {
            keyMp[key] = refMp[1].insert(refMp[1].begin(), Node(key, value, 1));
            if (keyMp.size() > capacity) {
                keyMp.erase(refMp[minRefs].back().key);
                refMp[minRefs].pop_back();
                if (refMp[minRefs].empty()) {
                    refMp.erase(minRefs);
                }
            }
            minRefs = 1;
        }
    }

private:
    int capacity;
    int minRefs;
    unordered_map<int, list<Node>::iterator> keyMp;
    unordered_map<int, list<Node>> refMp;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

