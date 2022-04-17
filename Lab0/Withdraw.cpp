#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    queue<pii> q;

    int id, potential;
    for(int i=0; i<N; i++){
        cin >> id >> potential;
        q.push({id,potential});
    }

    while(!q.empty()){
        cout << q.front().first << "\n";
        q.front().second--;

        if(q.front().second) q.push(q.front());
        q.pop();
    }

    return 0;
}