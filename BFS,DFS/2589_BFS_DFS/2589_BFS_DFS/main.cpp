//
//  main.cpp
//  2589_BFS_DFS
//
//  Created by 홍진석 on 2021/03/25.
//

#include <iostream>
#include <queue>

using namespace std;

//육지 : L, 바다 : W
//상하좌우 이웃 육지로만 이동 가능

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

queue<pair<int, int>> q;

char arr[51][51];
int wholeCheck[51][51];
int N,M;
char c;
int maxvalue;

void bfs(int cx, int cy){
    int hour = -1;
    
    int check[51][51] = {0,};
    
    check[cx][cy] = 1;
    
    q.push(make_pair(cx, cy));
    
    while (!q.empty()) {
        unsigned long qsize = q.size();
        
        for(unsigned w= 0; w<qsize; w++){
            int fx = q.front().first;
            int fy = q.front().second;
            
            q.pop();
            
            for(int k =0; k< 4; k++){
                int cx = fx + dx[k];
                int cy = fy + dy[k];
                
                if(cx>=0 && cy>=0 && cx <N && cy <M){
                    if(arr[cx][cy] == 'L' && check[cx][cy] == 0){
                        check[cx][cy] = 1;
                        q.push(make_pair(cx, cy));
                    }
                }
            }
        }
        hour ++;

    }
    
    //cout << hour << endl;
    if(maxvalue < hour){
        maxvalue = hour;
    }
}

int main() {
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> c;
            arr[i][j] = c;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 'L' && wholeCheck[i][j] == 0){
                //cout << i << " " << j << " : ";
                wholeCheck[i][j] = 1;
                bfs(i,j);
            }
        }
    }
    
    cout << maxvalue;
    return 0;
}
