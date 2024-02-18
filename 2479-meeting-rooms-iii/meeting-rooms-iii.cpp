class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n,0);
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> meet;
        priority_queue<int, vector<int>, greater<int>> empty;
        for(int i=0;i<n;i++) empty.push(i);
        for(int i=0;i<meetings.size();i++){
            while(meet.size() > 0 && meet.top().first <= meetings[i][0]){
                empty.push(meet.top().second);
                meet.pop();
            }
            if(empty.size() > 0){
                rooms[empty.top()]++;
                meet.push({meetings[i][1], empty.top()});
                empty.pop();
            }
            else{
                pair<long long,int> t = meet.top();
                meet.pop();
                rooms[t.second]++;
                meet.push({t.first + (long long)abs(meetings[i][0]-meetings[i][1]), t.second});
            }
        }
        int fr = 0, ans = 0;
        for(int i=n-1;i>=0;i--){
            if(fr <= rooms[i]){
                ans = i;
                fr = rooms[i];
            }
        }
        return ans;
    }
};