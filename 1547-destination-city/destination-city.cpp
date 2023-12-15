class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> m;
        for(int i=0;i<paths.size();i++) m[paths[i][0]] = paths[i][1];
        string ans = paths[0][0];
        while(m.find(ans) != m.end()) ans = m[ans];
        return ans;
    }
};