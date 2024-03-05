class Solution {
public:
    int minimumLength(string s) {
        vector<pair<char, int>> v;
        int cnt = 0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == s[i+1]) cnt++;
            else{
                v.push_back({s[i], cnt+1});
                cnt = 0;
            }
        }
        v.push_back({s[s.size()-1], cnt+1});
        int p = 0, q = v.size()-1, ans = 0;
        while(p<q){
            if(v[p].first == v[q].first){
                v[p].second = 0;
                v[q].second = 0;
                p++;
                q--;
            }
            else break;
        }
        if(p == q) return v[p].second > 1 ? 0:1;
        for(int i=0;i<v.size();i++) ans += v[i].second;
        return ans;
    }
};