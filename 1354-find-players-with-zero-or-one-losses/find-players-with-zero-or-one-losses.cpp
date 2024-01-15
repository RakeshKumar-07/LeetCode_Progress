class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> score(100001, vector<int>(2, 0));
        for(int i=0;i<matches.size();i++){
            score[matches[i][0]][0]++;
            score[matches[i][1]][1]--;
        }
        vector<vector<int>> ans;
        vector<int> t;
        for(int i=0;i<score.size();i++) if(score[i][0] != 0 && score[i][1] == 0) t.push_back(i);
        ans.push_back(t);
        t.clear();
        for(int i=0;i<score.size();i++) if(score[i][1] == -1) t.push_back(i);
        ans.push_back(t);
        return ans;
    }
};