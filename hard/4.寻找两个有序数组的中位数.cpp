/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        if (nums1Size > nums2Size) {
            return findMedianSortedArrays(nums2, nums1);
        }

        if (nums1Size == 0) {
            if (nums2Size % 2 == 0) {
                return (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0;
            } else {
                return nums2[nums2Size / 2];
            }
        }

        int pre = 0;
        int post = nums1Size - 1;
        int mid = (pre + post) / 2;
        int breakPos = (nums1Size + nums2Size - 1) / 2;
        int lmax1 = 0, lmax2 = 0;
        int rmin1 = 0, rmin2 = 0;
        while (pre <= post) {
            lmax1 = nums1[mid];
            rmin1 = (mid == nums1Size - 1) ? INT_MAX : nums1[mid + 1];
            lmax2 = (breakPos - mid - 1 < 0) ? INT_MIN : nums2[breakPos - mid - 1];
            rmin2 = nums2[breakPos - mid];
            if (lmax1 > rmin2) {
                post = mid - 1;
            } else if (lmax2 > rmin1) {
                pre = mid + 1;
            } else {
                break;
            }
            if (post < 0) {
                lmax1 = INT_MIN;
                rmin1 = nums1[0];
                lmax2 = nums2[breakPos];
                rmin2 = (breakPos + 1 >= nums2Size) ? INT_MAX : nums2[breakPos + 1];
                break;
            }
            if (pre >= nums1Size) {
                lmax1 = nums1[nums1Size - 1];
                rmin1 = INT_MAX;
                lmax2 = (breakPos - nums1Size < 0) ? INT_MIN : nums2[breakPos - nums1Size];
                rmin2 = nums2[breakPos - nums1Size + 1];
                break;
            }
            mid = (pre + post) / 2;
        }
        if ((nums1Size + nums2Size) % 2 == 1) {
            return max(lmax1, lmax2);
        } else {
            return (max(lmax1, lmax2) + min(rmin1, rmin2)) / 2.0;
        }
    }
};
// @lc code=end

