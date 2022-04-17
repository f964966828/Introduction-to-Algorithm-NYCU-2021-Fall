#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Q;
    cin >> Q;


    map<int,map<int,int>> shelves;
    while(Q--){
        int op, a, x;
        cin >> op;

        if(op == 1){
            cin >> a >> x;
            shelves[a][x]++;
        }else{
            cin >> a;
            if(shelves[a].size()){
                auto it = shelves[a].begin();
                cout << (*it).first << "\n";
                if(--(*it).second == 0) shelves[a].erase(it);
            }else{
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}