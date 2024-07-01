class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> vec = mat;
        k %= mat[0].size();
        for(int i=0;i<mat.size();i++){
            vector<int> v(mat[i].size());
            if(!(i&1)){
                // cout<<"\nEVEN:- ";
                for(int j=0;j<mat[i].size();j++){
                    v[(mat[i].size() + (j-k))%mat[i].size()] = mat[i][j];
                }
                // for(int j=0;j<v.size();j++) cout<<v[j]<<" -> ";
                for(int j=0;j<v.size();j++) mat[i][j] = v[j];
            }
            else{
                // cout<<"\nODD:- ";
                for(int j=0;j<mat[i].size();j++){
                    v[(j+k)%mat[i].size()] = mat[i][j];
                }
                // for(int j=0;j<v.size();j++) cout<<v[j]<<" -> ";
                for(int j=0;j<v.size();j++) mat[i][j] = v[j];
            }
        }
        return mat == vec;
    }
};