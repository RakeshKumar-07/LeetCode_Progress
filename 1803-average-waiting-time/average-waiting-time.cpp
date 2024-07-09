class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double currentTime = 1, waitingTime = 0;
        for(int i=0;i<customers.size();i++){
            currentTime = max(currentTime, (double)customers[i][0]);
            currentTime += customers[i][1];
            waitingTime += (currentTime - customers[i][0]);
        }
        return waitingTime/customers.size();
    }
};