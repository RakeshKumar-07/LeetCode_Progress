class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> t;
        for(int i=0;i<nums.size();i++) t.push_back({nums[i],i});
        sort(t.begin(), t.end());
        int p = 0, q = t.size()-1;
        while(p<q){
            if(t[p].first + t[q].first > target) q--;
            else if(t[p].first + t[q].first < target) p++;
            else return {t[p].second, t[q].second};
        }
        return {};
    }
};