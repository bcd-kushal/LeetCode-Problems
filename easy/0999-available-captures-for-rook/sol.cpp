#include <vector>
using namespace std;

class Solution {
private:
    int captureHorizontally(vector<vector<char>> &board, int start, int row, int dir) {
        if(dir < 0) {
            for(int i=start;i>=0;i-=1)
                if(board[row][i] == 'B')        return 0;
                else if(board[row][i] == 'p')   return 1;
        } 
        else {
            for(int i=start;i<8;i+=1)
                if(board[row][i] == 'B')        return 0;
                else if(board[row][i] == 'p')   return 1;
        }

        return 0;
    }
    
    int captureVertically(vector<vector<char>> &board, int start, int col, int dir) {
        if(dir < 0) {
            for(int i=start;i>=0;i-=1)
                if(board[i][col] == 'B')        return 0;
                else if(board[i][col] == 'p')   return 1;
        } 
        else {
            for(int i=start;i<8;i+=1)
                if(board[i][col] == 'B')        return 0;
                else if(board[i][col] == 'p')   return 1;
        }

        return 0;
    }

public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rookRow = 0, rookCol = 0;
        for(int i=0;i<8;i+=1)
            for(int j=0;j<8;j+=1)
                if(board[i][j] == 'R') {
                    rookRow = i;
                    rookCol = j;
                    break;
                }

        int captures = 0;

        captures += captureVertically(board,rookRow+1,rookCol,1);
        captures += captureVertically(board,rookRow-1,rookCol,-1);
        captures += captureHorizontally(board,rookCol+1,rookRow,1);
        captures += captureHorizontally(board,rookCol-1,rookRow,-1);
       
        return captures;
    }
};