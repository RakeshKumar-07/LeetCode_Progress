class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = -1;
        for(int i=0;i<word.size();i++){
            if(ch == word[i]){
                idx = i;
                break;
            }
        }
        if(idx != -1){
            string t = word.substr(0, idx+1);
            reverse(t.begin(), t.end());
            t += word.substr(idx+1, word.size()-1-idx);
            return t;
        }
        return word;
    }
};