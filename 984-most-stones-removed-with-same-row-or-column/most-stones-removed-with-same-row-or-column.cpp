class Solution {
public:
    int parent[1001];

    int find(int i) { 
        if (parent[i] == i) return i;
        else return parent[i] = find(parent[i]);
    } 

    void Union(int i, int j) { 
        int irep = find(i);
        int jrep = find(j);
        if(irep <= jrep) parent[jrep] = irep;
        else parent[irep] = jrep;
    }

    int removeStones(vector<vector<int>>& stones) {
        for(int i=0;i<1001;i++) parent[i] = i;

        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) Union(i, j);
            }
        }

        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) Union(i, j);
            }
        }

        set<int> s;

        for(int i=0;i<stones.size();i++) s.insert(parent[i]);

        // for(int i=0;i<stones.size();i++) cout<<parent[i]<<endl;

        return stones.size() - s.size();
    }

};