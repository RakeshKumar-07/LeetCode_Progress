class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> v(rowSum.size(), vector<int>(colSum.size(), 0));
        vector<int> rowCurSum(rowSum.size(), 0), colCurSum(colSum.size(), 0);
        for(int i=0;i<colSum.size();i++){
            if(i<colSum.size() && i<rowSum.size()){
                v[i][i] = min(rowSum[i], colSum[i]);
                rowCurSum[i] = v[i][i];
                colCurSum[i] = v[i][i];
            }
        }
        for(int i=0;i<rowSum.size();i++){
            for(int j=0;j<colSum.size();j++){
                if(i != j && rowCurSum[i] < rowSum[i] && colCurSum[j] < colSum[j]){
                    int minDiff = min(rowSum[i] - rowCurSum[i], colSum[j] - colCurSum[j]);
                    v[i][j] = minDiff;
                    rowCurSum[i] += minDiff;
                    colCurSum[j] += minDiff;
                }
            }
        }
        return v;
    }
};