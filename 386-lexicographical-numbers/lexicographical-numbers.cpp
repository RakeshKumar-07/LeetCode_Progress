class Solution {
public:

    vector<int> lexicalOrder(int n) {
        vector<string> t;
        for(int i=1;i<=n;i++) t.push_back(to_string(i));
        sort(t.begin(), t.end());
        vector<int> ans;
        for(int i=0;i<n;i++) ans.push_back(stoi(t[i]));
        return ans;
    }
};