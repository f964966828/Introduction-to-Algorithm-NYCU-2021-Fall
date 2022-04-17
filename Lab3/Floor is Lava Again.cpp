#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<double> c(n), p(n); 
    for(int i=0; i<n; i++) cin >> c[i] >> p[i];

    priority_queue<pair<double,int>> pq;
    for(int i=0; i<n; i++) pq.push({c[i]/(p[i]+1), i});
    
    vector<int> ppl(n);
    while(k--){
        int idx = pq.top().second;
        pq.pop();
        ppl[idx]++;
        pq.push({c[idx]/(p[idx]+ppl[idx]+1)*(ppl[idx]+1) - c[idx]/(p[idx]+ppl[idx])*ppl[idx], idx});
    }

    double sum = 0.0;
    for(int i=0; i<n; i++){
        if(ppl[i]) sum += c[i]/(p[i]+ppl[i])*ppl[i];
    }
    cout << fixed << setprecision(10) << sum << endl;
}