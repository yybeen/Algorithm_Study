#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

queue<pair<string, int>> q;
int visit[10000000][11]={0};

int main(){
    int K, result;
    int max_n=0;
    string s, p_str;

    cin >> s >> K;

    q.push(make_pair(s,0));

    while(!q.empty()){
        pair<string, int> p = q.front(); 
        q.pop();
        if(p.second==K){
            max_n = max(max_n, stoi(p.first));
        }
        else{
            p_str=p.first;
            for(int i=0; i<p_str.size()-1; i++){
                for(int j=i+1; j<p_str.size(); j++){
                    swap(p_str[i], p_str[j]);
                    if(p_str[0]=='0' || visit[stoi(p_str)][p.second+1]==1){
                        swap(p_str[i], p_str[j]);
                    }
                    else{
                        q.push(make_pair(p_str, p.second+1));
                        visit[stoi(p_str)][p.second+1]=1;
                        swap(p_str[i], p_str[j]);
                    }
                }
            }
        }
    }

    if(max_n==0) cout << "-1";
    else cout << max_n;
    return 0;
}