class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> ms;
        vector<pair<int,int>> temp;
        for(int i=0;i<temperatures.size();i++){
            while(!ms.empty() && ms.top().first < temperatures[i]){
                temp.push_back({ms.top().second, i - ms.top().second});
                ms.pop();
            }
            ms.push({temperatures[i], i});
        }
        while(!ms.empty()){
            temp.push_back({ms.top().second, 0});
            ms.pop();
        }
        sort(temp.begin(), temp.end());
        vector<int> ans;
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};