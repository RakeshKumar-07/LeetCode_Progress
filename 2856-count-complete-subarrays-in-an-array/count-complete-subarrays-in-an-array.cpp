class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,bool> m;
        for(int i=0;i<nums.size();i++) m[nums[i]] = true;
        int cnt = m.size(), ans = 0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int, bool> h;
            for(int j=i;j<nums.size();j++){
                h[nums[j]] = true;
                if(h.size() == cnt) ans++;
            }
        }
        return ans;
    }
};