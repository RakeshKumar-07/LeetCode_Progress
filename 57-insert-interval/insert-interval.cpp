class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> m(100001, 0);
        vector<bool> vis(100001, false);
        for(int i=0;i<intervals.size();i++){
            m[intervals[i][0]]++;
            vis[intervals[i][0]] = true;
            m[intervals[i][1]]--;
            vis[intervals[i][1]] = true;
        }
        m[newInterval[0]]++;
        vis[newInterval[0]] = true;
        m[newInterval[1]]--;
        vis[newInterval[1]] = true;
        vector<vector<int>> ans;
        int t = 0, a, c = 0;
        for(int i=0;i<100001;i++){
            if(!vis[i]) continue;
            t += m[i];
            if(c == 0){
                a = i;
                c = 1;
            }
            if(t == 0){
                ans.push_back({a,i});
                c = 0;
            }
        }
        return ans;
    }
};