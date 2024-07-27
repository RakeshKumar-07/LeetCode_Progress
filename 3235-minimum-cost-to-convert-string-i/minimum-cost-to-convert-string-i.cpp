class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));
        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;
        for (int i = 0; i < original.size(); i++) {
            dist[original[i] - 'a'][changed[i] - 'a'] = min(
                (long long)cost[i], dist[original[i] - 'a'][changed[i] - 'a']);
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    dist[j][k] = min(dist[j][i] + dist[i][k], dist[j][k]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (dist[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
                return -1;
            else
                ans += dist[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};