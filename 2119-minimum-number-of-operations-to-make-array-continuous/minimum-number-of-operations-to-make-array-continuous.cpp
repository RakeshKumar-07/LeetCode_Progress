class Solution {
public:
    int binarySearch(int l, int h, int target, vector<int>& newNums){
        if(l>h) return h;
        int mid = l + (h-l)/2;
        if(newNums[mid] == target) return mid;
        if(newNums[mid] > target) return binarySearch(l, mid-1, target, newNums);
        return binarySearch(mid+1, h, target, newNums);
    }

    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> newNums, dupVec;
        int dup = 0;
        dupVec.push_back(dup);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]) dup++;
            // else newNums.push_back(nums[i]);
            dupVec.push_back(dup);
        }
        // newNums.push_back(nums[nums.size()-1]);

        int ans = INT_MIN;

        for(int i=0;i<nums.size();i++){
            int index = binarySearch(i, nums.size()-1, nums[i] + nums.size() - 1, nums);
            ans = max(ans, index - i + 1 - (dupVec[index] - dupVec[i]));
            // cout<<i<<" -> "<<index<<" -> "<<nums[i]<<" -> "<<ans<<" -> "<<(dupVec[index] - dupVec[i])<<endl;
        }

        // for(int i=0;i<newNums.size();i++){
        //     int index = binarySearch(i, newNums.size()-1, newNums[i] + newNums.size() - 1, newNums);
        //     ans = max(ans, index - i + 1 + dupVec[i]);
        //     cout<<i<<" -> "<<index<<" -> "<<newNums[i]<<" -> "<<ans<<endl;
        // }

        return (nums.size() - ans);
    }
};