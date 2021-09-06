#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
vector<vector<char>> map;
int alphabet[26]={0};
int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};
int max_cnt=0;

void dfs(int a, int b, int cnt){
    max_cnt=max(max_cnt,cnt);
    int k=(int)map[a][b]-65; //A=65
    alphabet[k]=1;

    for(int i=0; i<4; i++){
        int ax=a+x[i];
        int by=b+y[i];
        if(ax<R && ax>=0 && by<C && by>=0){
            int m=(int)map[ax][by]-65;
            if(alphabet[m]==0){
                dfs(ax, by, cnt+1);
                alphabet[m]=0;
            }
        }            
    }
}

int main(){
    string tmp;
    
    cin >> R >> C;
    map.resize(R,vector<char>(C));

    for(int i=0; i<R; i++){
        cin >> tmp;
        for(int j=0; j<C; j++){
            map[i][j]=tmp[j];
        }
    }

    dfs(0,0,1);
    cout << max_cnt;
    return 0;
}