class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0 || (int)(log(left)/log(2)) != (int)(log(right)/log(2))) return 0;
        int cnt = 0;
        while(left != right){
            left = left>>1;
            right = right>>1;
            cnt++;
        }
        while(cnt--) left = left<<1;
        return left;
    }
};