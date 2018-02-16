	#include <iostream>
	#include <cstring>
	#include <vector>
	 
	using namespace std;	 	 
	int arr[202];
	vector<pair<int,int> > g;
	const long long  ms1 =1000000;
	long long int dis[202];
	void belman(int st,int num){
	    memset(dis,ms1,sizeof(dis));
	    dis[st]=0;
	    for(int i=1;i<num;i++){
	        for(int j=0;j<g.size();j++){
	            int u=g[j].first;
	            int v=g[j].second;
	 
	            long long int tmp=(arr[v]-arr[u]);
	            if(dis[u]!=ms1 && dis[v]>dis[u]+(tmp)){
	                    dis[v]=dis[u]+(tmp);
	            }
	        }
	    }
	        int i;
	        for(i=0;i<g.size();i++){
	            int u=g[i].first;
	            int v=g[i].second;
	            long long int tmp=(arr[v]-arr[u])*(arr[v]-arr[u])*(arr[v]-arr[u]);
	            if(dis[v]==-ms1)continue;
	            if(dis[u]!=ms1 && dis[v]>dis[u]+(tmp)){
	                dis[v]=-ms1;
	                //detect cycle
	            }
	        }
	}
	 
	int main() {
	   // freopen("test.in","w",stdout);
	    int T;cin>>T;
	    for(int j=0;j<T;j++){
	        g.clear();
	        int n;cin>>n;
	        for(int i=1;i<=n;i++){
	            int tmp;cin>>tmp;
	            arr[i]=tmp;
	        }
	        int m;cin>>m;
	        for(int i=0;i<m;i++){
	            int u;cin>>u;
	            int v;cin>>v;
	            g.push_back(make_pair(u,v));
	        }
	        int q;cin>>q;
	        belman(1,n);
	        cout<<"Case "<<j+1<<":\n";
	        for(int i=0;i<q;i++){
	            int tmp;cin>>tmp;
	            if(dis[tmp]>2000000 || dis[tmp]<3){
	                cout<<"?"<<endl;
	            }else{
	                cout<<dis[tmp]<<endl;
	            }
	        }
	    }
	 
	    return 0;
	}