// 섬의 개수(DFS)
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int map[50][50],visit[50][50];
int dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,1,1,1,0,-1,-1,-1}; //이동할 좌표값들
int w,h;
void dfs(int y,int x){
    for(int i=0;i<8;i++){
        int nextX=x+dx[i];
        int nextY=y+dy[i];
        if(nextX<0||nextY<0||nextX>=w||nextY>=h)continue; 
        if(!visit[nextY][nextX]&&map[nextY][nextX]){ 
            visit[nextY][nextX]=1;
            dfs(nextY,nextX);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    while(1){
        int cnt=0;
        cin>>w>>h;
        if(!w&&!h)break; 
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>map[i][j];
            }
        }
        for(int i=0;i<h;i++){ 
            for(int j=0;j<w;j++){
                if(!visit[i][j]&&map[i][j]){
                    visit[i][j]=1;
                    dfs(i,j);
                    cnt++; 
                }
            }
        }
        cout<<cnt<<"\n";
        memset(visit,0,sizeof(visit)); 
    }
}
