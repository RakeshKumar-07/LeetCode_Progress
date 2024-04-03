class Solution {
public:
    bool searchword(vector<vector<char>>& board, string word, vector<vector<int>>& state, int i, int j, int n, int w){
        if(n==w){
            return true;
        }
        if(i>=0 && i+1<board.size() && j>=0 && j<board[0].size() && board[i+1][j]==word[w] && state[i+1][j]==1){
            state[i+1][j] = -1;
            if(searchword(board,word,state,i+1,j,n,w+1)){
                return true;
            }
            state[i+1][j] = 1;
        }
        if(i-1>=0 && i<board.size() && j>=0 && j<board[0].size() && board[i-1][j]==word[w] && state[i-1][j]==1){
            state[i-1][j] = -1;
            if(searchword(board,word,state,i-1,j,n,w+1)){
                return true;
            }
            state[i-1][j] = 1;
        }
        if(i>=0 && i<board.size() && j-1>=0 && j<board[0].size() && board[i][j-1]==word[w] && state[i][j-1]==1){
            state[i][j-1] = -1;
            if(searchword(board,word,state,i,j-1,n,w+1)){
                return true;
            }
            state[i][j-1] = 1;
        }
        if(i>=0 && i<board.size() && j>=0 && j+1<board[0].size() && board[i][j+1]==word[w] && state[i][j+1]==1){
            state[i][j+1] = -1;
            if(searchword(board,word,state,i,j+1,n,w+1)){
                return true;
            }
            state[i][j+1] = 1;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word){
        int n = word.size();
        vector<vector<int>> state(board.size(),vector<int>(board[0].size(),1));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == word[0]){
                    state[i][j] = -1;
                    if(searchword(board,word,state,i,j,n,1))
                        return true;
                }
                state[i][j] = 1;
            }
        }
        return false;
    }
};