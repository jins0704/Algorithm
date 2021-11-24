//
//  main.cpp
//  2667_BFS_두번째풀이
//
//  Created by 홍진석 on 2021/02/27.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//단지 개수 , 각 단지의 집 개수

int N,n;
int arr[30][30];
int check[30][30];

int xx[4] = {0,0,-1,1};
int yy[4] = {-1,1,0,0};

queue<pair<int,int>> q;
vector<int> team;

int makeBFS(int curx, int cury, int cnt){
    check[curx][cury] = 0;
    cnt++;
    
    q.push(make_pair(curx, cury));
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int j = 0; j < 4; j++){
            int ccx = x + xx[j];
            int ccy = y + yy[j];
            if(ccx >= 0 && ccy >= 0 && ccx < N && ccy < N && check[ccx][ccy] == 1){
                check[ccx][ccy] = 0;
                
                cnt++;
                
                q.push(make_pair(ccx, ccy));
                
            }
        }
    }
    
    return cnt;
}

int main() {
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            scanf("%1d", &n);
            
            arr[i][j] = n;
            check[i][j] = n;
            
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 1 && check[i][j] == 1){
                team.push_back(makeBFS(i,j,0));
            }
        }
    }
    
    sort(team.begin(), team.end());
    
    cout << team.size() << endl;
    for(int i=0; i< team.size(); i++){
        cout << team[i] << endl;
    }
}
