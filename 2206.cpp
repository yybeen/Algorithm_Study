#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[1000][1000];
int visited[1000][1000][2];
int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};

int bfs(){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0,0),1));
    visited[0][0][1]=1;
    
    while(!q.empty()){
        int a=q.front().first.first;
        int b=q.front().first.second;
        int wall=q.front().second;
        q.pop();
        
        if(a==N-1 && b==M-1){
            return visited[a][b][wall];
        }
        
        for(int i=0; i<4; i++){
            int ax=a+x[i];
            int by=b+y[i];
            
            if(ax<N && ax>=0 && by<M && by>=0){
                if(map[ax][by]=='1' && wall==1){
                    visited[ax][by][0]=visited[a][b][1]+1;
                    q.push(make_pair(make_pair(ax,by),0));
                }
                else if(map[ax][by]=='0' && visited[ax][by][wall]==0){
                    visited[ax][by][wall]=visited[a][b][wall]+1;
                    q.push(make_pair(make_pair(ax,by),wall));
                }
            }
        }
    }
    return -1;
}
int main(){
    string tmp;
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        cin >> tmp;
        for(int j=0; j<M; j++){
            map[i][j]=tmp[j];
        }
    }
    
    cout << bfs();
    return 0;
}