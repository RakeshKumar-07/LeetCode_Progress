class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0, t = points[0][1];
        for(int i=1;i<points.size();i++){
            if(t >= points[i][0]) t = min(t, points[i][1]);
            else{
                ans++;
                t = points[i][1];
            }
        }
        return ans+1;
    }
};