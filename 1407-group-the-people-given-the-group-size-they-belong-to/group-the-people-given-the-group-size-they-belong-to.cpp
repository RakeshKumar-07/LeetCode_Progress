class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m;
        for(int i=0;i<groupSizes.size();i++){
            m[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto i:m){
            int j = i.second.size()/i.first, k = 0;
            while(j--){
                vector<int> temp;
                for(int l=k;l<k+i.first;l++){
                    temp.push_back(i.second[l]);
                }
                ans.push_back(temp);
                k += i.first;
            }
        }
        return ans;
    }
};