class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0],freq = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==num) freq++;
            if(nums[i]!=num){
	            if(freq==0){
		            num = nums[i];
		            freq = 1;
	            }else{
		            freq--;
	            }
            }
        }
        return num;
    }
};