class Solution {
public:
    static bool compareString(string a, string b){
        return (b+a) < (a+b);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int i=0;i<nums.size();i++) v.push_back(to_string(nums[i]));
        sort(v.begin(), v.end(), compareString);
        string ans = "";
        for(int i=0;i<v.size();i++) ans += v[i];
        if(ans[0] == '0') return "0";
        return ans;
    }

};