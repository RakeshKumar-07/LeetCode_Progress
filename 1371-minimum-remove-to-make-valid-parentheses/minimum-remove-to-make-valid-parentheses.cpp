class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> v;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(st.size() > 0 && s[i] == ')' && s[st.top()] == '(') st.pop();
            else if(s[i] == '(' || s[i] == ')') st.push(i);
        }
        string t = "";
        for(int i=s.size()-1;i>=0;i--){
            if(st.size() > 0 && st.top() == i) st.pop();
            else t += s[i];
        }
        reverse(t.begin(), t.end());
        return t;
    }
};