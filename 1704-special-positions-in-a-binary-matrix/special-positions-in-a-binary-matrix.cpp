class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1){
                    int t = 0;
                    for(int k=0;k<mat.size();k++) t += mat[k][j];
                    for(int k=0;k<mat[i].size();k++) t += mat[i][k];
                    if(t == 2) ans++;
                }
            }
        }
        return ans;
    }
};