#include <iostream>
#include <string>
using namespace std;

int main(){
    string s, tmp;
    int sum, t;
    bool minus=false;
    cin >> s;
    sum=0;
    for(int i=0; i<=s.size(); i++){
        if(s[i]=='+' || s[i]=='-' || i==s.size()){
            t=stoi(tmp);
            if(minus==false){
              sum+=t;
            }
            else{
                sum-=t;
            }
            tmp.clear();
            if(s[i]=='-') {
                minus=true;
            }
        }
        else{
            tmp.push_back(s[i]);
        }
    }
    cout << sum;

    return 0;
}