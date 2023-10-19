class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        int i = 0;
        if(s[i] != '#') st1.push(s[i++]);
        while(i<s.size()){
            if(s[i] == '#' && st1.size() >= 1) st1.pop();
            else if(s[i] == '#' && st1.size() == 0) ;
            else st1.push(s[i]);
            i++;
        }
        i = 0;
        if(t[i] != '#') st2.push(t[i++]);
        while(i<t.size()){
            if(t[i] == '#' && st2.size() >= 1) st2.pop();
            else if(t[i] == '#' && st2.size() == 0) ;
            else st2.push(t[i]);
            i++;
        }
        return st1 == st2; 
    }
};