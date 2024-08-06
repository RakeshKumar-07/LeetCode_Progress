class Solution {
public:
    vector<int> computeLPS(string &pattern){
        vector<int> lps(pattern.size(), 0);
        int j = 0;
        for(int i=1;i<pattern.size();i++){
            if(pattern[i] == pattern[j]) lps[i]  = ++j;
            else{
                while (j != 0 && pattern[i] != pattern[j]) j = lps[j - 1];
                if (pattern[i] == pattern[j]) lps[i] = ++j;
                else if (j == 0) lps[i] = 0;
            }
        }
        return lps;
    }

    vector<int> stringMatching(string &text, string &pattern, vector<int> &lps){
        vector<int> result;
        int i = 0, j = 0;

        while((text.size() - i) >= (pattern.size() - j)){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }

            if(j == pattern.size()){
                result.push_back(i-j);
                j = lps[j-1];
            }
            else if(i < text.size() && text[i] != pattern[j]){
                if(j != 0) j = lps[j-1];
                else i++;
            }
        }
        return result;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        if(s.size() < a.size() || s.size() < b.size()) return {};
        
        vector<int> lps1 = computeLPS(a), lps2 = computeLPS(b);

        vector<int> idx1 = stringMatching(s, a, lps1), idx2 = stringMatching(s, b, lps2), ans;
        
        for(int i=0;i<idx1.size();i++){
            for(int j=0;j<idx2.size();j++){
                if(abs(idx2[j] - idx1[i]) <= k){
                    ans.push_back(idx1[i]);
                    break;
                }
            }
        }
        return ans;
    }
};