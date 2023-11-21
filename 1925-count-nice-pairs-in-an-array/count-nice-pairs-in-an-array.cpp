class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int M = 1000000007;
        vector<int> rev;
        for(int i=0;i<nums.size();i++){
            int n = nums[i], l = 0, newN = 0;
            vector<int> revN;
            while(n > 0){
                l++;
                revN.push_back(n%10);
                n /= 10;
            }
            while(l--){
                newN += revN[revN.size() - l - 1]*pow(10, l);
            }
            rev.push_back(newN);
        }
        map<int, long long> m;
        for(int i=0;i<rev.size();i++){
            m[nums[i]-rev[i]]++;
        }
        long long ans = 0;
        for(auto i:m){
            ans += ((long long)(i.second)*(i.second - 1))/2;
            ans %= M;
        }
        return ans;
    }
};