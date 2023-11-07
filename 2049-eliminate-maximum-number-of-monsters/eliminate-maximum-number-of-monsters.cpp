class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;
        for(int i=0;i<dist.size();i++) time.push_back((double)dist[i]/speed[i]);
        int ans = 0, t = 0;
        sort(time.begin(), time.end());
        for(int i=0;i<time.size();i++){
            if(time[i] > t) ans++;
            else break;
            t++;
        }
        return ans;
    }
};