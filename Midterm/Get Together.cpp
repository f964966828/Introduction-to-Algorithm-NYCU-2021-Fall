#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> l(n), v(n);
    for(int i=0; i<n; i++) cin >> l[i] >> v[i];

    double left = 0, right = 1e9;
    for(int i=0; i<100; i++){
        double mid = (left+right)/2;
        double tmp_left = -1e9, tmp_right = 1e9;
        for(int j=0; j<n; j++){
            tmp_left = max(tmp_left, l[j] - mid*v[j]);
            tmp_right = min(tmp_right, l[j] + mid*v[j]);
        }
        if(tmp_left <= tmp_right) right = mid;
        else left = mid;
    }
     
    cout << fixed << setprecision(6) << (left+right)/2 << endl;

}