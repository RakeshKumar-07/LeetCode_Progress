class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // cout<<matrix.size()<<" "<<matrix[0].size();
        int sum = 0;
        vector<vector<int>> updated(matrix.size(), vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == '0'){
                    updated[i][j] = 0;
                    sum = 0;
                }
                else updated[i][j] = ++sum;
            }
            sum = 0;
        }
        int ans = 0;
        for(int i=0;i<updated[0].size();i++){
            for(int j=0;j<updated.size();j++){
                int t = INT_MAX;
                for(int k=j;k<updated.size();k++){
                    t = min(t, updated[k][i]);
                    ans = max(ans, t*(k-j+1));
                }
            }
        }
        return ans;
    }
};