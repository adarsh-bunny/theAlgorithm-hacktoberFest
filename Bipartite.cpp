#include <iostream>
#include <cstring>
using namespace std;
 
#define M 5 
#define N 5

int bipartite(int graph[M][N], int u, int seen[], int match[]);
int max(int graph[M][N]);

int main() 
{ 

    int graph[M][N] =    {{1, 1, 0, 0, 0}, 
                          {1, 0, 0, 0, 0}, 
                          {0, 1, 1, 0, 0}, 
                          {0, 0, 1, 1, 1}, 
                          {0, 0, 0, 0, 1}}; 
    cout<<"Maximum-bipartite-matching in a graph G = (V, E) is : "<< max(graph); 
  
    return 0; 
}

int bipartite(int graph[M][N], int u, int seen[], int match[]) 
{ 
	int v;
    for (v = 0; v < N; v++) 
    { 
        if (graph[u][v] && !seen[v]) 
        { 
            seen[v] = 1;  
            if (match[v] < 0 || bipartite(graph, match[v], 
                                     seen, match)) 
            { 
                match[v] = u; 
                return 1; 
            } 
        } 
    } 
    return 0; 
} 
  
int max(int graph[M][N]) 
{ 
    int match[N];
    int u;

    memset(match, -1, sizeof(match)); 
  
    int result = 0;  
    for (u = 0; u < M; u++) 
    { 
 
        int seen[N]; 
        memset(seen, 0, sizeof(seen)); 

        if (bipartite(graph, u, seen, match)) 
            result++; 
    } 
    return result; 
} 
