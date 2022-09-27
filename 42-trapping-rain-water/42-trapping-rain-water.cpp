class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax = 0;
        int rightmax = 0;
        vector<vector<int>> maxheight(n,vector<int>(2,0));
        for(int i=0;i<n;i++){
            leftmax = max(leftmax,height[i]);
            maxheight[i][0] = leftmax;
        }
        for(int i=n-1;i>=0;i--){
            rightmax = max(rightmax,height[i]);
            maxheight[i][1] = rightmax;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += min(maxheight[i][0],maxheight[i][1]) - height[i];
        }
        return sum;
    }
};