class Solution {
public:
    int alpha[26] = {0};
    
    int find(int a){
        if(alpha[a] == a) return a;
        return alpha[a] = find(alpha[a]);
    }
    
    void Union(int a,int b){
        int pa = find(a);
        int pb = find(b);
        alpha[pa] = alpha[pb];
    }
    
    bool equationsPossible(vector<string>& equations){
        for(int i=0;i<26;i++) alpha[i] = i;
        for(int i=0;i<equations.size();i++){
            if(equations[i][1] == '='){
                int a = equations[i][0] - 97;
                int b = equations[i][3] - 97;
                Union(a,b);
            }
        }
        for(int i=0;i<26;i++){
            find(i);
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1] == '!' && alpha[equations[i][0] - 'a'] == alpha[equations[i][3] - 'a']) return false;
        }
        return true;
    }
};