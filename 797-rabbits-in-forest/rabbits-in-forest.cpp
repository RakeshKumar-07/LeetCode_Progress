class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> f(1001, 0);
        int ans = 0;
        for(int i=0;i<answers.size();i++) f[answers[i]]++;
        for(int i=0;i<1001;i++){
            ans += (f[i] - (f[i]%(i+1)));
            ans += (f[i]%(i+1)) > 0 ? (i+1) : 0;
        }
        return ans;
    }
};