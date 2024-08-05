class Solution {
public:
    
    vector<int> computeLPS(string &pattern)
    {
        vector<int> lps(pattern.length(), 0);
        int j = 0;
        for (int i = 1; i < pattern.length(); i++)
        {
            if (pattern[i] == pattern[j])
                lps[i] = ++j;
            else
            {
                while (j != 0 && pattern[i] != pattern[j])
                    j = lps[j - 1];
                if (pattern[i] == pattern[j])
                    lps[i] = ++j;
                else if (j == 0)
                    lps[i] = 0;
            }
        }
        return lps;
    }

    bool stringMatching(string &text, string &pattern, vector<int> &lps)
    {

        int i = 0, j = 0;

        while ((text.length() - i) >= (pattern.length() - j))
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
            }

            if (j == pattern.length()) return true;
            else if (i < text.length() && text[i] != pattern[j])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {

        string t = "";
        
        while(t.size() < b.size()) t += a;
        int ans = t.size()/a.size();

        vector<int> lps = computeLPS(b);

        if(stringMatching(t, b, lps)) return t.size()/a.size();
        t += a;
        if(stringMatching(t, b, lps)) return t.size()/a.size();

        return -1;
    }
};