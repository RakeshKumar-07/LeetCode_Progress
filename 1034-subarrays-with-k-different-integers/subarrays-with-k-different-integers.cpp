class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int size = 0, ans1 = 0, j = 0, ans2 = 0;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]] == 0) size++;
            m[nums[i]]++;
            while(size > k){
                m[nums[j]]--;
                if(m[nums[j]] == 0) size--;
                j++;
            }
            ans1 += i-j+1;
        }
        j = 0;
        m.clear();
        size = 0;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]] == 0) size++;
            m[nums[i]]++;
            while(size > k-1){
                m[nums[j]]--;
                if(m[nums[j]] == 0) size--;
                j++;
            }
            ans2 += i-j+1;
        }
        return ans1-ans2;
    }
};