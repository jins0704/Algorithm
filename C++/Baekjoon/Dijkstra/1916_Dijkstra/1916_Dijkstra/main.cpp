//
//  main.cpp
//  1916_Dijkstra
//
//  Created by 홍진석 on 2021/04/15.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
int a,b,c;
int startV, destV;


struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
        {return a.second > b.second;}
};


vector<pair<int, int>> edge[1001];
bool check[1001];
priority_queue<pair<int, int>,vector<pair<int, int>>, cmp> pq;

int main() {
    
    cin >> N;
    cin >> M;

    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
    }

    cin >> startV >> destV;
    
    pq.push(make_pair(startV, 0));
    
    while (!pq.empty()) {
        int currentV = pq.top().first;
        int w = pq.top().second;
        
        pq.pop();
        
        if(currentV == destV){
            cout << w << endl;
            return 0;
        }
        if(check[currentV]){continue;}
        
        check[currentV] = true;
        
        for(int i=0; i<edge[currentV].size(); i++){
            if(!check[edge[currentV].at(i).first]){
                pq.push(make_pair(edge[currentV].at(i).first, w+edge[currentV].at(i).second));
            }
        }
    }
    
    return 0;
}
