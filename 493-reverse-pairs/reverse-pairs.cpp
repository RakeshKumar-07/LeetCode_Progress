class Solution {
public:
    int ans = 0;

    // int binarySearch(vector<int>& arr, int l, int r, long long x){
    //     while (l <= r) {
    //         int m = l + (r - l) / 2;
    //         if (2*(long long)arr[m] < x) l = m + 1;
    //         else r = m - 1;
    //     }
    //     return r;
    // }

    void merge(vector<int>& array, int const left, int const mid, int const right){
        int const subArrayOne = mid - left + 1;
        int const subArrayTwo = right - mid;
    
        vector<int> leftArray(subArrayOne), rightArray(subArrayTwo);
    
        for (auto i = 0; i < subArrayOne; i++) leftArray[i] = array[left + i];
        for (auto j = 0; j < subArrayTwo; j++) rightArray[j] = array[mid + 1 + j];
    
        auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left, r = 0;

        for(int i=0;i<subArrayOne;i++){
            while(r < subArrayTwo && (long long)leftArray[i] > 2*(long long)rightArray[r]) r++;
            ans += r;
        }
    
        while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
    
        while (indexOfSubArrayOne < subArrayOne) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }

        while (indexOfSubArrayTwo < subArrayTwo) {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    }

    void mergeSort(vector<int>& array, int const begin, int const end){
        if (begin >= end) return;
        int mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return ans;
    }
};