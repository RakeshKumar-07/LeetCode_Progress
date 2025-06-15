class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int maxi, mini;
        vector<bool> v(s.size(), false);
        char c = s[0];
        if(c == '9'){
            for(int i=0;i<v.size();i++){
                if(s[i] != c){
                    c = s[i];
                    break;
                }
            } 
            for(int i=0;i<v.size();i++){
                if(s[i] == c){
                    s[i] = '9';
                    v[i] = true;
                }
            }
            // cout<<c<<" hi"<<endl;
        }
        else{
            for(int i=0;i<v.size();i++){
                if(s[i] == c){
                    s[i] = '9';
                    v[i] = true;
                }
            }
        }
        maxi = stoi(s);
        for(int i=0;i<v.size();i++) if(v[i]) s[i] = c;
        c = s[0];
        if(c == '1'){
            for(int i=0;i<s.size();i++){
                if(s[i] != '1' && s[i] != '0'){
                    c = s[i];
                    break;
                }
            }
            if(c != '1') for(int i=0;i<s.size();i++) if(s[i] == c) s[i] = '0';
            cout<<c<<" hi"<<endl;
        }
        else for(int i=0;i<v.size();i++) if(s[i] == c) s[i] = '1';
        mini = stoi(s);
        cout<<maxi<<" -> "<<mini<<endl;
        return maxi - mini;
    }
};