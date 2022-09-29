class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        arr.push_back(x);
        sort(arr.begin(), arr.end());
        int p,q;
        for(int i=0;i<n+1;i++){
            if(arr[i] == x){
                p = i;
                q = i;
                break;
            }
        }
        p--,q++;
        for(int i=0;i<k;i++){
            if( q<=n && p>=0 && abs(arr[p]-x) > abs(arr[q]-x) || p<0){
                ans.push_back(arr[q]);  
                q++;
            }
            else if(p>=0 && q<=n && abs(arr[p]-x) <= abs(arr[q]-x) || q>n){
                ans.push_back(arr[p]);
                p--;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};