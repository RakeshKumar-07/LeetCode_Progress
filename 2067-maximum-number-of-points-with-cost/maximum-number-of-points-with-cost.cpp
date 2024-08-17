class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        int m=points[0].size();

        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));

        for(int i=0;i<m;i++){
            dp[0][i]=points[0][i];
        }

        for(int i=1;i<n;i++){

            vector<long long>left(m),right(m);
            
            left[0]=dp[i-1][0];

            for(int j=1;j<m;j++){
             left[j]=max(left[j-1]-1,dp[i-1][j]);
            }

            right[m-1]=dp[i-1][m-1];

            for(int j=m-2;j>=0;j--){
             right[j]=max(right[j+1]-1,dp[i-1][j]);
            }

            for(int j=0;j<m;j++){
                dp[i][j]=points[i][j]+max(left[j],right[j]);
            }
            
        }

        long long ans=INT_MIN;

        for(int i=0;i<m;i++){
            ans=max(ans,dp[n-1][i]);
        }

        return ans;
    }
};