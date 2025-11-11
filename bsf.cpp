

#include<bits/stdc++.h>
using namespace std;
    //  BFS traversal techinique

void bfs(vector<string>& location, vector<vector<int>>& adjlist, int visited[]){
    queue<int> q;
    visited[0]=1;
    q.push(0);
    cout << "BFS traversal starting from:" << location[0] << endl;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << location[curr] << " ";
        for(int neighbour : adjlist[curr]){
            if(visited[neighbour]==0){
                visited[neighbour]=1;
                q.push(neighbour);
            }
        }
    }
    cout << endl;
} 

             // DFS Traversal technique

void dfs(vector<string>& location, int adjmatrix[][5], int visited[],int n){
    stack<int> s;
    visited[0]=1;
    s.push(0);
    cout << "DFS traversal from:" << location[0] << endl;

    while(!s.empty()){
        int curr = s.top();
        s.pop();
        cout << location[curr] << " ";
        for(int i=n-1; i>=0; i--){
            if(adjmatrix[curr][i]==1 && visited[i]==0){
              s.push(i);
              visited[i]=1;
            }
        }
    }
}
int main(){
     const int n = 5;
     vector<string> location ={"A","B","C","D","E"};
     vector<vector<int>> adjlist(n);
     int adjmatrix[n][n] = {0};

     int visited[n] = {0};

    
     adjlist[0].push_back(1);
     adjlist[1].push_back(0);
     adjlist[0].push_back(2);
     adjlist[2].push_back(0);
     adjlist[1].push_back(3);
     adjlist[3].push_back(1);
     adjlist[2].push_back(4);
     adjlist[4].push_back(2);
    
     adjmatrix[0][1] = adjmatrix[1][0] =1;
     adjmatrix[0][2] = adjmatrix[2][0] =1;
     adjmatrix[1][3] = adjmatrix[3][1] =1;
     adjmatrix[2][4] = adjmatrix[4][2] =1;
     
     bfs(location,adjlist,visited); 
     for(int i=0;i<n;i++){
        visited[i]=0;
     }
     dfs(location,adjmatrix,visited,n);
    return 0;
}
