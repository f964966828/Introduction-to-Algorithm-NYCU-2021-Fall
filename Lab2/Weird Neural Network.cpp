#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
typedef long long ll;

const int mod = 1e9+7;
vector<ll> seq;
vector<vector<int>> input;

ll solve(int idx){
    ll result = 0;

    for(auto it: input[idx]){
        result = (result + solve(it)) % mod;
    }

    if(input[idx].size() == 0) result = 1;
    
    return (result * seq[idx]) % mod;
}

int main(){
    
    int n;
    cin >> n;

    seq.resize(n);
    for(int i=0; i<n; i++) cin >> seq[i];

    input.resize(n);

    int idx;
    for(int i=1; i<n; i++){
        cin >> idx;
        input[idx-1].push_back(i);
    }

    cout << solve(0) << endl;
}