class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        map<pair<int,int>, int> m;
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i][0] > dominoes[i][1]) swap(dominoes[i][0], dominoes[i][1]);
            m[{dominoes[i][0], dominoes[i][1]}]++;
        }
        for(auto i:m) ans += (i.second*(i.second-1))/2;
        return ans;
    }
};