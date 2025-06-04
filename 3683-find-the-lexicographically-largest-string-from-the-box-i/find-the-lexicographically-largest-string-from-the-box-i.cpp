class Solution {
public:
    string answerString(string word, int numFriends) {
        string ans = "";
        for(int i=0;i<word.size();i++){
            string s = word.substr(i, min(word.size()-i, word.size() - numFriends + 1));
            if(s > ans) ans = s;
        }
        return numFriends == 1 ? word : ans;

    }
};