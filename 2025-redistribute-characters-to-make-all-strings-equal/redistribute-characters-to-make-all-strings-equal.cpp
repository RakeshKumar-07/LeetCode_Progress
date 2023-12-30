class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> m(26,0);
        for(int i=0;i<words.size();i++) for(int j=0;j<words[i].size();j++) m[words[i][j] - 'a']++;
        for(int i=0;i<26;i++) if(m[i]%words.size() != 0) return false;
        return true;
    }
};