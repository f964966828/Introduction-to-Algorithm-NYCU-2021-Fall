#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    int tmp;
    map<int,int> mp;
    for(int i=0; i<n; i++){
        cin >> tmp;
        mp[tmp] = i+1;
    }

    for(int i=0; i<m; i++){
        cin >> tmp;
        cout << (mp[tmp] ? mp[tmp]-1 : -1) << endl;
    }

    return 0;
}