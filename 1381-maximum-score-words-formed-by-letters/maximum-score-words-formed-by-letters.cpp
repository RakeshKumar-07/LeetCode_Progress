class Solution {
public:
    int ans = 0;

    void solve(int i, int n, int currScore, vector<string>& words, unordered_map<int, int> &m, vector<int>& score){
        if(i == n){
            ans = max(currScore, ans);
            return;
        }
        solve(i+1, n, currScore, words, m, score);
        bool y = true;
        vector<int> t(26, 0);
        for(int j=0;j<words[i].size();j++){
            t[words[i][j] - 'a']++;
            if(t[words[i][j] - 'a'] > m[words[i][j] - 'a']) y &= false;
        }
        if(y){
            int s = 0;
            for(int j=0;j<t.size();j++){
                if(t[j] != 0) {
                    m[j] -= t[j];
                    s += t[j]*score[j];
                }
            }
            solve(i+1, n, currScore + s, words, m, score);
            for(int j=0;j<t.size();j++) m[j] += t[j];
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<int, int> m;
        for(int i=0;i<letters.size();i++) m[letters[i] - 'a']++;
        solve(0, words.size(), 0, words, m, score);
        return ans;
    }
};