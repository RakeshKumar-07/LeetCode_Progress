class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int cnt = 0;
        char curr = word[0];
        for(int i=0;i<word.size();i++){
            if(curr == word[i] && cnt < 9) cnt++;
            else if(cnt == 9 || curr != word[i]){
                ans += (to_string(cnt) + curr);
                cnt = 1;
                curr = word[i];
            }
        }
        ans += (to_string(cnt) + curr);
        return ans;
    }
};