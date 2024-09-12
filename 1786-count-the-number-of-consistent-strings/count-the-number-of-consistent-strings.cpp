class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> vis(26, false);
        for(int i=0;i<allowed.size();i++) vis[allowed[i] - 'a'] = true;
        int ans = 0;
        for(int i=0;i<words.size();i++){
            bool t = true;
            for(int j=0;j<words[i].size();j++) if(!vis[words[i][j] - 'a']) t &= false;
            if(t) ans++;
        }
        return ans;
    }
};