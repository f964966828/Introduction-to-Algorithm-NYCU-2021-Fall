#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, m, s;
        cin >> n >> m >> s;
        
        vector<vector<int>> adj_list(n);
        int a, b;
        for(int i=0; i<m; i++){
            cin >> a >> b;
            adj_list[a-1].push_back(b-1);
            adj_list[b-1].push_back(a-1);
        }

        vector<int> cops;
        set<int> hideouts;
        int x, y, tmp;
        cin >> x;
        for(int i=0; i<x; i++){
            cin >> tmp;
            cops.push_back(tmp-1);
        }
        cin >> y;
        for(int i=0; i<y; i++){
            cin >> tmp;
            hideouts.insert(tmp-1);
        }
        vector<int> visited_self(n), visited_cops(n), bfs_self(1, s-1), bfs_cops(cops);
        bool find = false, finish = false;
        while(!finish){

            if(bfs_self.size() == 0 && bfs_cops.size() == 0) finish = true;
            //cout << bfs_self.size() << " " << bfs_cops.size() << "\n";

            vector<int> tmp_self(0), tmp_cops(0);
            for(auto it: bfs_cops){
                visited_cops[it] = 1;
                if(hideouts.find(it) != hideouts.end()){
                    hideouts.erase(hideouts.find(it));
                }
                for(auto to: adj_list[it]){
                    if(!visited_cops[to]){
                        visited_cops[to] = 1;
                        tmp_cops.push_back(to);
                    }
                }
            }
            bfs_cops = tmp_cops;
            for(auto it: bfs_self){
                visited_self[it] = 1;
                if(hideouts.find(it) != hideouts.end()){
                    find = true;
                    finish = true;
                }
                for(auto to: adj_list[it]){
                    if(!visited_self[to]){
                        visited_self[to] = 1;
                        tmp_self.push_back(to);
                    }
                }
            }
            bfs_self = tmp_self;
            if(!hideouts.size() || (!bfs_cops.size() && !bfs_self.size())) finish = true;
        }

        cout << (find ? "Yes" : "No") << "\n";
    }
}