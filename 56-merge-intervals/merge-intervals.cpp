class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int mini = intervals[0][0], maxi = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(maxi >= intervals[i][0]) maxi = max(maxi, intervals[i][1]);
            else{
                ans.push_back({mini, maxi});
                mini = intervals[i][0];
                maxi = intervals[i][1];
            }
        }
        ans.push_back({mini, maxi});
        return ans;
    }
};