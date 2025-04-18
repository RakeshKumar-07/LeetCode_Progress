class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1;i<n;i++){
            char curr = ans[0];
            string s = "";
            int cnt = 0;
            for(int j=0;j<ans.size();j++){
                if(curr == ans[j]) cnt++;
                else{
                    s += to_string(cnt) + curr;
                    cnt = 1;
                    curr = ans[j];
                }
            }
            s += to_string(cnt) + curr;
            ans = s;
        }
        return ans;
    }
};