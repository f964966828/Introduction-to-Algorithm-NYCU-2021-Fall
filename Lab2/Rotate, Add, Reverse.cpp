#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solve(int n){
    vector<int> seq;

    if(n == 0){
        seq.push_back(1);
        return seq;
    }

    vector<int> tmp = solve(n-1);
    for(int i=0; i<tmp.size(); i++) seq.push_back(tmp[i] + pow(2, n-1));
    for(int i=tmp.size()-1; i>=0; i--) seq.push_back(tmp[i]);

    return seq;
}

int main(){
    int n;
    cin >> n;

    vector<int> seq = solve(n);

    for(auto it: seq) cout << it << " ";
}