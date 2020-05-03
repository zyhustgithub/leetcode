/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        left = mt.end();
        right = mt.end();
    }
    
    void addNum(int num) {
        int mtSize = mt.size();
        mt.insert(num);
        if (mtSize == 0) {
            left = mt.begin();
            right = mt.begin();
        } else {
            if (mtSize & 1) {
                if (num >= *left) {
                    ++right;
                } else {
                    --left;
                }
            } else {
                if (num < *right) {
                    left = --right;
                } else {
                    ++left;
                }
            }
        }
    }
    
    double findMedian() {
        return (double)(*left + *right) / 2;
    }

private:
    multiset<int> mt;
    multiset<int>::iterator left;
    multiset<int>::iterator right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

