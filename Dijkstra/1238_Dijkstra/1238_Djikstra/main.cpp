//
//  main.cpp
//  1238_Djikstra
//
//  Created by 홍진석 on 2021/04/12.
//

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

struct cmp{
    bool operator()(pair<int,int> &x, pair<int,int> &y){
        return x.second > y.second;
    }
};

int N,M,X;
int s,l,t;
int best[1001][1001];

int main() {
    //첫째 줄에 N(1~1000), M(1~10000), X
    cin >> N >> M >> X;
    
    vector<pair<int, int>> arr[N+1];
    
    for(int i=0; i<M; i++){
        //i번째 도로의 시작점, 끝점, 소요시간 Ti
        cin >> s >> l >> t;
        arr[s].push_back(make_pair(l, t)); //s->l 소요시간 t
    }

    for(int i=1; i<= N; i++){
        for(int j=1; j<=N; j++){
           best[i][j] = INF;
        }
    }

    for(int j=1; j<=N; j++){

        priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> pq;
        bool visit[1001] = {false};

        pq.push(make_pair(j, 0));

        while (!pq.empty()) {

            int currentX = pq.top().first;
            int w = pq.top().second;

            pq.pop();
            
            if(visit[currentX]){continue;}
            
            visit[currentX] = true;
            
            if(w <= best[j][currentX]){
                best[j][currentX] = w;
            }

            for(int i=0; i<arr[currentX].size(); i++){
                if(!visit[arr[currentX].at(i).first]){
                    pq.push(make_pair(arr[currentX].at(i).first, arr[currentX].at(i).second + w));
                }
            }
        }
    }

    int maxValue = -1;

    for(int i=1; i<= N; i++){

        if(best[i][X] + best[X][i] >= maxValue){
            maxValue = best[i][X] + best[X][i];
        }
    }

    printf("%d",maxValue);
    
    return 0;
}
