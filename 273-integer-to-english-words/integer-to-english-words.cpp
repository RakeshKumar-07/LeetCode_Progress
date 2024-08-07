class Solution {
public:
    string numberToWords(int num) {
        string s = to_string(num);
        reverse(s.begin(), s.end());
        int parts = s.size()/3;
        unordered_map<int, string> m, places;
        m[0] = "Zero"; m[1] = "One"; m[2] = "Two"; m[3] = "Three"; m[4] = "Four"; m[5] = "Five";
        m[6] = "Six"; m[7] = "Seven"; m[8] = "Eight"; m[9] = "Nine"; m[10] = "Ten"; m[11] = "Eleven";
        m[12] = "Twelve"; m[13] = "Thirteen"; m[14] = "Fourteen"; m[15] = "Fifteen"; m[16] = "Sixteen";
        m[17] = "Seventeen"; m[18] = "Eighteen"; m[19] = "Nineteen"; m[20] = "Twenty"; m[30] = "Thirty";
        m[40] = "Forty"; m[50] = "Fifty"; m[60] = "Sixty"; m[70] = "Seventy"; m[80] = "Eighty"; m[90] = "Ninety";
        places[0] = "Hundred";
        places[1] = "Thousand";
        places[2] = "Million";
        places[3] = "Billion";

        vector<string> res;

        for(int j=0;j<parts;j++){
            if(j > 0) res.push_back(places[j]);
            int size = res.size();
            for(int i=j*3;i<(j+1)*3;){
                if(i == j*3 + 2 && s[i] -'0' > 0){
                    res.push_back(places[0]);
                    res.push_back(m[(s[i]-'0')]);
                    i += 2;
                }
                else if(i != j*3 + 2 && s[i] -'0' > 0 && s[i+1] - '0' == 0){
                    res.push_back(m[(s[i]-'0')]);
                    i += 2;
                }
                else if(i != j*3 + 2 && s[i] -'0' == 0 && s[i+1] - '0' > 0){
                    res.push_back(m[(s[i+1]-'0')*10]);
                    i += 2;
                }
                else if(i != j*3 + 2 && s[i] -'0' > 0 && s[i+1] - '0' == 1){
                    res.push_back(m[(s[i+1]-'0')*10 + (s[i]-'0')]);
                    i += 2;
                }
                else if(i != j*3 + 2 && s[i] -'0' > 0 && s[i+1] - '0' > 1){
                    res.push_back(m[(s[i]-'0')]);
                    res.push_back(m[(s[i+1]-'0')*10]);
                    i += 2;
                }
                else i+=2;
            }
            if(size == res.size() && res.size() > 0) res.pop_back();
        }

        // for(int i=0;i<res.size();i++) cout<<res[i]<<endl;
        // cout<<endl;
        
        if(s.size()%3 > 0){
            if(parts > 0) res.push_back(places[parts]);
            int i = s.size()-s.size()%3;
            if(s.size()%3 == 2){
                if(s[i] -'0' > 0 && s[i+1] - '0' == 0){
                    res.push_back(m[(s[i]-'0')]);
                }
                else if(s[i] -'0' == 0 && s[i+1] - '0' > 0){
                    res.push_back(m[(s[i+1]-'0')*10]);
                }
                else if(s[i] -'0' > 0 && s[i+1] - '0' == 1){
                    res.push_back(m[(s[i+1]-'0')*10 + (s[i]-'0')]);
                }
                else if(s[i] -'0' > 0 && s[i+1] - '0' > 1){
                    res.push_back(m[(s[i]-'0')]);
                    res.push_back(m[(s[i+1]-'0')*10]);
                }
            }
            else{
                res.push_back(m[s[i]-'0']);
            }
        }

        // for(int i=0;i<res.size();i++) cout<<res[i]<<endl;

        string ans = "";

        for(int i=res.size()-1;i>0;i--) ans += (res[i] + " ");
        ans += res[0];
        
        return ans;
    }
};