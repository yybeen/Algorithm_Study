#include <iostream>
#include <vector>
using namespace std;

//vector[i]=int i's parent
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

int main(){
    int N, M, uf, a, b;

    scanf("%d %d", &N, &M);

    for(int i=0; i<=N; i++){
        parent.push_back(i);
    }
    
    for(int i=0; i<M; i++){
        scanf("%d %d %d", &uf, &a, &b);

        if(uf==0){
            Union(parent[a], parent[b]);
        }
        else if(uf==1){
            if(Find(parent[a])==Find(parent[b])) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}