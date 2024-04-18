class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<bool>> vis(101, vector<bool>(101,false));
        stack<vector<int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    break;
                }
            }
            if(q.size() == 1) break;
        }
        int k = 0;
        while(q.size() > 0){
                vector<int> t = q.top();
                q.pop();
                int x = t[0], y = t[1];
                
                vis[x][y] = true;
                
                if(x+1 < grid.size() && vis[x+1][y] == false && grid[x+1][y] == 1){
                    q.push({x+1,y});
                    vis[x+1][y] = true;
                }

                if(x-1 >= 0 && vis[x-1][y] == false && grid[x-1][y] == 1){
                    q.push({x-1,y});
                    vis[x-1][y] = true;
                }
                
                if(y+1 < grid[x].size() && vis[x][y+1] == false && grid[x][y+1] == 1){
                    q.push({x,y+1});
                    vis[x][y+1] = true;
                }
                
                if(y-1 >= 0 && vis[x][y-1] == false && grid[x][y-1] == 1){
                    q.push({x,y-1});
                    vis[x][y-1] = true;
                }

                if(x+1 >= grid.size() ){
                    ans++;
                }

                if(x-1 < 0 ){
                    ans++;
                }

                if( y+1 >= grid[x].size()){
                    ans++;
                }

                if(y-1 < 0 ){
                    ans++;
                }

                if(x+1 < grid.size() && grid[x+1][y] == 0){
                    ans++;
                }

                if(x-1 >= 0 && grid[x-1][y] == 0){
                    ans++;
                }
                
                if(y+1 < grid[x].size() && grid[x][y+1] == 0){
                    ans++;
                }
                
                if(y-1 >= 0 && grid[x][y-1] == 0){
                    ans++;
                }
        }
        return ans;
    }
};