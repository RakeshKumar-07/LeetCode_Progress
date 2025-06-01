class Solution {
public:    
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i=0;i<=min(n,limit);i++){
            int rest = n-i;
            if(rest <= limit*2){
                ans += abs(2*min(limit, rest) - rest) + 1;
            }
        }
        return ans;
    }
};