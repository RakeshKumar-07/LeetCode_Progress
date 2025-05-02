class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int right[100001],left[100001];
        for(int i=0;i<100001;i++) right[i] = left[i] = INT_MAX;
        int c = INT_MIN;
        char cur = ' ';
        for(int i=0;i<n;i++){
            if(dominoes[i] == 'R'){
                c = 0;
                right[i] = 0;
                cur = 'R';
            }
            if(dominoes[i] == '.'  && cur == 'R'){
                c++;
                right[i] = c;
            }
            if(dominoes[i] == 'L')
                cur = ' ';
        }
        c = 0;
        cur = ' ';
        for(int i=n-1;i>=0;i--){
            if(dominoes[i] == 'L'){
                c = 0;
                left[i] = 0;
                cur = 'L';
            }
            if(dominoes[i] == '.'  && cur == 'L'){
                c++;
                left[i] = c;
            }
            if(dominoes[i] == 'R')
                cur = ' ';
        }
        
        for(int i=0;i<n;i++){
            if(right[i]>left[i])
                dominoes[i] = 'L';
            else if(right[i]<left[i])
                dominoes[i] = 'R';
        }
        return dominoes;
    }
};