#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int a, b;
    vector<int> v1, tmp;
    cin >> a >> b;

    for(int i=1; i<=a; i++){
        v1.push_back(i);
    }

    do{
        vector<int> v2;

        for(int m=0; m<b; m++){
            v2.push_back(v1[m]);
        }

        if(tmp!=v2){
        for(int k=0; k<b; k++){
            cout << v2[k] << " ";
        }
        cout << '\n';
        }

        tmp=v2;
    }while(next_permutation(v1.begin(),v1.end()));

    return 0;