class Solution {
public:
    long long mod = 1000000007;

    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod; 
        while (exp > 0) {
            if(exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;         
            exp = exp >> 1;                         
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        int ans = (modExp(4, n/2, mod) * modExp(5, n/2 + (n%2 == 1), mod)) % mod;
        return ans;
    }
};