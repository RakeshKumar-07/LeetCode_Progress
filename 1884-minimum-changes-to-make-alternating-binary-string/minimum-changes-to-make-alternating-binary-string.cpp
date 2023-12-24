class Solution {
public:
    int minOperations(string s) {
        int ans = INT_MAX, ones = 0, zeroes = 0;
        for(int i=0;i<s.size();i++){
            if(i%2 == 0 && s[i] != '0') ones++;
            else if(i%2 == 1 && s[i] != '1') zeroes++;
        }
        ans = ones+zeroes;
        ones = 0, zeroes = 0;
        for(int i=0;i<s.size();i++){
            if(i%2 == 0 && s[i] != '1') zeroes++;
            else if(i%2 == 1 && s[i] != '0') ones++;
        }
        return min(ans, ones+zeroes);
    }
};