class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<vector<int>> right, left;
        int n = dominoes.length();
        string ans = dominoes;
        int tempi = INT_MIN;
        char cur;
        int inv = INT_MIN;
        // Filling neighbours of '.'
        for(int i=0;i<n;i++){
            if(dominoes[i] == 'R'){
                tempi = i;
                cur = 'R';
            }
            if(dominoes[i] == 'L' && cur != 'L'){
                cur = 'L';
                if(tempi%2 == i%2 && tempi != INT_MIN){
                    int m = tempi + (i-tempi)/2;
                    ans[m-1] = 'R';
                    ans[m+1] = 'L';
                    right.push_back({tempi,m-1});
                    left.push_back({m+1,i});
                }
                else if(tempi != INT_MIN){
                    int m = tempi + (i-tempi)/2;
                    ans[m] = 'R';
                    ans[m+1] = 'L';
                    right.push_back({tempi,m});
                    left.push_back({m+1,i});
                }
            }
        }
                
        
        // filling leftover spots
         for(int i=0;i<n;i++){
            if(dominoes[i] == 'R'){
                if(inv == 0){
                    right.push_back({tempi,i});
                }
                tempi = i;
                inv = 0;
            }
            if(dominoes[i] == 'L'){
                if(inv == 1){
                    left.push_back({tempi,i});
                }
                tempi = i;
                inv = 1;
            }
        }
        n = right.size();
        if(n > 0){
            int m = right[0].size();
            for(int i=0;i<n;i++){
                for(int j=right[i][0];j<right[i][1];j++){
                    ans[j] = 'R';
                }
            }
        }
        n = left.size();
        if(n > 0){
            int m = left[0].size();
            for(int i=0;i<n;i++){
                for(int j=left[i][0];j<left[i][1];j++){
                    ans[j] = 'L';
                }
            }
        }
        
        
         
        // Filling start and end
        n = dominoes.length();
        for(int i=0;i<n;i++){
            if(ans[i] == 'L'){
                for(int j=0;j<i;j++) ans[j] = 'L';
                break;
            }
            if(ans[i] == 'R') break;
        }
        for(int i=n-1;i>=0;i--){
            if(ans[i] == 'R'){
                for(int j=n-1;j>i;j--) ans[j] = 'R';
                break;
            }
            if(ans[i] == 'L') break;
        }
        return ans;
    }
};