class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> m;
        int maxi = 0;
        for(int i=1;i<=n;i++){
            int s = 0, d = i;
            while(d > 0){
                s += d%10;
                d /= 10;
            }
            m[s]++;
            maxi = max(m[s], maxi);
        }
        int ans = 0;
        for(auto i:m) if(maxi == i.second) ans++;
        return ans;
    }
};