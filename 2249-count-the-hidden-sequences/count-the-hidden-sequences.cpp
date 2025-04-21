class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mini = INT_MAX, maxi = INT_MIN, sum = 0;
        for(int i=0;i<differences.size();i++){
            sum += differences[i];
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }
        int ans = (upper - (maxi < 0 ? 0 : maxi)) - (lower - (mini > 0 ? 0 : mini)) + 1;
        return ans < 0 ? 0 : ans;
    }
};