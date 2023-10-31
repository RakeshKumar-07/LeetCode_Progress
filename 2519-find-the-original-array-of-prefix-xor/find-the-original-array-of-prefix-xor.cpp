class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        int prev = pref[0];
        ans.push_back(pref[0]);
        for(int i=1;i<pref.size();i++){
            int t = prev ^ pref[i];
            prev ^= t;
            ans.push_back(t);
        }
        return ans;
    }
};