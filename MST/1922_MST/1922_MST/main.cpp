//
//  main.cpp
//  1922_MST
//
//  Created by 홍진석 on 2021/08/04.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,n) for(int i=0; i< (n); i++)

using namespace std;

int N, M;
int a, b, c;
int cost, from, to, answer;
int parent[1001];

int findParent(int v){
    if(parent[v] == v) { return v; }
    else{ return findParent(parent[v]); }
}

int main() {
    cin >> N;
    cin >> M;
    vector<pair<int,pair<int, int>>> node;
    FOR(i, N+1){ parent[i] = i; }
    FOR(i, M){
        cin >> a >> b >> c;
        node.push_back(make_pair(c, make_pair(a, b)));
    }
    
    sort(node.begin(), node.end());
    
    
    FOR(i, node.size()){
        cost = node[i].first;
        from = node[i].second.first;
        to = node[i].second.second;
        
        int parentOfFrom = findParent(from);
        int parentOfTo = findParent(to);
        
        if(parentOfFrom != parentOfTo){
            parent[parentOfTo] = parent[parentOfFrom]; //union
            answer += cost;
        }
    }
    
    cout << answer;
    return 0;
}

