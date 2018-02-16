#include <iostream>
using namespace std;
void filllsp(string pat,int* lsp){
    int len=0;
    int i=1;
    lsp[0]=0;
    while (i<pat.size()){
        if(pat[len]-pat[i]==0){
            len++;
            lsp[i]=len;
            i++;
        }else{
            if(len==0){
                lsp[i]=0;
                i++;
            }else{
                len=lsp[len-1];
            }
        }
    }
}
int kmpalg(string txt,string pat){
    int N=pat.size();
    int lsp[N];
    int i=0;
    int j=0;
    int sum=0;
    filllsp(pat,lsp);
    while(i<txt.size()){
        if(txt[i]-pat[j]==0){
            j++;
            i++;
        }
        if(j==N){
            sum++;
            j=lsp[j-1];
        }else{
            if(i<txt.size() && pat[j]!=txt[i]){
                if(j==0){
                    i++;
                }else{
                    j=lsp[j-1];
                }
            }
        }
    }
    return sum;
}
int main(){
    int T;cin>>T;
    for(int i=0;i<T;i++){
        string s;cin>>s;
        string pat;cin>>pat;
        cout<<"Case "<<i+1<<": "<<kmpalg(s,pat)<<endl;
    }
    return 0;
}
