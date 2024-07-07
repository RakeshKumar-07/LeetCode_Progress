class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, filled = 0, left = 0;
        while(numBottles > 0){
            ans += numBottles;
            filled = (numBottles + left)/numExchange;
            left = (numBottles + left)%numExchange;
            numBottles = filled;
        }
        return ans;
    }
};