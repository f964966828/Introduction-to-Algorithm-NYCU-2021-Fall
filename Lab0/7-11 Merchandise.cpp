#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<vector<int>> shelf(N);
    while(Q--){
        int op, a, b;
        cin >> op >> a >> b;

        if(op == 1){
            shelf[a].push_back(b);
        }else if(op == 2){
            if(shelf[a].size() > b) cout << shelf[a][b] << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}