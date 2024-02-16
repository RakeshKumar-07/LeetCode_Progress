class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int ans = 0, l = 0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            l++;
            while(m[s[i]] != 1){
                m[s[i-l+1]]--;
                l--;
            }
            ans = max(ans, l);
        }
        return ans;
    }
};