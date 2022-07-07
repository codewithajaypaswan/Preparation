class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        int adjA = 0, adjB = 0;
        for(char c:colors) {
            if(c == 'A') {
                adjA++;
                if(adjA >= 3) a++;
                adjB = 0;
            }
            else {
                adjB++;
                if(adjB >= 3) b++;
                adjA = 0;
            }
        }
        return a > b;
    }
};