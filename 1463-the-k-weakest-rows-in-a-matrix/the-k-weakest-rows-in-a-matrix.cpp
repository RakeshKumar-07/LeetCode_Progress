class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<mat.size();i++){
            int cnt = 0;
            for(int j=0;j<mat[i].size();j++) if(mat[i][j] == 1) cnt++;
            v.push_back({cnt,i});
        }
        sort(v.begin(), v.end());
        vector<int> ans(k);
        for(int i=0;i<k;i++) ans[i] = v[i].second;
        return ans;
    }
};