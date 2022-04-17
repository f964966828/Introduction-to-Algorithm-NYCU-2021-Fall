#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> seq(n);
    for(int i=0; i<n; i++) cin >> seq[i];

    vector<vector<int>> info(4, vector<int>(n));
    vector<vector<int>> s(4);

    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            int idx = (j<2 ? i : n-1-i);
            int sign = (j%2 ? -1 : 1);
            auto it = lower_bound(s[j].begin(), s[j].end(), sign*seq[idx]);
            if(it != s[j].end()) *it = sign*seq[idx];
            else s[j].push_back(sign*seq[idx]);
            info[j][idx] = s[j].size();
        }
    }
    
    int ans = 0;
    for(int i=0; i<n; i++) ans = max(ans,max(info[0][i]+info[2][i],info[1][i]+info[3][i]));

    cout << ans-1;
}