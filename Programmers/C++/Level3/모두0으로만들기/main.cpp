//
//  main.cpp
//  모두0으로만들기
//
//  Created by 홍진석 on 2021/09/16.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

long long answer = 0;

void DFS(vector<vector<int>> &graph, vector<long long> &sum, int parent, int child){
    FOR(i, graph[child].size()){
        if(graph[child][i] != parent){//자식이라면 더 깊게 들어간다
            DFS(graph, sum, child, graph[child][i]);
        }
    }

    sum[parent] += sum[child];
    answer += abs(sum[child]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {

    vector<long long> sum(a.begin(), a.end()); //배열 변환
    vector<vector<int>> graph(a.size());
    
    FOR(i, edges.size()){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    DFS(graph,sum,0,0);
    
    if(sum[0] == 0) return answer;
    else return -1;
}

int main() {
    vector<int> a = {-5,0,2,1,2};
    vector<vector<int>> edges = {{0,1},{3,4},{2,3},{0,3}};
    solution(a, edges);
    return 0;
}

//각 점에 가중치 부여 트리
//트리의 모든 점들의 가중치 0으로 만들고자 한다.
//  임의의 연결된 두 점을 골라서 한쪽은 1증가, 다른 한쪽은 1감소
//가능하면 최소 몇번 return
