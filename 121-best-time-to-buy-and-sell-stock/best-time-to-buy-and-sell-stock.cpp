class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> lMin, rMax;
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i=0;i<prices.size();i++){
            mini = min(mini, prices[i]);
            lMin.push_back(mini);
        }
        for(int i=prices.size()-1;i>=0;i--){
            maxi = max(maxi, prices[i]);
            rMax.push_back(maxi);
        }
        reverse(rMax.begin(), rMax.end());
        int ans = 0;
        for(int i=0;i<prices.size();i++) ans = max(ans, rMax[i] - lMin[i]);
        return ans;
    }
};