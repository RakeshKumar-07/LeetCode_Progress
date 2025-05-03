class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int tAns = INT_MAX, bAns = INT_MAX;
        for(int i=1;i<=6;i++){
            bool r = true;
            int t = 0;
            for(int j=0;j<tops.size();j++){
                if(tops[j] != i && bottoms[j] != i){
                    r = false;
                    break;
                }
                else if(tops[j] != i && bottoms[j] == i) t++;
            }
            if(r) tAns = min(t, tAns);
        }
        for(int i=1;i<=6;i++){
            bool r = true;
            int b = 0;
            for(int j=0;j<tops.size();j++){
                if(tops[j] != i && bottoms[j] != i){
                    r = false;
                    break;
                }
                else if(bottoms[j] != i && tops[j] == i) b++;
            }
            if(r) bAns = min(b, bAns);
        }
        return min(tAns, bAns) == INT_MAX ? -1 : min(tAns, bAns);
    }
};