class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int n1 = nums1.size(), n2 = nums2.size(), i = 0, j = 0;
        while(i<n1 && j<n2){
            if(nums1[i] <= nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n1){
            v.push_back(nums1[i]);
            i++;
        }

        while(j<n2){
            v.push_back(nums2[j]);
            j++;
        }

        if(v.size()%2 == 1) return v[v.size()/2];
        return (v[v.size()/2] + v[v.size()/2 - 1])/2.0;
    }
};