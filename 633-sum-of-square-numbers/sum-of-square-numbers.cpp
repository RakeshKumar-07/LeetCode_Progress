class Solution {
public:
    bool judgeSquareSum(int c) {
        int newC = floor(sqrt(c));
        for(int i=0;i<=newC;i++){
            int a = c - i*i;
            if(ceil(sqrt(a)) == floor(sqrt(a))) return true;
        }
        return false;
    }
};