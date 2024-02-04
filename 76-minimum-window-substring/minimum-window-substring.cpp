class Solution {
public:
    string minWindow(string s, string t) {
        int cnt = 0, minL = INT_MAX, start = 0, idx = -1, l = 0;
        unordered_map<char, int> hasht, hashs;
        for(int i=0;i<t.size();i++) hasht[t[i]]++;
        
        for(int i=0;i<s.size();i++){
            hashs[s[i]]++;
            if(hashs[s[i]] <= hasht[s[i]]) cnt++;
            if(cnt == t.size()){
                while(hashs[s[start]] > hasht[s[start]]){
                    hashs[s[start]]--;
                    start++;
                }
                l = i - start + 1;
                if(minL > l){
                    minL = l;
                    idx = start;
                }
            }
            l++;
        }
        return idx != -1 ? s.substr(idx,minL) : "";
    }
};