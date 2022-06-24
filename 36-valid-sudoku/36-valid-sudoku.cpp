class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int box1[10][10] = {0}, box2[10][10] = {0}, box3[10][10] = {0};
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int k = i/3*3 + j/3;
                    if(box1[i][num] || box2[j][num] || box3[k][num]) return false;
                    box1[i][num] = box2[j][num] = box3[k][num] = num;
                }
            }
        }
        return true;
    }
};