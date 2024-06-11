class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans(arr1.size());
        int k = 0;
        vector<bool> vis(1001, false);
        sort(arr1.begin(), arr1.end());
        for(int i=0;i<arr2.size();i++){
            int cnt = 0;
            for(int j=0;j<arr1.size();j++){
                if(arr2[i] == arr1[j]) cnt++;
            }
            for(int j=0;j<cnt;j++) ans[k++] = arr2[i];
            vis[arr2[i]] = true;
        }
        for(int i=0;i<1001;i++){
            int cnt = 0;
            if(!vis[i]){
                for(int j=0;j<arr1.size();j++){
                    if(i == arr1[j]) cnt++;
                }
                for(int j=0;j<cnt;j++) ans[k++] = i;
                vis[i] = true;
            }
        }
        return ans;
    }
};