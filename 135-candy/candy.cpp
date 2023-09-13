class Solution {
public:
    int candy(vector<int>& ratings) {
        // cout<<ratings.size()<<endl;
        int ans = ratings.size(), mini = INT_MAX;
        vector<int> rat(ratings.size(), 1);
        map<int, vector<int>> m;
        for(int i=0;i<ratings.size();i++){
            m[ratings[i]].push_back(i);
            mini = min(mini, ratings[i]);
        }
        for(auto i:m){
            if(i.first != mini){
                for(int j=0;j<i.second.size();j++){
                    if(i.second[j] > 0 && i.second[j] < ratings.size()-1){
                        if(ratings[i.second[j]] > ratings[i.second[j]+1] && ratings[i.second[j]] > ratings[i.second[j]-1]){
                            ans += abs(rat[i.second[j]] - (max(rat[i.second[j]+1], rat[i.second[j]-1]) + 1));
                            rat[i.second[j]] = max(rat[i.second[j]+1], rat[i.second[j]-1]) + 1;
                        }
                        else if(ratings[i.second[j]] > ratings[i.second[j]+1]){
                            ans += abs(rat[i.second[j]] - (rat[i.second[j]+1] + 1));
                            rat[i.second[j]] = rat[i.second[j]+1] + 1;
                        }
                        else if(ratings[i.second[j]] > ratings[i.second[j]-1]){
                            ans += abs(rat[i.second[j]] - (rat[i.second[j]-1] + 1));
                            rat[i.second[j]] = rat[i.second[j]-1] + 1;
                        }
                    }
                    else if(i.second[j] == 0){
                        if(ratings[i.second[j]] > ratings[i.second[j]+1]){
                            ans += abs(rat[i.second[j]] - (rat[i.second[j]+1] + 1));
                            rat[i.second[j]] = rat[i.second[j]+1] + 1;
                        }
                    }
                    else if(i.second[j] == ratings.size() - 1){
                        if(ratings[i.second[j]] > ratings[i.second[j]-1]){
                            ans += abs(rat[i.second[j]] - (rat[i.second[j]-1] + 1));
                            rat[i.second[j]] = rat[i.second[j]-1] + 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};