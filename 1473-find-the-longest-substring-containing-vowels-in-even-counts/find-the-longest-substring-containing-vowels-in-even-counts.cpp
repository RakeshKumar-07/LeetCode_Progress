class Solution {
public:
    int findTheLongestSubstring(string s) {
        int evenCnt = (1 << 5) - 1;
        map<char, int> m;
        m['a'] = 4;
        m['e'] = 3;
        m['i'] = 2;
        m['o'] = 1;
        m['u'] = 0;
        map<int, vector<int>> even;
        even[31].push_back(-1);
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') evenCnt = evenCnt ^ (1 << m[s[i]]);
            even[evenCnt].push_back(i);
        }
        int ans = 0;
        for(auto i:even) ans = max(ans, (i.second[i.second.size()-1] - i.second[0]));
        return ans;
    }
};