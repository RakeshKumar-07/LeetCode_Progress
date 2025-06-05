class Solution {
public:
    char parent[26];

    char find(char a){
        if(parent[a-'a'] == a) return a;
        return find(parent[a-'a']);
    }

    void _union(char a, char b){
        char pa = find(a), pb = find(b);
        if(pa <= pb) parent[pb-'a'] = pa;
        else parent[pa-'a'] = pb;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i=0;i<26;i++) parent[i] = (char)('a'+i);
        for(int i=0;i<s1.size();i++) _union(s1[i], s2[i]);
        for(int i=0;i<s1.size();i++) _union(s1[i], s2[i]);
        string ans = "";
        for(int i=0;i<baseStr.size();i++) ans += find(baseStr[i]);
        return ans;
    }
};