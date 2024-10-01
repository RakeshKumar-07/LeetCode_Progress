class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        cout<<arr.size()<<endl;
        for(int i=0;i<arr.size();i++) arr[i] = ((arr[i] % k) + k) % k;
        vector<int> f(k+1, 0);
        for(int i=0;i<arr.size();i++) f[arr[i]]++;
        for(int i=1;i<k;i++){
            if(f[i] != f[k - i] || (i == k-i && f[i]%2 == 1)) return false;
        }
        return true;
    }
};