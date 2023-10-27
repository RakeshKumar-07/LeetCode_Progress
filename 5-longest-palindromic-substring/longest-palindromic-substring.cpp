class Solution {
public:
    string longestPalindrome(string s) {
        pair<int,int> ans = {1,0};
        for(int i=0;i<s.size();i++){
            int p = i-1, q = i+1;
            int size = 1;
            while(p>=0 && q<s.size() && s[p] == s[q]){
                p--;
                q++;
                size += 2;
            }
            if((ans.second - ans.first + 1) < (size)) ans = {p+1, q-1};
        }
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == s[i+1]){
                int p = i-1, q = i+2;
                int size = 2;
                while(p>=0 && q<s.size() && s[p] == s[q]){
                    p--;
                    q++;
                    size += 2;
                }
                if((ans.second - ans.first + 1) < (size)) ans = {p+1, q-1};
            }
        }
        return s.substr(ans.first, ans.second - ans.first + 1);
    }
};