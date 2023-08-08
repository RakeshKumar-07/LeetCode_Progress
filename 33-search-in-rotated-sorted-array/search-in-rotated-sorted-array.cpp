class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = -1, l = 0, h = nums.size()-1;

        while(l<h){
            int mid = l + (h-l)/2;
            if( nums[0] <= nums[mid] ) l = mid+1;
            else h = mid;
        }
        pivot = l, l = 0, h = nums.size()-1;

        if(target >= nums[pivot] && target <= nums[h]) l = pivot; 
        else h = pivot-1;

        while(l<=h){
            int mid = l + (h-l)/2;
            if( target > nums[mid] ) l = mid+1;
            else if( target < nums[mid] ) h = mid-1;
            else return mid;
        }
        return -1;
    }
};