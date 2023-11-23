class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            vector<int> v;
            for(int j=l[i];j<=r[i];j++) v.push_back(nums[j]);
            sort(v.begin(), v.end());
            if(v.size() == 1) ans.push_back(true);
            else{
                int d = v[1] - v[0];
                bool t = true;
                for(int j=1;j<v.size();j++){
                    if(d != v[j] - v[j-1]) t &= false;
                }
                ans.push_back(t);
            }
        }
        return ans;
    }
};