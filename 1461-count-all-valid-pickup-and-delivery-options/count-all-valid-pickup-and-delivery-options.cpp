class Solution {
public:
    int countOrders(int n) {
        long long M = 1000000007;
        long long ans = 1, twos = n;
        for(int i=1;i<=2*n;i++){
            ans *= i;
            while(ans%2 == 0 && twos>0){
                ans /= 2;
                twos--;
            }
            ans %= M;
        }
        return ans%M;
    }
};