class Solution {
public:
    int binarySearch(int l, int h, int target, vector<int>& newNums){
        if(l>h) return h;
        int mid = l + (h-l)/2;
        // if(newNums[mid] == target) return mid;
        if(newNums[mid] > target) return binarySearch(l, mid-1, target, newNums);
        return binarySearch(mid+1, h, target, newNums);
    }

    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dupVec;
        int dup = 0;
        dupVec.push_back(dup);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]) dup++;
            dupVec.push_back(dup);
        }

        int ans = INT_MIN;

        for(int i=0;i<nums.size();i++){
            int index = binarySearch(i, nums.size()-1, nums[i] + nums.size() - 1, nums);
            ans = max(ans, index - i + 1 - (dupVec[index] - dupVec[i]));
        }

        return (nums.size() - ans);
    }
};