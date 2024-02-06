class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>> t;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            t.push_back({s,i});
        }
        sort(t.begin(), t.end());
        vector<vector<string>> ans;
        for(int i=0;i<t.size();){
            string s = t[i].first;
            vector<string> p;
            while(i<t.size() && t[i].first == s) p.push_back(strs[t[i++].second]);
            ans.push_back(p);
        }
        return ans;
    }
};