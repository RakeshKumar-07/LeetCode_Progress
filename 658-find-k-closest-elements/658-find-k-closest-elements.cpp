class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        deque<int> dq;
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
                dq.push_back(arr[q]);  
                q++;
            }
            else if(p>=0 && q<=n-1 && abs(arr[p]-x) <= abs(arr[q]-x) || q>n-1){
                dq.push_front(arr[p]);
                p--;
            }
        }
        for(int i=0;i<k;i++){
            if(dq.front() <= dq.back()){
                ans.push_back(dq.front());
                dq.pop_front();
            }
            else{
                ans.push_back(dq.back());
                dq.pop_back();
            }
        }
        return ans;
    }
};