class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ans = 0;
        queue<int> q;
        for(int i=0;i<students.size();i++) q.push(students[i]);
        for(int i=0;i<sandwiches.size();i++){
            int b = q.size();
            while(q.size() > 0 && b--){
                int t = q.front();
                q.pop();
                if(t == sandwiches[i]) break;
                q.push(t);
            }
            if(b == -1) return q.size();
        }
        return 0;
    }
};