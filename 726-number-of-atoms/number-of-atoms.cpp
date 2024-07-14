class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string, int>> st1, st2;
        for(int i=0;i<formula.size();){
            string s = "", cnt = "";
            bool popped = false;
            s += formula[i++];
            while(formula[i] > 96) s += formula[i++];
            while(formula[i] > 47 && formula[i] < 58) cnt += formula[i++];
            while(s == ")" && st1.top().first != "("){
                pair<string, int> t = st1.top();
                st1.pop();
                st2.push({t.first, t.second * (cnt != "" ? stoi(cnt) : 1)});
                popped = true;
            }
            if(popped){
                popped = true;
                st1.pop();
                while(st2.size() > 0){
                    st1.push(st2.top());
                    st2.pop();
                }
            }
            else st1.push({s, cnt != "" ? stoi(cnt) : 1});
        }
        map<string, int> m;
        while(st1.size() > 0){
            pair<string, int> t = st1.top();
            st1.pop();
            m[t.first] += t.second;
        }
        string ans = "";
        for(auto i:m) ans += i.first + (i.second > 1 ? to_string(i.second) : "");
        return ans;
    }
};