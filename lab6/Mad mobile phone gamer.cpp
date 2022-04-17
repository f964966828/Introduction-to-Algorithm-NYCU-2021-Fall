#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> pii;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dis(n, vector<int>(n, 1e15));
    int from, to, cost;
    for(int i=0; i<n; i++) dis[i][i] = 0;
    for(int i=0; i<m; i++){
        cin >> from >> to >> cost;
        dis[from][to] = min(dis[from][to], cost);
    }
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> from >> to;
        cout << (dis[from][to] == 1e15 ? -1 : dis[from][to]) << "\n";
    }

    return 0;
}