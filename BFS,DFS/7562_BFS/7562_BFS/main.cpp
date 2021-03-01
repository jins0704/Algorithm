//
//  main.cpp
//  7562_BFS
//
//  Created by 홍진석 on 2021/03/01.
//

#include <iostream>
#include <queue>
#include <vector>

//체스판 위 나이트
//테스트 개수 입력 T
//체스판 한 변의 길이 l, 나이트가 현재 있는 칸 (cx,cy), 나이트가 이동하려고 하는 칸 (nx,ny)

using namespace std;

int T,l,cx,cy,a,b;
int chess[301][301];

int xx[8] = {-1,-2,-2,-1,1,2,2,1};
int yy[8] = {-2,-1,1,2,-2,-1,1,2};

vector<int> v;

//새로운 케이스를 위해 체스판 리셋
void caseClear(int l){
    for(int i=0; i<l; i++){
        for(int j=0; j<l; j++){
            chess[i][j] = 0;
        }
    }
}

//나이트 말 움직이기
void nightMove(int cx, int cy){
    int cnt = 0;
    bool finish = false;
    
    if(cx == a && cy == b){
        v.push_back(0);
        return;
    }
    
    queue<pair<int,int>> q;
    q.push(make_pair(cx, cy));
    
    
    while(!q.empty()){

        unsigned long qsize = q.size();
        
        for(int i=0; i< qsize; i++){
            
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            
            chess[x][y] = 1;
            
            for(int j=0; j<8; j++){
                
                int nx = x + xx[j];
                int ny = y + yy[j];
                
                if(nx >=0 && ny >=0 && nx<l && ny<l){
                    if(chess[nx][ny] == 0){
                        chess[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
                if(nx == a && ny == b){
                    finish = true;
                    break;
                }
            }
            if(finish){break;}
        }
        cnt ++;
        if(finish){
            v.push_back(cnt);
            break;
        }
    }
    
}
int main() {

    cin >> T;
    
    while(T--){
        
        cin >> l;
        cin >> cx >> cy;
        cin >> a >> b;
    
        nightMove(cx,cy);
        caseClear(l);
    }
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }
    
    return 0;
}
