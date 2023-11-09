class Solution {
public:
    int countHomogenous(string s) {
        // cout<<s.size()<<endl;
        vector<long long> count;
        int j = 1, M = 1000000007;
        long long ans = 0;
        for(int i=1;i<s.size();i++){
            if(s[i] != s[i-1]){
                count.push_back(j);
                j = 1;
            }
            else j++;
        }
        count.push_back(j);
        for(int i=0;i<count.size();i++){
            ans += ((count[i])*(count[i] + 1))/2;
            ans %= M;
        }
        return ans;
    }
};