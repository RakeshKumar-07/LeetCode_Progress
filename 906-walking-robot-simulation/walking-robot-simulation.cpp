class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        bool isY = true, isPos = true;
        long long x = 0, y = 0, ans = INT_MIN;
        map<pair<int,int>, bool> m;
        for(int i=0;i<obstacles.size();i++) m[{obstacles[i][0], obstacles[i][1]}] = true;
        for(int i=0;i<commands.size();i++){
            if(commands[i] >= 1){
                int tx = 0, ty = 0;
                for(int j=1;j<=commands[i];j++){
                    if(isY && isPos && !m[{x, y + j}]) ty = j;
                    else if(isY && !isPos && !m[{x, y - j}]) ty = -1*j;
                    else if(!isY && isPos && !m[{x + j, y}]) tx = j;
                    else if(!isY && !isPos && !m[{x - j, y}]) tx = -1*j;
                    else break;
                }
                x += tx;
                y += ty;
            }
            else if(commands[i] == -1){
                if(isY) isY = !isY;
                else if(!isY){
                    isPos = !isPos;
                    isY = !isY;
                }
            }
            else if(commands[i] == -2){
                if(isY){
                    isPos = !isPos;
                    isY = !isY;
                }
                else if(!isY) isY = !isY;
            }
            ans = max(ans, abs(x)*abs(x) + abs(y)*abs(y));
        }
        return ans;
    }
};