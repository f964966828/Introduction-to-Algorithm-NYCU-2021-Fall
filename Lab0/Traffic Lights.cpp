#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int L, n;
    cin >> L >> n;
    
    set<int> lights;
    map<int,int> intervals;
    lights.insert(0);
    lights.insert(L);
    intervals[L]++;

    int num;
    while(n--){
        cin >> num;
        
        lights.insert(num);

        auto pos = lights.find(num);
        auto prev = --pos;
        auto next = (++++pos)--;

        intervals[*next - *pos]++;
        intervals[*pos - *prev]++;
        intervals[*next - *prev]--;
        if(!intervals[*next - *prev]) intervals.erase(*next - *prev);
        
        auto ans = intervals.end();
        cout << (*(--ans)).first/2 << endl;
    }

    return 0;
}