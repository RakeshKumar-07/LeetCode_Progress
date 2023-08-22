class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans  = "";
        while(columnNumber > 0){
            int ascii = (columnNumber-1)%26;
            columnNumber = (columnNumber-1)/26;
            ans += 'A' + ascii;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};