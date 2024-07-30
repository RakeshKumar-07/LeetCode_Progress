class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> as(s.size()+1, 0), bs(s.size()+1, 0);
        for(int i=1;i<=s.size();i++) bs[i] += ((s[i-1] == 'b') + bs[i-1]);
        for(int i=s.size()-1;i>=0;i--) as[i] += ((s[i] == 'a') + as[i+1]);
        int ans = INT_MAX;
        for(int i=0;i<=s.size();i++) ans = min(ans, as[i] + bs[i]);
        return ans;
    }
};