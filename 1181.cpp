#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b){
    if(a.size() < b.size()){
        return true;
    }
    else if(a.size()==b.size()){
        if(a<b) {
            return true;
        }
        else{
            return false;
        }
    }
    else {
        return false;
    }
}

int main(){
    int N;
    string v;
    cin >> N;

    vector<string> voca;

    for(int i=0; i<N; i++){
        cin >> v;
        voca.push_back(v);
    }

    sort(voca.begin(), voca.end(), cmp);
    
    for(int k=0; k<N; k++){
        if(k!=0){
          if(voca[k-1]==voca[k]) continue;
        }
        cout << voca[k] << '\n';
    }

    return 0;
}