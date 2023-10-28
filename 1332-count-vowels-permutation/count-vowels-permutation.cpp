class Solution {
public:
    int dp[20001][27];
    int M = 1000000007;

    int solve(int i, int n, char lastChar){
        if(i==n){
            return 1;
        }
        if(dp[i][lastChar - '`'] != -1) return dp[i][lastChar - '`'];
        long long t = 0;
        if(lastChar == '`'){
            t += solve(i+1, n, 'a');
            t %= M;
            t += solve(i+1, n, 'e');
            t %= M;
            t += solve(i+1, n, 'i');
            t %= M;
            t += solve(i+1, n, 'o');
            t %= M;
            t += solve(i+1, n, 'u');
            t %= M;
        }
        if(lastChar == 'a'){
            t += solve(i+1, n, 'e');
            t %= M;
        }if(lastChar == 'e'){
            t += solve(i+1, n, 'a');
            t %= M;
            t += solve(i+1, n, 'i');
            t %= M;
        }if(lastChar == 'i'){
            t += solve(i+1, n, 'a');
            t %= M;
            t += solve(i+1, n, 'e');
            t %= M;
            t += solve(i+1, n, 'o');
            t %= M;
            t += solve(i+1, n, 'u');
            t %= M;
        }if(lastChar == 'o'){
            t += solve(i+1, n, 'i');
            t %= M;
            t += solve(i+1, n, 'u');
            t %= M;
        }if(lastChar == 'u'){
            t += solve(i+1, n, 'a');
            t %= M;
        }
        return dp[i][lastChar - '`'] = t;
    }

    int countVowelPermutation(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0,n,'`');
        return ans;
    }
};