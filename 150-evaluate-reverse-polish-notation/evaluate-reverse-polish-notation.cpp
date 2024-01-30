class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        int i = 0, n = tokens.size();
        while(i<n){
            if(tokens[i][0] >= 42 && tokens[i][0] <= 47 && tokens[i].length() == 1){
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                if(tokens[i][0] == 42)
                    s.push(b*a);
                else if(tokens[i][0] == 43)
                    s.push(b+a);
                else if(tokens[i][0] == 45)
                    s.push(b-a);
                else
                    s.push(b/a);
            }
            else{
                int t = 0;
                if(tokens[i][0] != 45){
                    for(int j=tokens[i].length()-1;j>=0;j--){
                        t += (tokens[i][j] - '0')*pow(10, tokens[i].length() - 1 - j);
                    }
                }
                else{
                    for(int j=tokens[i].length()-1;j>0;j--){
                        t += (tokens[i][j] - '0')*pow(10, tokens[i].length() - 1 - j);
                    }
                    t *= (-1);
                }
                s.push(t);
            }
            i++;    
        }
        return s.top();
    }
};