class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        while(start > 0 || goal > 0){
            if(start%2 != goal%2) ans++;
            goal >>= 1;
            start >>= 1;
        }
        return ans;
    }
};