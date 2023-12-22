class Solution {
public:
    int maxScore(string s) {
        vector<int> l(s.size(), 0), r(s.size(), 0);
        int cnt = 0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == '0') cnt++;
            l[i] = cnt;
        }
        cnt = 0;
        for(int i=s.size()-1; i>0;i--){
            if(s[i] == '1') cnt++;
            r[i-1] = cnt;
        }
        int ans = INT_MIN;
        for(int i=0;i<s.size();i++) ans = max(ans, l[i]+r[i]);
        return ans;
    }
};