class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        vector<pair<int,int>> v;
        int maxi = INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(maxi < arr[i]){
                maxi = arr[i];
                v.push_back({i, arr[i]});
            }
        }
        if(k >= arr.size() || v.size() == 1) return maxi;

        for(int i=0;i<v.size()-1;i++){
            // cout<<(v[i+1].first - v[i].first - 1) + (v[i].first - 1 >= 0 && arr[v[i].first - 1] < v[i].second ? 1 : 0)<<endl;
            if((v[i+1].first - v[i].first - 1) + (v[i].first - 1 >= 0 && arr[v[i].first - 1] < v[i].second ? 1 : 0) >= k ){
                return v[i].second;
            }
        }

        return maxi;
    }
};