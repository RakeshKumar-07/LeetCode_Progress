class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int, int>, bool> m;
        int x = 0, y = 0;
        m[{x,y}] = true;
        for(int i=0;i<path.size();i++){
            if(path[i] == 'N') y++;
            if(path[i] == 'S') y--;
            if(path[i] == 'E') x++;
            if(path[i] == 'W') x--;
            if(!m[{x,y}]) m[{x,y}] = true;
            else return true;
        }
        return false;
    }
};