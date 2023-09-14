class Solution {
public:

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> m;
        for(int i=0;i<tickets.size();i++){
            m[tickets[i][0]].push_back(tickets[i][1]);
        }

        for (auto& [_, dests] : m) {
            sort(dests.rbegin(), dests.rend());
        }

        vector<string> ans;
        stack<string> s;
        s.push("JFK");
        while(!s.empty()){
            string t = s.top();
            if(m.find(t) != m.end() && m[t].size() > 0){
                s.push(m[t].back());
                m[t].pop_back();
            }
            else{
                ans.push_back(t);
                s.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};