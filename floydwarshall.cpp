#include <iostream>

using namespace std;
const int N=105;
const int MaxValue=INT32_MAX;//adad bezaram behtareh
int d1[N][N];
int pp[N][N];
void gnarateP() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (d1[i][j] != 0 && d1[i][j] != MaxValue) {
                pp[i][j] = i;
            } else {
                pp[i][j] = -1;
            }
        }
    }
}

void floydWarshall() {
    gnarateP();
    for (int k = 1; k <=N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (d1[i][k] == MaxValue || d1[k][j] == MaxValue) {
                    continue;
                }

                if (d1[i][j] > d1[i][k] + d1[k][j]) {
                    d1[i][j] = d1[i][k] + d1[k][j];
                    pp[i][j] = k;
                }

            }
        }
    }

}

void writeDis(int s,int t){
    if(pp[s][t]==-1){
        cout<<"Impossible"<<endl;
        return;
    }
    if(pp[s][t]==s){
        cout<<s<<" ";
        return ;
    }

    writeDis(s,pp[s][t]);
    writeDis(pp[s][t],t);
}
void genareteD(){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(i!=j) {
                d1[i][j] = MaxValue;
            }else{
                d1[i][j]=0;
            }
        }
    }
}
int main(){
    int T;cin>>T;
    for(int i=0;i<T;i++) {
        int n;cin>>n;
        int m;cin>>m;
        genareteD();
        for(int j=0;j<m;j++) {
            int u,v,w;
            cin >> u>>v>>w;
            d1[u][v]=min(w,d1[u][v]);
            d1[v][u]=min(w,d1[v][u]);
        }
        floydWarshall();
       /*
        writeDis(1,n);
        cout<<n<<endl;
        */
        cout<<"Case "<<i+1<<": ";
        int res=min(d1[1][n],d1[n][1]);
        if(res==MaxValue){
            cout<<"Impossible"<<endl;
        }else{
            cout<<res<<endl;
        }
    }
    return 0;
}

