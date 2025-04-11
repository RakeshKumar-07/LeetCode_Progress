class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low;i<=high;i++){
            if(((int)floor(log(i)/log(10)) + 1)%2 == 0){
                int pw = (floor(log(i)/log(10)) + 1)/2;
                int first = i/(int)pow(10, pw), second = i%(int)pow(10, pw);
                int sumF = 0, sumS = 0;
                while(first > 0){
                    sumF += first%10;
                    first /= 10;
                }
                while(second > 0){
                    sumS += second%10;
                    second /= 10;
                }
                if(sumF == sumS) ans++;
            }
        }
        return ans;
    }
};