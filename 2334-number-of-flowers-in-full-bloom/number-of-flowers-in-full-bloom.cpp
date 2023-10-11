class Solution {
public:
    int binarySearch(int l, int h, vector<int> &v, int target){
        if(l>h) return h;
        int mid = l + (h-l)/2;
        if(v[mid] > target) return binarySearch(l, mid-1, v, target);
        return binarySearch(mid+1, h, v, target);
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> s, e;
        for(int i=0;i<flowers.size();i++){
            s.push_back(flowers[i][0]);
            e.push_back(flowers[i][1]);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        
        vector<int> ans;

        for(int i=0;i<people.size();i++){
            int bloom = binarySearch(0, s.size() - 1, s, people[i]);
            int dead = binarySearch(0, e.size() - 1, e, people[i]-1);
            ans.push_back(bloom - dead);
        }
        return ans;
    }
};