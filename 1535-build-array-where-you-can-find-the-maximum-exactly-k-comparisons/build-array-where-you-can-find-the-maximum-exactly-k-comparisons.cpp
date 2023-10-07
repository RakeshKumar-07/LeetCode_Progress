class Solution {
public:
    int M = 1000000007;
    long long dp[51][101][51];

    long long solve(int n, int k, int m, int maxi){
        if(n==0){
            if(k==0) return 1;
            else return 0;
        }
        if(dp[n][maxi][k] != -1) return dp[n][maxi][k];
        long long t = 0;
        for(int i=1;i<=m;i++){
            if( k > 0 ){
                if(maxi < i) t += solve(n-1, k-1, m, i)%M;
                else t += solve(n-1, k, m, maxi)%M;
            }
            else if(maxi >= i) t += solve(n-1, k, m, maxi)%M; 
            t %= M;
        }
        return dp[n][maxi][k] = t%M;
    }

    int numOfArrays(int n, int m, int k) {
        if(m<k) return 0;
        memset(dp,-1,sizeof(dp));
        long long ans = solve(n,k,m,0);
        return ans;
    }
};