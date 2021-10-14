#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt;
vector<vector<int>> area(N, vector<int>(M));
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

void dfs(int x, int y, int dir){
    if(area[x][y]==0){
        area[x][y]=-1;
        cnt++;
    }
    for(int i=0; i<4; i++){ //왼쪽부터 반시계방향
        int nextd=(dir+3-i)%4;
        int nextx=x+dr[nextd];
        int nexty=y+dc[nextd];
        if(nextx<0 || nextx>=N || nexty<0 || nexty>=M || area[nextx][nexty]==1) continue;
        if(area[nextx][nexty]==0) dfs(nextx,nexty,nextd);
    }
    int nextd=(dir+2)%4; //후진하는 경우
    int nextx=x+dr[nextd];
    int nexty=y+dc[nextd];

    if(area[nextx][nexty]==1){
        cout << cnt;
        return;
    }
    dfs(nextx,nexty,dir);
}

int main(){
    int N, M, r, c, d;
    int dr_left[4]={0,-1,0,1}, dc_left[4]={-1,0,1,0};
    int dr_back[4]={1,0,-1,0}, dc_back[4]={0,-1,0,1};
    cin >> N >> M;

    vector<vector<int>> area(N, vector<int>(M));
    cin >> r >> c >> d;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> area[i][j];
        }
    }

    int cnt=0;
    bool not_clean=false;
    while(1){
        if(area[r][c]==0) {//1번
            area[r][c]=-1;
            cnt++;
        }
        if(r+dr_left[d]>0 && r+dr_left[d]<N-1 && c+dc_left[d]>0 && c+dc_left[d]<M-1){
            if(area[r+dr_left[d]][c+dc_left[d]]==0){//2-a번
                r+=dr_left[d];
                c+=dc_left[d];
                if(d-1<0) d=3;
                else d-=1;
            }
            else{
                int d_copy=d;
                for(int i=0; i<3; i++){
                    if(d_copy-1<0) d_copy=3;
                    else d_copy-=1;
                    if(r+dr_left[d_copy]>0 && r+dr_left[d_copy]<N-1 && c+dc_left[d_copy]>0 && c+dc_left[d_copy]<M-1){
                        if(area[r+dr_left[d_copy]][c+dc_left[d_copy]]==0){
                            not_clean=true;
                            break;
                        }
                    }
                }
                if(!not_clean){//2-c번
                    d=d_copy;
                    r+=dr_back[d];
                    c+=dc_back[d];
                    if(r==N-1 || c==M-1 || r==0 || c==0) break; //2-d번
                    if(area[r][c]==1) break;
                }
                else{//2-b번
                    not_clean=false;
                    d=d_copy;
                    r+=dr_left[d];
                    c+=dc_left[d];
                }
            }
        }
        else {//2-b번
            if(d-1<0) d=3;
            else d-=1;
        }
    }
    cout << cnt;
    return 0;
}