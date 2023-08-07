class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, h = matrix.size()-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] > target) h--;
            if(matrix[mid][0] < target) l++;
        }
        if(h==-1) return false;
        
        int i = h;
        l = 0, h = matrix[i].size()-1;

        while(l<=h){
            int mid = l + (h-l)/2;
            if(matrix[i][mid] == target) return true;
            if(matrix[i][mid] > target) h--;
            if(matrix[i][mid] < target) l++;
        }

        return false;
    }
};