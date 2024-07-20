class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> v(rowSum.size(), vector<int>(colSum.size(), 0));
        for(int i=0;i<rowSum.size();i++){
            for(int j=0;j<colSum.size();j++){
                int minDiff = min(rowSum[i], colSum[j]);
                v[i][j] = minDiff;
                rowSum[i] -= minDiff;
                colSum[j] -= minDiff;
            }
        }
        return v;
    }
};