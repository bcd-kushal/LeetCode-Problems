#include <bits/stdc++.h>
using namespace std;

class Islands {
    private:
        #define ROWS(x) (x.size())
        #define COLS(x) (x[0].size())

        bool isVisited(vector<pair<int,int>> Visited, pair<int,int> pair) {
            for(const auto x: Visited)
                if(x==pair)
                    return true;
            return false;
        }

        void bfs(vector<vector<int>> map, vector<pair<int,int>> &Visited, queue<pair<int,int>> &Q, int curr_row, int curr_col, int rows, int cols) {
            Q.push(make_pair(curr_row,curr_col));

            while(!Q.empty()) {
                curr_row = Q.front().first;
                curr_col = Q.front().second;

                // explore adjacent edges
                if(curr_row+1<rows && map[curr_row+1][curr_col]==1 && !isVisited(Visited,make_pair(curr_row+1,curr_col)))
                    Q.push(make_pair(curr_row+1,curr_col));
                if(curr_row-1>=0   && map[curr_row-1][curr_col]==1 && !isVisited(Visited,make_pair(curr_row-1,curr_col)))
                    Q.push(make_pair(curr_row+1,curr_col));
                if(curr_col+1<cols && map[curr_row][curr_col+1]==1 && !isVisited(Visited,make_pair(curr_row,curr_col+1)))
                    Q.push(make_pair(curr_row,curr_col+1));
                if(curr_col-1>=0   && map[curr_row][curr_col-1]==1 && !isVisited(Visited,make_pair(curr_row,curr_col-1)))
                    Q.push(make_pair(curr_row,curr_col-1));


                // remove this cell from Q
                Visited.push_back(Q.front());
                Q.pop();
            }
        }


    public:
        int totalIslands(vector<vector<int>> map) {
            const int rows = ROWS(map);
            const int cols = COLS(map);

            if(rows<1 || cols<1)    
                return 0;

            queue<pair<int,int>> Q;
            vector<pair<int,int>> Visited;

            int curr_row = 0;
            int curr_col = 0;
            int islands = 0;

            for(int i=0;i<rows;i++)
                for(int j=0;j<cols;j++) {
                    if(map[i][j]==1 && !isVisited(Visited,make_pair(i,j))) {
                        cout << "[" << i << "..." << j << "]" << endl;
                        bfs(map,Visited,Q,i,j,rows,cols);
                        islands += 1;
                    }
                }

            

            return islands;

        }
};



int main() {
    auto start = chrono::steady_clock::now();
    //---------------------------------------------------------------

    vector<vector<int>> map = {
        {1,1,1,0,1,1},
        {1,0,0,0,0,0},
        {1,1,0,1,1,1},
        {0,0,0,0,1,0},
    };
    
    Islands isl;
    cout << isl.totalIslands(map) << " islands found.";


    //---------------------------------------------------------------
    auto end = chrono::steady_clock::now();
    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    return 0;
}