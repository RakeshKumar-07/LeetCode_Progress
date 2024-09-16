class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        for(int i=0;i<timePoints.size();i++){
            int h = stoi(timePoints[i].substr(0, 2)), m = stoi(timePoints[i].substr(3, 2));
            time.push_back(h*60 + m);
        }
        sort(time.begin(), time.end());
        time.push_back(time[0] + 24*60);
        int ans = INT_MAX;
        for(int i=1;i<time.size();i++) ans = min(time[i] - time[i-1], ans);
        return ans;
    }
};