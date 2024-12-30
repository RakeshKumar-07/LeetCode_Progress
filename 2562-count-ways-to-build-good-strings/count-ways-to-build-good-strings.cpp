class Solution {
public:
    long long M =  1000000007;
    long long dp[100001];
    long long solve(int low, int high, int zero, int one, long long sum){
        if(sum > high) return 0;
        if(dp[sum] != -1) return dp[sum]%M;
        long long t1 = 0, t2 = 0;
        t1 = solve(low,high,zero,one,sum+zero);
        t2 = solve(low,high,zero,one,sum+one);
        if(sum>=low && sum<=high) return dp[sum] = (1+t1%M+t2%M)%M;
        return dp[sum] = (t1%M+t2%M)%M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof(dp));
        return solve(low,high,zero,one,0);
    }
};