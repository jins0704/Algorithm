//
//  main.cpp
//  1753_Dijkstra
//
//  Created by 홍진석 on 2021/04/11.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V,E;
int K;
int u,v,w;

vector<pair<int,int>> arr[20001];
bool check[20001];
int bestSol[20001];

struct cmp{
    bool operator()(pair<int,int> &x, pair<int,int> &y){
        return x.second > y.second;
    }
};

priority_queue<pair<int, int>,vector<pair<int,int>>,cmp> pq;

int main() {
    
    cin >> V >> E;
    cin >> K;

    for(int i=0; i<E; i++){
        cin >> u >> v >> w;

        arr[u].push_back(make_pair(v, w));
    }

    pq.push(make_pair(K, 0));
    
    while (!pq.empty()) {
        
        int currentV = pq.top().first;
        int currentW = pq.top().second;

        pq.pop();

        if(check[currentV]){continue;}

        check[currentV] = true;
        bestSol[currentV] = currentW;

        for(int i=0; i<arr[currentV].size(); i++){
            if(!check[arr[currentV].at(i).first]){
                pq.push(make_pair(arr[currentV].at(i).first, arr[currentV].at(i).second + currentW));
            }
        }
    }

    for(int i=1; i<= V; i++){
        if(bestSol[i] == 0 && i != K){
            printf("INF\n");
        }
        else{
            printf("%d\n",bestSol[i]);
        }
    }

    return 0;
}
