#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V;
vector<pair<int, pair<int, int>>> k;
vector<int> parent;

int Find_Root(int x){
    if(parent[x]==x) return x;
    else return parent[x]=Find_Root(parent[x]);
}

int main(){
    int E, A, B, C;
    int i, cost=0;
    
    cin >> V >> E;
    for(i=0; i<E; i++){
        cin >> A >> B >> C;
        k.push_back(make_pair(C,make_pair(A,B)));
    }
    sort(k.begin(), k.end());
    
		parent.push_back(-1);
    for(i=1; i<=V; i++){
        parent.push_back(i);
    }
    
    for(i=0; i<E; i++){
        A=Find_Root(k[i].second.first);
        B=Find_Root(k[i].second.second);
        if(A!=B){
            parent[B]=A;
            cost+=k[i].first;
        }
    }
    
    cout << cost;
    return 0;
}