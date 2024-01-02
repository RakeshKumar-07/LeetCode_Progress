class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> m(201, 0);
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            maxi = max(m[nums[i]], maxi);
        }
        vector<vector<int>> ans;
        for(int i=0;i<maxi;i++){
            vector<int> t;
            for(int j=0;j<201;j++){
                if(m[j] > 0){
                    t.push_back(j);
                    m[j]--;
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};