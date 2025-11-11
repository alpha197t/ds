#include <bits/stdc++.h>
using namespace std;

#define MAX 10


int findMinKey(int key[], bool visited[], int V) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}


int minDeliveryTime(int graph[MAX][MAX], int V) {
    int parent[MAX];    
    int key[MAX];       
    bool visited[MAX];  

  
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    
    key[0] = 0;
    parent[0] = -1;

    
    for (int count = 0; count < V - 1; count++) {
        int u = findMinKey(key, visited, V);
        visited[u] = true;

        
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    
    int totalTime = 0;
    cout << "\nOptimal Delivery Routes:\n";
    for (int i = 1; i < V; i++) {
        cout << "From location " << parent[i] << " to " << i
             << " -> Time: " << graph[i][parent[i]] << " units" << endl;
        totalTime += graph[i][parent[i]];
    }

    return totalTime;
}

int main() {
    int V;
    cout << "Enter number of locations (including pizza shop): ";
    cin >> V;

    int graph[MAX][MAX];
    cout << "\nEnter time matrix (0 if no direct connection):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int totalTime = minDeliveryTime(graph, V);
    cout << "\nMinimum total delivery time: " << totalTime << " units\n";

    return 0;
}
