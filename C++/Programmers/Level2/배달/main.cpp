//
//  main.cpp
//  배달
//
//  Created by 홍진석 on 2021/10/10.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void checkRoads(vector<vector<int>> &roads){
    for(int i=0; i<roads.size(); i++){
        for(int j=0; j<roads[i].size(); j++){
            cout << roads[i][j] << " ";
        }cout << endl;
    }
}

void dfs(vector<int> &cost, vector<vector<int>> &roads, int N){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> q;
    
    q.push(make_pair(0,0));
    vector<vector<bool>> check(N,vector<bool>(N,0));
    
    while(!q.empty()){
        int cx = q.top().second;
        int cCost = q.top().first;
        q.pop();
        
        for(int i=0; i<N; i++){
            if(cx == i) { continue; }
            if(roads[cx][i] == -1){ continue; }
            if(check[cx][i]) { continue; }
            check[cx][i] = true;
            if(cost[i] == -1 || cost[i] > cCost+roads[cx][i]) {
                cost[i] = cCost+roads[cx][i];
                q.push(make_pair(cost[i],i));
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<int>> roads(N,vector<int>(N,-1));
    vector<int> cost(N,-1);
    cost[0] = 0; //원점
    
    for(int i=0; i<road.size(); i++){
        if( roads[road[i][0]-1][road[i][1]-1] != -1){
            if(roads[road[i][0]-1][road[i][1]-1] < road[i][2]) { continue; }
        }
        roads[road[i][0]-1][road[i][1]-1] = road[i][2];
        roads[road[i][1]-1][road[i][0]-1] = road[i][2];
    }
    
    dfs(cost,roads,N);
    for(int i=0; i<N; i++){
        if(cost[i] <= K) { answer ++; }
    }
    return answer;
}
