class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int ans = 1, right = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(right <= intervals[i][0]){
                right = intervals[i][1];
                ans++;
            }
        }
        return intervals.size() - ans;
    }
};