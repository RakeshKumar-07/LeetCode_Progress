class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = INT_MAX, maxi = INT_MIN, ans = INT_MIN;
        for(int i=0;i<arrays.size();i++){
            if(i != 0) ans = max(max(abs(mini-arrays[i][arrays[i].size()-1]), abs(maxi - arrays[i][0])), ans);
            mini = min(arrays[i][0], mini);
            maxi = max(arrays[i][arrays[i].size()-1], maxi);
        }
        return ans;
    }
};