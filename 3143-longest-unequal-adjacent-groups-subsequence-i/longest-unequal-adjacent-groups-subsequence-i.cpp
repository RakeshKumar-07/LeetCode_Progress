class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        bool t = groups[0] == 0 ? false : true;
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(!t && groups[i] == 1){
                ans.push_back(words[i]);
                t = true;
            }
            if(t && groups[i] == 0){
                ans.push_back(words[i]);
                t = false;
            }
        }
        return ans;
    }
};