class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        map<int,int> m;
        int cnt = 1, unique = 1;;
        for(int i=1;i<arr.size();i++){
            if(arr[i] == arr[i-1]) cnt++;
            else{
                m[cnt]++;
                cnt = 1;
                unique++;
            }
        }
        m[cnt]++;
        // cout<<unique<<endl;
        for(auto i:m){
            while(i.second > 0 && i.first <= k){
                // cout<<i.first<<" -> "<<i.second<<endl;
                k -= i.first;
                unique--;
                i.second--;
            }
        }
        // cout<<unique<<endl;
        return unique;
    }
};