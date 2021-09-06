#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    vector<int> seq(n);
    for(int i=0; i<n; i++){
        cin >> seq[i];
    }
    sort(seq.begin(), seq.end());
    cin >> x;

    int start=0, end=n-1, answer=0;

    while(start<end){
        if(seq[start]+seq[end]<x) start++;
        else if(seq[start]+seq[end]>x) end--;
        else if(seq[start]+seq[end]==x){
            answer++;
            end--;
        }
    }
    cout << answer;
    return 0;
}