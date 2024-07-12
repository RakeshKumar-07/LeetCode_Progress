class Solution {
public:
    int maximumGain(string s, int x, int y) {
        vector<string> vec;
        string str = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'b') str += s[i];
            else{
                if(str.size() != 0) vec.push_back(str);
                str = "";
            }
        }
        if(str.size() != 0) vec.push_back(str);
        int ans = 0;
        if(x > y){
            for(int i=0;i<vec.size();i++){
                stack<char> st, st1;
                for(int j=0;j<vec[i].size();j++){
                    if(st.size() == 0) st.push(vec[i][j]);
                    else if(st.top() == 'a' && vec[i][j] == 'b'){
                        st.pop();
                        ans += x;
                    }
                    else st.push(vec[i][j]);
                }
                while(st.size() > 0){
                    if(st1.size() == 0) st1.push(st.top());
                    else if(st1.top() == 'a' && st.top() == 'b'){
                        st1.pop();
                        ans += y;
                    }
                    else st1.push(st.top());
                    st.pop();
                }
            }
        }
        else{
            for(int i=0;i<vec.size();i++){
                stack<char> st, st1;
                for(int j=0;j<vec[i].size();j++){
                    if(st.size() == 0) st.push(vec[i][j]);
                    else if(st.top() == 'b' && vec[i][j] == 'a'){
                        st.pop();
                        ans += y;
                    }
                    else st.push(vec[i][j]);
                }
                while(st.size() > 0){
                    if(st1.size() == 0) st1.push(st.top());
                    else if(st1.top() == 'b' && st.top() == 'a'){
                        st1.pop();
                        ans += x;
                    }
                    else st1.push(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};