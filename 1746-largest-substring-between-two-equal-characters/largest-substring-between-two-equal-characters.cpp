class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,vector<int>> m;
        int ans = -1;
        for(int i=0;i<s.size();i++) m[s[i]].push_back(i);
        for(auto i:m) if(i.second.size() > 1) ans = max(i.second[i.second.size()-1]-i.second[0]-1, ans);
        return ans;
    }
};