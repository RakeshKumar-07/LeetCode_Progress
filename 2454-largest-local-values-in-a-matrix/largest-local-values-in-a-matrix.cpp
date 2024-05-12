class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        for(int i=0;i<grid.size()-2;i++){
            vector<int> temp;
            for(int j=0;j<grid.size()-2;j++){
                int t = 0;
                for(int l=i;l<i+3;l++) for(int k=j;k<j+3;k++) t = max(grid[l][k], t);
                temp.push_back(t);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};