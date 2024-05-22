class Solution {
public:
    bool check(int i, int j, string &s){
        for(int m=0;m<=(j-i);m++)
            if(s[m+i] != s[j-m]) return false;
        return true;
    }

    void solve(int i, int n, string &s, vector<string> &t, vector<vector<string>> &ans){
        if(i == n){
            ans.push_back(t);
            return;
        }
        for(int j=i;j<n;j++){
            if(check(i,j,s)){
                t.push_back(s.substr(i,j-i+1));
                solve(j+1, n, s, t, ans);
                t.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> t;
        vector<vector<string>> ans;
        solve(0, n, s, t, ans);
        return ans;
    }
};