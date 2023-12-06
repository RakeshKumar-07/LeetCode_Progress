class Solution {
public:
    int totalMoney(int n) {
        int m = n/7, r = n%7, ans = 0;
        for(int i=1;i<=m;i++) ans += 7*(i+3);
        ans += (r*(2*(m+1) + (r-1)))/2;
        return ans;
    }
};