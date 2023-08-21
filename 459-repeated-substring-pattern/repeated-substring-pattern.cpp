class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        if(s.size() > 1){
            for(int i=1;i<s.size();i++){
                if(s[i] != s[i-1]) break;
                if(s[i] == s[i-1] && i == s.size()-1) return true;
            }
        }
        
        for(int i=2;i<=pow(s.size(),0.5);i++){
            if(s.size()%i == 0){
                string temp = s.substr(0,i);
                string sub = "";
                for(int j=0;j<(s.size()/i);j++){
                    sub += temp;
                }
                // cout<<i<<" "<<temp<<endl;
                if(sub == s) return true;
                temp = s.substr(0,(s.size()/i));
                sub = "";
                for(int j=0;j<i;j++){
                    sub += temp;
                }
                if(sub == s) return true;
            }
        }
        return false;
    }
};