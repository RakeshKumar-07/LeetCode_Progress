class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=0;i<=n;i++){
            int cnt = 0, t = i;
            while(t>0){
                if(t%2==1) cnt++;
                t /= 2;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};