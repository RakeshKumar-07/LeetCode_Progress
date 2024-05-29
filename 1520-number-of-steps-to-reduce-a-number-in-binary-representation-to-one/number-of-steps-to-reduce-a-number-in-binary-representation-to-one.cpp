class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s.size() > 1){
            if(s[s.size()-1] == '0'){
                s = s.substr(0, s.size()-1);
                ans++;
            }
            else if(s[s.size()-1] == '1'){
                char add = '1';
                for(int i=s.size()-1;i>=0;i--){
                    if(s[i] == '0' && add == '1'){
                        s[i] = '1';
                        add = '0';
                        break;
                    }
                    else if (s[i] == '0' && add == '0'){
                        s[i] = '0';
                        add = '0';
                        break;
                    }
                    else if (s[i] == '1' && add == '1'){
                        s[i] = '0';
                        add = '1';
                    }
                    else if (s[i] == '1' && add == '0'){
                        s[i] = '1';
                        add = '0';
                        break;
                    }
                }
                if(add == '1') s = "1" + s;
                ans++;
            }
        }
        return ans;
    }
};