#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<pair<char, int>>> apart;
int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};
int cnt;

void dfs(int a, int b){
    cnt++;
    apart[a][b].second=1;
    
    for(int i=0; i<4; i++){
        int ax=a+x[i];
        int by=b+y[i];
        if(ax<N && ax>=0 && by<N && by>=0){
            if(apart[ax][by].first=='1' && apart[ax][by].second==0) dfs(ax, by);
        }            
    }
}
int main(){
    string tmp;
    vector<int> complex;
    cin >> N;
    apart.resize(N,vector<pair<char, int>>(N));
    for(int i=0; i<N; i++){
        cin >> tmp;
        for(int j=0; j<N; j++){
            apart[i][j]=make_pair(tmp[j],0);
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(apart[i][j].first=='1' && apart[i][j].second==0){
                cnt=0;
                dfs(i,j);
                complex.push_back(cnt);
            }
        }
    }
    
    sort(complex.begin(), complex.end());
    int num=complex.size();
    cout << num << '\n';
    for(int i=0; i<num; i++){
        cout << complex[i] << '\n';
    }
    return 0;
}