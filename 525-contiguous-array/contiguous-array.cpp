class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> f1(200001, INT_MAX), f2(200001, INT_MAX);
        int zeroes = 0, ones = 0, ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1) ones++;
            else zeroes++;
            if(ones == zeroes) ans = max(i+1, ans);
            // cout<<ones<<" , "<<zeroes<<" => "<<f2[ones-zeroes + 100000]<<" -> "<<f1[zeroes - ones + 100000]<<endl;
            if(f2[ones-zeroes + 100000] != INT_MAX) ans = max(i - f2[ones-zeroes + 100000], ans);
            f1[zeroes - ones + 100000] = min(f1[zeroes - ones + 100000], i);
            f2[ones - zeroes + 100000] = min(f2[ones - zeroes + 100000], i);
        }
        return ans;
    }
};