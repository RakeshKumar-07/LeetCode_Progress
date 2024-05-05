class Solution {
public:
    int gcd( int a, int b ){
        if ( b < a ) swap(a,b);
        if ( a == 0 ) return b;
        return gcd(b%a, a);
    }

    int lcm( int a, int b ){
        return (a*b)/gcd(a,b);
    }
    
    int minAnagramLength(string s) {
        sort(s.begin(), s.end());
        vector<int> f(26);
        for(int i=0;i<s.size();i++) f[s[i]-'a']++;
        int ans = f[s[0]-'a'];
        for(int i=0;i<26;i++) if(f[i] != 0) ans = gcd(ans, f[i]);
        return s.size()/ans;
    }
};