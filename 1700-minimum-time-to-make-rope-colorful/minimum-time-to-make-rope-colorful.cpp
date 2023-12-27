class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, sum = 0, maxi = INT_MIN;
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i] == colors[i+1]){
                maxi = max(neededTime[i], maxi);
                sum += neededTime[i];
            }
            else{
                maxi = max(neededTime[i], maxi);
                sum += neededTime[i];
                ans += sum - maxi;
                sum = 0;
                maxi = INT_MIN;
            }
        }
        maxi = max(neededTime[neededTime.size()-1], maxi);
        sum += neededTime[neededTime.size()-1];
        ans += sum - maxi;
        return ans;
    }
};