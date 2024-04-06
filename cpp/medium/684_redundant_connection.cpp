# include <bits/stdc++.h>
using namespace std;

class Redundant {
private:
    bool isAlreadyInQueue(queue<int> Q, int target) {
        while(!Q.empty()) {
            if(Q.front()==target)
                return true;
            Q.pop();
        }
        return false;
    }
    
    bool isVisited(vector<int> Visited, int target) {
        vector<int>::iterator it = Visited.begin();
        while(it!=Visited.end()) {
            if(*it==target)
                return true;
            it+=1;
        }
        return false;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> redundant_connection(2,-1);
        
        unordered_map<int,vector<int>> connections;
        vector<int> Visited;
        queue<int> Q;
        
        // get the complete connections list
        for(auto edge: edges) 
            connections[edge[0]].push_back(edge[1]);
        
        // push first bit into queue
        Q.push(edges[0][0]);
        
        // perform bfs
        while(!Q.empty()) {
            
            // update local variable
            int n = Q.front();
            
            // traverse adjacent edges and keep in check the adjacent
            // is neither:
            //     1. already visited
            //     1. already in queue
            for(auto adj: connections[n]) {
                if(!isVisited(Visited,adj))
                    if(!isAlreadyInQueue(Q,adj))
                        Q.push(adj);
                    else {
                        // the redundant conn is: [ n, adj ]
                        redundant_connection = {n,adj};
                        break;
                    }
            }
            
            // pop from queue and add to visited
            Visited.push_back(Q.front());
            Q.pop();
            
        }
        
        return redundant_connection;
        
    }
};

int main() {
    vector<vector<int>> edges = { {1,2},{2,3},{3,4},{1,4},{1,5} };

    Redundant x;

    auto start = chrono::steady_clock::now();
    vector<int> result = x.findRedundantConnection(edges);
    auto end = chrono::steady_clock::now();

    cout << result[0] << ", " << result[1];
    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms" << endl;
    return 0;
}