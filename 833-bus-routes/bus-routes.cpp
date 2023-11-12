class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        map<int, vector<int>> m;
        vector<bool> vis1(501, false), vis2(1000001, false);
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                m[routes[i][j]].push_back(i);
            }
        }
        // cout<<routes.size()<<endl;
        int ans = 0;
        queue<int> q;
        q.push(source);
        while(q.size() > 0){
            int size = q.size();
            while(size--){
                int t = q.front();
                q.pop();
                vis2[t] = true;
                for(int i = 0;i<m[t].size();i++){
                    if(!vis1[m[t][i]]){
                        for(int j=0;j<routes[m[t][i]].size();j++){
                            if(!vis2[routes[m[t][i]][j]]){
                                q.push(routes[m[t][i]][j]);
                                vis2[routes[m[t][i]][j]] = true;
                            }
                        }
                        vis1[m[t][i]] = true;
                    }
                }
            }
            ans++;
            if(vis2[target]) break;
        }
        return vis2[target] ? ans : -1;
    }
};