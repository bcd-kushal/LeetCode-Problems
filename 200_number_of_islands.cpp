#include<bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
        stack<pair<int,int>> st;
        int total_islands=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='0')
                    continue;

                total_islands+=1;
                st.push(make_pair(i,j));
                while(!st.empty()){
                    pair<int,int> x = st.top();
                    st.pop();

                    if(grid[x.first][x.second]=='0')
                        continue;

                    grid[x.first][x.second]='0';
                    if(x.first+1<grid.size() && grid[x.first+1][x.second]=='1')
                        st.push(make_pair(x.first+1,x.second));
                    if(x.second+1<grid[0].size() && grid[x.first][x.second+1]=='1')
                        st.push(make_pair(x.first,x.second+1));
                    if(x.first-1>=0 && grid[x.first-1][x.second]=='1')
                        st.push(make_pair(x.first-1,x.second));
                    if(x.second-1>=0 && grid[x.first][x.second-1]=='1')
                        st.push(make_pair(x.first+1,x.second));
                }
            }
        }

        return total_islands;
    }
    
    
