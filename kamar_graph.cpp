#include <queue>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 100 * 1000 + 10;
const int INF = 1<<30;     

bool mark[MAXN];
vector<int> adj[MAXN];      
int depth[MAXN];            
int parent[MAXN];          

int n;       
int m;       

int bfs(int v, int max_depth) {
    queue<int> q;                
    memset(depth, -1, sizeof(depth));
    memset(mark, 0, sizeof(mark));
    mark[v] = 1;
    depth[v] = 0;
    q.push(v);

    while(q.size()) {
        v = q.front();
        q.pop();

	if (depth[v] == max_depth)     
	    return INF;

        for(unsigned int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];

            if (mark[u] == 1 && u != parent[v])      
                return (depth[v]+1) + depth[u];      

            mark[u] = 1;
            q.push(u);
            parent[u] = v;
            depth[u] = depth[v] + 1;      
        }

    }

    return INF;
}

int find_min_cycle()
{
    int dist = INF;              
    
    for (int i = 0; i < n; i++)
        dist = min(dist, bfs(i, dist/2));
    
    return dist;
}


void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        adj[--v].push_back(--u);
        adj[u].push_back(v);
    }
}

int main()
{
    input();   
    cout << find_min_cycle() << endl;
}
