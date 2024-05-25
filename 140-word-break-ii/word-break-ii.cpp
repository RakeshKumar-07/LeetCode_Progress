class Solution {
public:
    vector<string> ans;

    void solve(int i, int n, vector<string>& wordDict, string s, string currString, vector<int>& vis){
        if(i == n){
            if(s <= currString){
                string temp = "";
                for(int j=0;j<vis.size()-1;j++) temp += (wordDict[vis[j]] + " ");
                temp += wordDict[vis[vis.size()-1]];
                ans.push_back(temp);
            }
            return;
        }
        for(int j=0;j<wordDict.size();j++){
            if(n - i >= wordDict[j].size() && s.substr(i, wordDict[j].size()) == wordDict[j]){
                vis.push_back(j);
                solve(i+wordDict[j].size(), n, wordDict, s, currString + wordDict[j], vis);
                vis.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string currWord = "";
        vector<int> vis;
        solve(0, s.size(), wordDict, s, currWord, vis);
        return ans;
    }
};