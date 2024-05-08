class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<score.size();i++) pq.push({score[i], i});
        vector<string> v(10001, "-1");
        int i = 1;
        while(pq.size() > 0){
            if(i == 1) v[pq.top().second] = "Gold Medal";
            else if(i == 2) v[pq.top().second] = "Silver Medal";
            else if(i == 3) v[pq.top().second] = "Bronze Medal";
            else v[pq.top().second] = to_string(i);
            pq.pop();
            i++;
        }
        vector<string> ans;
        for(int i=0;i<score.size();i++) ans.push_back(v[i]);
        return ans;
    }
};