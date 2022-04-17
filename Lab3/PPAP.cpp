#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int value;
    string str;
    bool is_leaf = true;
    node* left = NULL;
    node* right = NULL;
};

bool cmp(node* a, node* b){
    if(a->value == b->value) return a->str > b->str;
    else return a->value > b->value;
}

void traverse(node* root, map<string,int> &path, int layer){
    if(root->is_leaf) path[root->str] = layer;
    if(root->left) traverse(root->left, path, layer+1);
    if(root->right) traverse(root->right, path, layer+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    string str;
    getline(cin, str);
    
    stringstream ss;
    map<string,int> mp;
    vector<vector<string>> sen(n);
    for(int i=0; i<n; i++){
        getline(cin, str);
        ss.clear();
        ss << str;
        while(ss >> str){
            mp[str]++;
            sen[i].push_back(str);
        }
    }

    priority_queue<node*, vector<node*>, function<bool(node*, node*)>> pq(cmp);
    for(auto it: mp){
        node* tmp = new node;
        tmp->str = it.first;
        tmp->value = it.second;
        pq.push(tmp);
    }

    while(pq.size() != 1){
        node* tmp1 = pq.top(); pq.pop();
        node* tmp2 = pq.top(); pq.pop();

        node* tmp3 = new node;
        tmp3->value = tmp1->value + tmp2->value;
        tmp3->str = min(tmp1->str, tmp2->str);
        tmp3->is_leaf = false;
        tmp3->left = tmp1;
        tmp3->right = tmp2;
        pq.push(tmp3);
    }
    
    map<string,int> path;
    traverse(pq.top(), path, 0);
    
    for(auto it: sen){
        int sum = 0;
        for(auto itt: it) sum += path[itt];
        cout << fixed << setprecision(10) << sum / (ceil(log2(mp.size()))*it.size()) << "\n";
    }
}