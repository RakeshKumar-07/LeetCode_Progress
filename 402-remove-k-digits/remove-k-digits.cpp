class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i=0;i<num.size();i++){
            while(s.size() > 0 && s.top() > num[i] && k){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        string t = "";
        while(s.size() > 0){
            t += s.top();
            s.pop();
        }
        reverse(t.begin(), t.end());
        int idx = -1;
        // cout<<t<<" => "<<k<<endl;
        for(int i=0;i<t.size();i++){
            idx++;
            if(t[i] != '0') break;
        }
        t = t.substr(idx, t.size()-idx);
        if(k < t.size()) t = t.substr(0, t.size()-k);
        else t = "";
        return t.size() == 0 ? "0" : t;
    }
};