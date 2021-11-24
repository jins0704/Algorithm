//
//  main.cpp
//  1197_MST
//
//  Created by 홍진석 on 2021/08/03.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

int V,E;
int A, B, C;
int parent[10001], sum;
vector<pair<int,pair<int,int>>> roads;

int findParent(int v){
    if(parent[v] == v){ return v; }
    else{ return findParent(parent[v]); }
}

int main() {
    cin >> V >> E;
    FOR(i, V){//자기 자신을 부모로 저장
        parent[i] = i;
    }
    
    FOR(i, E){//간선 정보 저장
        cin >> A >> B >> C;
        roads.push_back(make_pair(C, make_pair(A, B)));
    }
    
    sort(roads.begin(), roads.end());//간선 정보 오름차순
    
    FOR(i, roads.size()){
        int from = roads[i].second.first;
        int to = roads[i].second.second;
        
        if(findParent(from) != findParent(to)){//사이클이 아니라면
            parent[findParent(to)] = findParent(from);//연결하기
            sum += roads[i].first; //가중치 더하기
        }
    }
    
    cout << sum;
    return 0;
}
