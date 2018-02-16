//bridge 
//time complexit:O(V+E)
//mesl halat dovom articulation point hast

	#include <iostream>
	#include<stdio.h>
	#include <vector>
	#include <cstring>
	#include <algorithm>	 
	using namespace std;
    vector<int> arr[10004];
	vector<pair<int ,int> > res;
	int visited[10004];
	int start[10004];
	int parent[10004];
	int counter=0;
	int low[10004];
	void bridge(int u){
	    visited[u]=true;
	    start[u]=++counter;
	    low[u]=start[u];
	    for(int i=0;i<arr[u].size();i++){
	        int v=arr[u][i];
	        if(!visited[v]){
	            parent[v]=u;
	            bridge(v);
	 
	            if(low[v]> start[u]){
	                if(u<=v) {
	                    res.push_back(make_pair(u, v));
	                }else{
	                    res.push_back(make_pair(v, u));
	                }
	            }
	            low[u]=min(low[u],low[v]);
	 
	        }else{
	            if(v!=parent[u]) {
	                low[u] = min(low[u], start[v]);
	            }
	        }
	    }
	 
	}
	int main() {
	    //freopen ("myfile.txt","w",stdout);
	    int T;cin>>T;
	    for(int t=0;t<T;t++){
	        int n;cin>>n;
	        for(int i=0;i<10004;i++){
	            arr[i].clear();
	        }
	        res.clear();
	        counter=0;
	        memset(visited,0, sizeof(visited));
	        memset(start,-1, sizeof(start));
	        memset(parent,-1 ,sizeof(parent));
	        memset(low,0, sizeof(low));
	        for(int i=0;i<n;i++){
	            int u,v,n2;
	            scanf("%d (%d) ",&u,&n2);
	            for(int j=0;j<n2;j++){
	                scanf("%d",&v);
	                arr[u].push_back(v);
	            }
	        }
	        for(int i=0;i<n;i++){
	            if(!visited[i]){
	                bridge(i);
	            }
	        }
	        sort(res.begin(),res.end());
	        printf("Case %d:\n",t+1);
	        printf("%d critical links\n",res.size());
	        for(int i=0;i<res.size();i++){
	            printf("%d - %d\n",res[i].first,res[i].second);
	}
	        }
	    }
	 
	    return 0;