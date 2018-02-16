//articulation point
//time complexit :  O(V+E)
//be in sorat peida mish ke agar raas morede nazar ma agar root bash ke age shakhe haye ziresh bishtar
// az 1 bashand ba hazf root etesal beyn onha ghat mishe  v halat dovom ine ke agar farzandan yek ras
// agar be pedaran ras yali nadashteh bashand v ras ham root nabashe pas ba hazf in ras ertebat ghat
//mishe.
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX1 10001

vector<int > arr[MAX1];
int visited[MAX1];
int low[MAX1];
int start[MAX1];
int parent[MAX1];
int artpoint[MAX1];//save articulation point
int counter=0;
void dfs1(int u){
		visited[u]=1;
	    low[u]=start[u]=++counter;
		int children=0;
		for(int i=0;i<arr[u].size();i++){
				int v=arr[u][i];
				if(!visited[v]){
						parent[v]=u;
						children++;
						dfs1(v);
						low[u]=min(low[u],low[v]);
						if(parent[u]==-1 && children>1){
								artpoint[u]=1;
							}
						if( parent[u]!=-1 && low[v]>=start[u]){
								artpoint[u]=1;
							}
				}else{
					if(parent[u] != v){
							low[u]=min(low[u],start[v]);
						}
				}
			}
	}
int main() {
		int T;cin>>T;
		for(int t=0;t<T;t++){
				int n;cin>>n;
				int m;cin>>m;
				for(int i=0;i<MAX1;i++){
						arr[i].clear();
					}
				memset(low,0, sizeof(low));
				memset(start,-1, sizeof(start));
				memset(visited,0, sizeof(visited));
				memset(parent,-1, sizeof(parent));
				memset(artpoint,0, sizeof(artpoint));
				counter=0;
				for(int i=0;i<m;i++){
						int u;cin>>u;
						int v;cin>>v;
						arr[u].push_back(v);
						arr[v].push_back(u);
					}
				for(int i=1;i<=n;i++){
						if(!visited[i]){
								dfs1(i);
							}
					}
				int sum=0;
				for(int i=1;i<=n;i++){
						if(artpoint[i])sum++;
					}
				cout<<"Case "<<t+1<<": "<<sum<<endl;

			}

		return 0;
	}

