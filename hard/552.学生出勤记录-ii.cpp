/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] 学生出勤记录 II
 */

// @lc code=start
constexpr uint64_t MOD_NUM = 1000000007;

class Solution {
public:
    int checkRecord(int n) {
        vector<uint64_t> dp(n < 5 ? 5 : n + 1, 0);

        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;
        dp[3] = 7;

        for (int idx = 4; idx <= n; ++idx) {
            dp[idx] = ((2 * dp[idx - 1]) % MOD_NUM + MOD_NUM - dp[idx - 4]) % MOD_NUM;
        }

        uint64_t ans = dp[n];

        for (int idx = 1; idx <= n; ++idx) {
            ans += (dp[idx - 1] * dp[n - idx]) % MOD_NUM;
        }

        return ans % MOD_NUM;
    }
};
// @lc code=end


// public class Solution {
//     int M=1000000007;
//     public int checkRecord(int n) {
//         int[] f =new int[n+1];
//         f[0]=1;
//         for(int i=1;i<=n;i++)
//             f[i]=func(i);
//         int sum=func(n);
//         for(int i=1;i<=n;i++){
//             sum+=(f[i-1]*f[n-i])%M;
//         }
//         return sum%M;
//     }
//    public int func(int n)
//    {    
//        if(n==0)
//             return 1;
//         if(n==1)
//             return 2;
//         if(n==2)
//             return 4;
//         if(n==3)
//             return 7;
//         return (2*func(n-1) - func(n-4))%M;
//    }
// }
