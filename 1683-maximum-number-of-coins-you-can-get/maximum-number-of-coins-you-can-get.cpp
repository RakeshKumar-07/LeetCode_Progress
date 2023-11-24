class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int p = 0, q = piles.size()-1, ans = 0;
        while(p<q){
            ans += piles[q-1];
            p++;
            q -= 2;
        }
        return ans;
    }
};