class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        vector<int> f1(26,0), f2(26,0);
        if(word1.length() != word2.length()){
            return false;
        }
        for(int i=0;i<n;i++){
            f1[word1[i] - 'a']++;
            f2[word2[i] - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(f1[i] == 0 && f1[i] != f2[i]){
                return false;
            }
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        for(int i=0;i<26;i++){
            if(f1[i] != f2[i]){
                return false;
            }
        }
        return true;
    }
};