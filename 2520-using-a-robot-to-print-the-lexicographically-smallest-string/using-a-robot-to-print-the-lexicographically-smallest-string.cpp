class Solution {
public:
    string robotWithString(string s) {
        vector<int> cnt(26, 0);
        vector<char> v;
        string ans = "";
        for(int i=0;i<s.size();i++) cnt[s[i]-'a']++;
        int j = 0;
        while(j < 26 && cnt[j] == 0) j++;
        for(int i=0;i<s.size();i++){
            v.push_back(s[i]);
            while(v.size() > 0 && j < 26 && v[v.size()-1] == (char)(j + 97)){
                ans += v[v.size()-1];
                v.pop_back();
                cnt[j]--;
                if(v.size() > 0) cnt[v[v.size()-1]-'a']++;
                for(int k=0;k<26;k++){
                    if(cnt[k] > 0){
                        j = k;
                        break;
                    }
                }
            }
            if(v.size() > 0) cnt[v[v.size()-1]-'a']--;
        }
        for(int i=v.size()-1;i>=0;i--) ans += v[i];
        return ans;
    }
};