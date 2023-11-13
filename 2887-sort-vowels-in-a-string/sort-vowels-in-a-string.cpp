class Solution {
public:
    string sortVowels(string s) {
        vector<int> v = {'A', 'E', 'I', 'O', 'U', 'a','e','i','o','u'}, idx;
        string vowels = "";
        for(int i=0;i<s.size();i++){
            for(int j=0;j<10;j++){
                if(s[i] == v[j]){
                    idx.push_back(i);
                    vowels += s[i];
                }
            }
        }
        sort(vowels.begin(), vowels.end());
        for(int i=0;i<idx.size();i++) s[idx[i]] = vowels[i];
        return s;
    }
};