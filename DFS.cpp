#include<iostream>
#include <vector>
using namespace std;

const int Gsize=50001;

int _color[Gsize], _p[Gsize] ,_d[Gsize] ,_f[Gsize] , _time,cycle[Gsize];
void DFS_visit(vector<int> G[], int u)
{
  _time++;
  _d[u]=_time;
  _color[u]=1;
  int v;
  for(int i=0;i<G[u].size();i++)
  {
    v=G[u][i];
    if(!_color[v])
    {
      _p[v]=u;
      DFS_visit(G, v);
    }else{
		if(_color[v]==1){
			cycle[u]++;
			int cur=_p[u];
			while(cur!=v){
				cycle[cur]++;
				cur=_p[cur];
			}
		}
	}
  }
  _color[u]=2;
  _time++;
  _f[u]=_time;
}
void DFS(vector<int>G[])
{
  for(int i=0;i<Gsize;i++)
  {
    _color[i]=0; _p[i]=0;cycle[i]=0;
  }
  _time=0;
  for(int i=0;i<Gsize;i++)
    if(!_color[i])
      DFS_visit(G, i);
}
int visited[Gsize];
int dfs1(int u,vector<int> g[]){
	if(visited[u]==1){
		return 0;
	}
	visited[u]=1;
	int sum=1;
	for(int i=0;i<g[u].size();i++){
		sum+=dfs1(g[u][i],g);
	}
	return sum;
}
int main()
{
	while(true){
		int n,m;
		cin>>n>>m;
		vector<int> g[50001]; 
		if(n==0 and m==0)break;
		for(int i=0;i<m;i++){
			int u;cin>>u;
			int v;cin>>v;
			u--;
			v--;
			g[u].push_back(v);
		}
		fill(visited,visited+n,0);
		DFS(g);
		for(int i=0;i<n;i++){
			int mx=-1;
			if(visited[i]==0&&cycle[i]>=2){
				mx=max(mx,dfs1(i,g);
			}
		}
		cout<<mx<<endl;
	}
  return 0;
}
