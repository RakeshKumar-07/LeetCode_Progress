class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans(n, 1);
        int sum = 0, neededSum = 0;
        for(int i=0;i<rolls.size();i++) sum += rolls[i];
        neededSum = mean*(rolls.size() + n) - sum;
        if(neededSum < n || ((double)neededSum/6 > n)) return {};
        neededSum -= n;
        for(int i=0;i<n;i++){
            if(neededSum/6 > 0){
                ans[i] = 6;
                neededSum -= 5;
            }
            else if(neededSum%6 > 0){
                ans[i] += neededSum;
                neededSum = 0;
            }
            else break;
        }
        return ans;
    }
};