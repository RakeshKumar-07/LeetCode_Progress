class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(), s.end());
        map<int, vector<char>, greater<int>> m;
        int cnt = 1, maxi = 0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i] != s[i+1]){
                maxi = max(maxi, cnt);
                m[cnt].push_back(s[i]);
                cnt = 1;
            }
            else cnt++;
        }
        maxi = max(maxi, cnt);
        m[cnt].push_back(s[s.size()-1]);
        vector<bool> vis(100000, false);
        for(auto i:m) vis[i.first] = true;
        vector<int> v;
        for(int i=0;i<vis.size();i++) if(!vis[i]) v.push_back(i);

        int k = v.size()-1;
        int ans = 0;
        for(auto i:m){
            for(int j=0;j<i.second.size()-1;j++){
                while(v[k] > i.first) k--;
                if(v[k] == 0) ans += i.first;
                else{
                    ans += abs(v[k] - i.first);
                    k--;
                }
            }
        }
        return ans;
    }
};