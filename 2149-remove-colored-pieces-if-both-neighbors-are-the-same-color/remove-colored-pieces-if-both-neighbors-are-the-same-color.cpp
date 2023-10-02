class Solution {
public:
    bool winnerOfGame(string colors) {
        int Alice = 0, Bob = 0;
        for(int i=1;i<colors.size()-1;i++){
            if(colors[i-1] == colors[i] && colors[i] == colors[i+1] && colors[i] == 'A') Alice++;
            if(colors[i-1] == colors[i] && colors[i] == colors[i+1] && colors[i] == 'B') Bob++;
        }
        return Alice > Bob;
    }
};