class Solution {
public:
    long long int m = 1000000007;
    
    int concatenatedBinary(int n) {
        long long ans = 0;
        for(int i=1;i<=n;i++){
            int len = (int)log2(i)+1; 
            ans = ((ans<<len)%m + i)%m;
        }
        return (int)ans%m;
    }
};