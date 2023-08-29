class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> left, right;
        int temp = 0;
        for(int i=0;i<customers.size();i++){
            left.push_back(temp);
            if(customers[i] == 'N') temp++;
        }
        left.push_back(temp);
        temp = 0;
        right.push_back(temp);
        for(int i=customers.size()-1;i>=0;i--){
            if(customers[i] == 'Y') temp++;
            right.push_back(temp);
        }
        reverse(right.begin(), right.end());
        int res = INT_MAX, ans = 0;
        for(int i=0;i<customers.size()+1;i++){
            if(res > left[i] + right[i]){
                res = left[i] + right[i];
                ans = i;
            }
        }
        return ans;
    }
};