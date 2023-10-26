class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int M = 1000000007;
        map<long long, long long> dp;
        sort(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++){
            dp[arr[i]] = 1;
        } 
        for(int i=0;i<arr.size();i++){
            for(int j=i-1;j>=0;j--){
                if(arr[i]%arr[j] == 0){
                    int r = arr[i]/arr[j];
                    if(dp[r] >= 1){
                        dp[arr[i]] += (dp[arr[j]]*dp[r])%M;
                        dp[arr[i]]%=M;
                    }
                }
            }
        }
        int ans = 0;
        for(auto i:dp){
            ans += i.second;
            ans%=M;
        }
        return ans;
    }
};