class Solution {
public:
    int minimumPushes(string word) {
        vector<int> f(26, 0);
        for(int i=0;i<word.size();i++) f[word[i] - 'a']++;
        priority_queue<int> pq;
        for(int i=0;i<26;i++) if(f[i] != 0) pq.push(f[i]);
        int i = 1, j = 0, ans = 0;
        while(pq.size() > 0){
            ans += i*pq.top();
            pq.pop();
            j++;
            if(j%8 == 0){
                i++;
                j = 0;
            }
        }
        return ans;
    }
};