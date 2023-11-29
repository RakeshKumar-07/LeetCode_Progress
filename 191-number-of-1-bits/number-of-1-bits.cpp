class Solution {
public:
    int hammingWeight(uint32_t n) {
        int setBitCount = 0;
        while (n != 0) {
            if(n%2 == 1) ++setBitCount;
            n /= 2;
        }
        return setBitCount;
    }
};