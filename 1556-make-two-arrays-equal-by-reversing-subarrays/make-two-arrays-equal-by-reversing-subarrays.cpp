class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> fq1(1001, 0), fq2(1001, 0);
        for(int i=0;i<target.size();i++) fq1[target[i]]++;
        for(int i=0;i<arr.size();i++) fq2[arr[i]]++;
        return fq1 == fq2;
    }
};