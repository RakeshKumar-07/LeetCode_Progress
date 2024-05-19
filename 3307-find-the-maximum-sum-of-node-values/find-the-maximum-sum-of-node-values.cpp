class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> e;
        vector<bool> vis(20001, false);
        for(int i=0;i<edges.size();i++){
            e[edges[i][0]].push_back(edges[i][1]);
            e[edges[i][1]].push_back(edges[i][0]);
        }
        long long ans = 0;
        vector<int> gain, loss;
        queue<int> q;
        q.push(0);
        while(q.size() > 0){
            int s = q.size();
            while(s--){
                int t = q.front();
                q.pop();
                vis[t] = true;
                ans += nums[t];
                if((nums[t]^k) > nums[t]) gain.push_back((nums[t]^k) - nums[t]);
                else loss.push_back(nums[t] - (nums[t]^k));
                for(int i=0;i<e[t].size();i++){
                    if(!vis[e[t][i]]) q.push(e[t][i]);
                    vis[e[t][i]] = true;
                }
            }
        }
        sort(gain.begin(), gain.end());
        sort(loss.begin(), loss.end());
        if(gain.size()%2 == 0) for(int i=0;i<gain.size();i++) ans += gain[i];
        else {
            for(int i=1;i<gain.size();i++) ans += gain[i];
            if(loss.size() > 0 && gain.size() > 0 && gain[0] - loss[0] > 0) ans += gain[0] - loss[0];
        }
        return ans;
    }
};