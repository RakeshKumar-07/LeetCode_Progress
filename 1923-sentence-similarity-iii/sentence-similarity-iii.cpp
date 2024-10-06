class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1, s2;
        stringstream ss1(sentence1), ss2(sentence2);
        string word;

        while (ss1 >> word)
            s1.push_back(word);
        while (ss2 >> word)
            s2.push_back(word);

        if (s1.size() > s2.size()) {
            int fi = 0, si = 0, flag = 0;
            while (fi < s2.size() && si < s1.size() && flag < 2) {
                if (s2[fi] == s1[si]) {
                    fi++;
                    si++;
                } else {
                    flag++;
                    int mf = 0;
                    for (int i = si + 1; i < s1.size(); i++) {
                        if (s2[fi] == s1[i]) {
                            mf = i;
                        }
                    }
                    si = mf + 1;
                    fi++;
                }
            }
            if (si < s1.size())
                flag++;
            if (fi < s2.size())
                flag++;

            return flag <= 1;
        } else if (s1.size() < s2.size()) {
            int fi = 0, si = 0, flag = 0;
            while (fi < s1.size() && si < s2.size() && flag < 2) {
                if (s1[fi] == s2[si]) {
                    fi++;
                    si++;
                } else {
                    flag++;
                    int mf = 0;
                    for (int i = si + 1; i < s2.size(); i++) {
                        if (s1[fi] == s2[i]) {
                            mf = i;
                        }
                    }
                    si = mf + 1;
                    fi++;
                }
            }
            if (si < s2.size())
                flag++;
            if (fi < s1.size())
                flag++;

            return flag <= 1;
        } else {
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] != s2[i])
                    return false;
            }
            return true;
        }
    }
};