#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> cost;
vector<int> parent;

//Find Root Node
int Find(int node){
    if(parent[node]==node) return node;
    else{
        parent[node]=Find(parent[node]);
        return parent[node];
    }
}

//Union
void Union(int a, int b){
    int tmp1 = Find(a);
    int tmp2 = Find(b);

    if(tmp1 != tmp2) parent[tmp2] = tmp1;
}

bool SameRoot(int a, int b){
    int tmp1 = Find(a);
    int tmp2 = Find(b);

    if(tmp1 == tmp2) return true;
    else return false;
}

bool compare(vector<int>& a, vector<int>& b){
    return a[2]<b[2];
}

int main(){
    int N, M, a, b, c;
    int result=0;
    vector<int> tmp;
		//vector<int> tmp(3);

    scanf("%d", &N);
    scanf("%d", &M);    

    for(int i=0; i<M; i++){
        scanf("%d %d %d", &a, &b, &c);  
				//cin >> tmp[0] >> tmp[1] >> tmp[2];     
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        cost.push_back(tmp);
        tmp.clear();
    }

    parent.push_back(-1);
    
    for(int i=1; i<=N; i++){
        parent.push_back(i);
    }

    sort(cost.begin(), cost.end(), compare);

    for(int i=0; i<M; i++){
        if(!SameRoot(cost[i][0], cost[i][1])){
            Union(cost[i][0], cost[i][1]);
            result += cost[i][2];
        }
    }

    printf("%d", result);
    return 0;
}