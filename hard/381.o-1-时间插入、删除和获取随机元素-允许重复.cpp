/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */

// @lc code=start
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int isexist = true;
        if (mp.count(val) != 0) {
            isexist = false;
        }
        int idx = nums.size();
        mp[val].insert(idx);
        nums.push_back(val);
        return isexist;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (mp.count(val) == 0) {
            return false;
        }

        if (val == nums.back()) {
            mp[val].erase(nums.size() - 1);
            nums.pop_back();
        } else {
            int idx = *mp[val].begin();
            mp[nums.back()].erase(nums.size() - 1);
            mp[nums.back()].insert(idx);
            mp[val].erase(idx);
            nums[idx] = nums.back();
            nums.pop_back();
        }
        if (mp[val].empty()) {
            mp.erase(val);
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];
    }

private:
    unordered_map<int, unordered_set<int>> mp;
    vector<int> nums;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

