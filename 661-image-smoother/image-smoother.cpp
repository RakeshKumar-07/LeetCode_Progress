class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size(), 0));
        for(int i=0;i<img.size();i++){
            for(int j=0;j<img[i].size();j++){
                int sum = 0, t = 0;
                if(i>0){
                    for(int k=j-1;k<=j+1;k++){
                        if(k>=0 && k<img[i-1].size()){
                            sum += img[i-1][k];
                            t++;
                        }
                    }
                }
                for(int k=j-1;k<=j+1;k++){
                    if(k>=0 && k<img[i].size()){
                        sum += img[i][k];
                        t++;
                    }
                }
                if(i<img.size()-1){
                    for(int k=j-1;k<=j+1;k++){
                        if(k>=0 && k<img[i+1].size()){
                            sum += img[i+1][k];
                            t++;
                        }
                    }
                }
                ans[i][j] = sum/t;
            }
        }
        return ans;
    }
};