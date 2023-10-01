class Solution {
public:
    string reverse(string inter){
        string a = "";
        for(int i = inter.length()-1;i>-1;i--){
            a += inter[i];
        }
        return a;
    }
    
    string reverseWords(string s) {
        string ans = "";
        string inter = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                ans += reverse(inter) + " ";
                inter = "";
            }
            else  inter += s[i];
        }
        ans += reverse(inter);
        return ans;
    }
};