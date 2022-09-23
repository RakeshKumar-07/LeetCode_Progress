class Solution {
public:
    long long int m = 1000000007;
    
    int concatenatedBinary(int n) {
        long long ans = 0;
        for(int i=1;i<=n;i++){
            ans <<= ((int)log2(i)+1);
            ans %= m;
            ans += i;
            ans %= m;
        }
        return (int)ans%m;
    }
};