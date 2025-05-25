class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> m;
        for(int i=0;i<words.size();i++) m[words[i]]++;
        int ans = 0;
        for(auto i:m){
            string s = i.first;
            reverse(s.begin(), s.end());
            if(s != i.first) ans += 2*min(i.second, m[s]);
            else if(s == i.first){
                if(m[s]%2 == 0){
                    ans += 2*i.second;
                    m[s] = 0;
                } 
                else{
                    ans += 2*(i.second-1);
                    m[s] = 1;
                }
            }
        }
        for(auto i:m){
            string s = i.first;
            reverse(s.begin(), s.end());
            if(s == i.first && m[s] == 1){
                ans += 2;
                break;
            }
        }
        return ans;
    }
};