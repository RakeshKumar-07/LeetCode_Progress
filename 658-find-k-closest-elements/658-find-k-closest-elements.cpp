class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        int p,q;
        for(int i=0;i<n;i++){
            if(arr[i] >= x){
                q = i;
                break;
            }
        }
        p = q-1;
        for(int i=0;i<k;i++){
            if( q<=n-1 && p>=0 && abs(arr[p]-x) > abs(arr[q]-x) || p<0){
                ans.push_back(arr[q]);  
                q++;
            }
            else if(p>=0 && q<=n-1 && abs(arr[p]-x) <= abs(arr[q]-x) || q>n-1){
                ans.push_back(arr[p]);
                p--;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};