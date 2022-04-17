#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    multiset<int> q1, q2, q3;

    int cnt = 0, num;
    while(cin >> num){
        if(num == 0) break;
    
        int r = ++cnt%4;
        q3.insert(num);
		q2.insert(*q3.begin()); q3.erase(q3.begin());
		q1.insert(*q2.begin()); q2.erase(q2.begin());

        if(r != 2) q2.insert(*(--q1.end())), q1.erase(--q1.end());
        else q3.insert(*(--q2.end())), q2.erase(--q2.end());

		double ans;
        if(r == 0 || r == 1) ans = (cnt == 1 ? 0 : ((*q3.begin())+(*(--q2.end()))) / 2.0 - ((*(--q1.end()))+(*q2.begin())) / 2.0);
        else ans = (*q3.begin()) - (*(--q1.end()));

		if(ceil(ans) == ans) cout << int(ans) << "\n";
        else cout << fixed << setprecision(1) << ans << "\n";        
    }
}