class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int r[101];
        memset(r, 0, sizeof(r));
        bool common[101][101];
        memset(common, false, sizeof(common));
        for(int i=0;i<roads.size();i++){
            r[roads[i][0]]++;
            r[roads[i][1]]++;
            common[roads[i][0]][roads[i][1]] = true;
            common[roads[i][1]][roads[i][0]] = true;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(common[i][j]){
                    ans = max(ans, r[i]+r[j]-1);
                }
                else{
                    ans = max(ans, r[i]+r[j]);
                }
            }
        }
        return ans;
    }
};