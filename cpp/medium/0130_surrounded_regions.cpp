#include <bits/stdc++.h>
using namespace std;

class Checkers {
    private:
        #define ROWS(x) (x.size())
        #define COLS(x) (x[0].size())

        bool isVisited(vector<pair<int,int>> Visited, pair<int,int> pair) {
            for(auto p: Visited)
                if(p==pair) return true;
            return false;
        }

        void bfs(vector<vector<char>> &board, vector<pair<int,int>> &Visited, queue<pair<int,int>> &Q, int rows, int cols, int i, int j) {
            Q.push(make_pair(i,j));
            while(!Q.empty()) {
                int ci = Q.front().first;
                int cj = Q.front().second;

                if(ci==0 || ci==rows-1 || cj==0 || cj==cols-1) {
                    Q.pop();
                    continue;
                }

                if(ci+1<rows && !isVisited(Visited,make_pair(ci+1,cj)) && board[ci+1][cj]=='O')    { board[ci+1][cj] = 'X'; Q.push(make_pair(ci+1,cj)); }
                if(ci-1>=0   && !isVisited(Visited,make_pair(ci-1,cj)) && board[ci-1][cj]=='O')    { board[ci-1][cj] = 'X'; Q.push(make_pair(ci-1,cj)); }
                if(cj+1<rows && !isVisited(Visited,make_pair(ci,cj+1)) && board[ci][cj+1]=='O')    { board[ci][cj+1] = 'X'; Q.push(make_pair(ci,cj+1)); }
                if(cj-1>=0   && !isVisited(Visited,make_pair(ci,cj-1)) && board[ci][cj-1]=='O')    { board[ci][cj-1] = 'X'; Q.push(make_pair(ci,cj-1)); }

                board[ci][cj]='X';
                
                Visited.push_back(Q.front());
                Q.pop();
            }
        }

    public:
        void solve(vector<vector<char>>& board) {
            int rows = ROWS(board);
            int cols = COLS(board);

            queue<pair<int,int>> Q;
            vector<pair<int,int>> Visited;

            for(int i=1;i<rows-1;i++)
                for(int j=1;j<cols-1;j++) {
                    if(board[i][j]=='O')
                        bfs(board,Visited,Q,rows,cols,i,j);
                }
        }
};


int main() {
    auto start = chrono::steady_clock::now();
    vector<vector<char>> board = {
        {'X','X','X'},
        {'X','O','X'},
        {'X','X','X'},  
    };

    Checkers checker;
    checker.solve(board);

    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[0].size();j++) 
            cout << board[i][j] << "  ";
        cout << endl;
    }
    auto end = chrono::steady_clock::now();
    cout << "\ntime taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    return 0;
}
