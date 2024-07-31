class Solution {
public:

    int dp[1001];

    int solve(int i, int n, vector<vector<int>>& books, int shelfWidth){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int t = INT_MAX, sum = 0, maxi = INT_MIN;
        for(int j=i;j<n;j++){
            sum += books[j][0];
            maxi = max(books[j][1], maxi);
            if(shelfWidth >= sum) t = min(t, maxi + solve(j+1,n,books,shelfWidth));
        }
        return dp[i] = t;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, -1, sizeof(dp));
        return solve(0, books.size(), books, shelfWidth);
    }
};