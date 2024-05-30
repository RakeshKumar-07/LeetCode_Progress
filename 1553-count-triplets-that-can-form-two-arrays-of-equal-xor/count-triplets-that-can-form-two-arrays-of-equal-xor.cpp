class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> newArr(arr.size()+1);
        newArr[0] = 0;
        int ans = 0;
        for(int i=0;i<arr.size();i++) newArr[i+1] = arr[i]^newArr[i];

        for(int i=0;i<=arr.size();i++){
            for(int j=i+1;j<=arr.size();j++){
                for(int k=j+1;k<=arr.size();k++){

                    if( (newArr[i]^newArr[j]) == (newArr[j]^newArr[k]) ){
                        ans++;
                    } 
                }
            }
        }
        return ans;
    }
};