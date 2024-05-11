class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        const int n= quality.size();
        vector<array<double, 2>>  worker(n);
        for(int i= 0; i < n; i++) {
            worker[i]={(double)wage[i]/quality[i], (double)quality[i]}; 
        }
        sort(worker.begin(), worker.end());

        int quality_sum = 0;

        priority_queue<int> pq;
        for(int i = 0; i < k; i++) {
            quality_sum += worker[i][1];
            pq.push(worker[i][1]);
        }
        double pay = quality_sum*worker[k-1][0];
        for(int i = k; i < n; i++) {
            pq.push(worker[i][1]);
            quality_sum+=worker[i][1]-pq.top();
            pq.pop();

            pay = min(pay, quality_sum*worker[i][0]);
        }
        return pay;
    }
};