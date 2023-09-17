class Solution {
public:

    int shortestPathLength(vector<vector<int>>& graph) {
        map<pair<int,int>,bool> m;
        int ans = INT_MAX;
        int all = 1<<graph.size();
        all--;
        queue<pair<int, pair<int,int>>> q;
        for(int i=0;i<graph.size();i++){
            int mask = 1<<i;
            q.push({i, {0, mask}});
            m[{i,mask}] = true;
        }

        while(!q.empty()){
            pair<int, pair<int,int>> t = q.front();
            q.pop();
            if(all == t.second.second) ans = min(t.second.first, ans);

            for(int i=0;i<graph[t.first].size();i++){
                int newMask = t.second.second | 1<<graph[t.first][i];
                if(!m[{graph[t.first][i], newMask}]){
                    q.push({graph[t.first][i],{t.second.first+1, newMask}});
                    m[{graph[t.first][i], newMask}] = true;
                }
            }
        }
        return ans;
    }
};