class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int> col, row;
        for(int i=0;i<matrix.size();i++) for(int j=0;j<matrix[i].size();j++) if(matrix[i][j] == 0) col[j]++, row[i]++;
        for(auto i:col) for(int j=0;j<matrix.size();j++) matrix[j][i.first] = 0;
        for(auto i:row) for(int j=0;j<matrix[0].size();j++) matrix[i.first][j] = 0;
    }
};