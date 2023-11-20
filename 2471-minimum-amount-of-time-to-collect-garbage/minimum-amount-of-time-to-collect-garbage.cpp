class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int G = -1, P = -1, M = -1, GC = 0, PC = 0, MC = 0;
        for(int i=0;i<garbage.size();i++){
            for(int j=0;j<garbage[i].size();j++){
                if(garbage[i][j] == 'G'){
                    G = max(G,i);
                    GC++;
                }
                if(garbage[i][j] == 'P'){
                    P = max(P,i);
                    PC++;
                }
                if(garbage[i][j] == 'M'){
                    M = max(M,i);
                    MC++;
                }
            }
        }
        for(int i=1;i<travel.size();i++) travel[i] += travel[i-1];
        int ans = GC + PC + MC;
        if(G != -1) ans += G == 0 ? 0 : travel[G-1];
        if(P != -1) ans += P == 0 ? 0 : travel[P-1];
        if(M != -1) ans += M == 0 ? 0 : travel[M-1];
        return ans;
    }
};