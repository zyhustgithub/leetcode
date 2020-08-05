/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>

#define INT_MIN_NUM -0x3f3f3f
#define INT_MAX_NUM 0x3f3f3f

int max(int a, int b)
{
    return a >= b ? a : b;
}

int min(int a, int b)
{
    return a <= b ? a : b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    if (nums1Size == 0) {
        return (nums2Size % 2 != 0) ? nums2[(nums2Size - 1) / 2] :
            (nums2[(nums2Size - 1) / 2] + nums2[(nums2Size - 1) / 2 + 1]) / 2.0;
    }

    int lMax1, lMax2;
    int rMin1, rMin2;

    int medianIdx = (nums1Size + nums2Size + 1) / 2;
    int left = 0;
    int right = nums1Size - 1;
    int mid = (left + right) / 2;

    while (left <= right) {
        lMax1 = nums1[mid];
        rMin1 = (mid + 1 >= nums1Size) ? INT_MAX_NUM : nums1[mid + 1];
        lMax2 = (medianIdx - mid - 2 < 0) ? INT_MIN_NUM : nums2[medianIdx - mid - 2];
        rMin2 = nums2[medianIdx - mid - 1];
        if (lMax1 > rMin2) {
            right = mid - 1;
        } else if (lMax2 > rMin1) {
            left = mid + 1;
        } else {
            break;
        }

        if (right < 0) {
            lMax1 = INT_MIN_NUM;
            rMin1 = nums1[0];
            lMax2 = nums2[medianIdx - 1];
            rMin2 = (medianIdx < nums2Size) ? nums2[medianIdx] : INT_MAX_NUM;
            break;
        }

        mid = (left + right) / 2;
    }

    if ((nums1Size + nums2Size) % 2 != 0) {
        return max(lMax1, lMax2);
    } else {
        return (max(lMax1, lMax2) + min(rMin1, rMin2)) / 2.0;
    }
}


// @lc code=end

