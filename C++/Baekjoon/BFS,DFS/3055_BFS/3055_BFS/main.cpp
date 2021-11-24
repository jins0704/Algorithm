//
//  main.cpp
//  3055_BFS
//
//  Created by 홍진석 on 2021/03/04.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[51][51];
int check[51][51];
int R,C;
char c;
int xx[4] = {-1,1,0,0};
int yy[4] = {0,0,-1,1};

// 고슴도치가 안전하게 비버의 굴로 이동하기 위한 최소 시간
// 고슴도치는 물이 찰 예정인 칸으로 이동 불가능
// 안전하게 비버의 굴로 이동할 수 없다면 "KAKTUS" 출력

vector<pair<int, int>> emptySpace;
vector<pair<int, int>> stoneSpace;
queue<pair<int, int>> waterSpace;
queue<pair<int, int>> startingPoint;
int minute;
bool finish;

void Move(){
    
    while(!startingPoint.empty()){ // 분마다 반복
        
        if(!waterSpace.empty()){
            // 매분 물에 인접한 비어있는 칸도 물로 참
            unsigned long wsize = waterSpace.size();
            
            for(int j = 0; j < wsize; j++){
                int wx = waterSpace.front().first;
                int wy = waterSpace.front().second;
                
                waterSpace.pop();
                
                for(int k=0; k<4; k++){
                    // 매분 고슴도치는 인접 칸으로 이동 가능
                    int wnx = wx + xx[k];
                    int wny = wy + yy[k];
                    
                    if(wny >= 0 && wnx >=0 && wnx <R && wny<C && arr[wnx][wny] == 0){
                        // 빈칸으로만 이동가능
                        arr[wnx][wny] = 1;
                        
                        waterSpace.push(make_pair(wnx, wny));
                    }
                }
            }
        }
        
        unsigned long ssize = startingPoint.size();
        
        bool canMove = false;
        
        for(int r= 0; r <ssize; r++){
            int cx = startingPoint.front().first;
            int cy = startingPoint.front().second;
            
            startingPoint.pop();
            
            check[cx][cy] = true;

            for(int i=0; i<4; i++){
                
                int nx = cx + xx[i];
                int ny = cy + yy[i];
                
                if(arr[nx][ny] == 3){
                    finish = true;
                    minute ++;
                    return;
                }
                
                if(ny >= 0 && nx >=0 && nx <R && ny<C && check[nx][ny] == false && arr[nx][ny] == 0){
                    arr[nx][ny]= 0;
                    canMove = 1;
                    startingPoint.push(make_pair(nx, ny));
      
                    check[nx][ny] = true;
                    
                }
            }
        }
        if(canMove){
            minute++;
        }
    }
}

int main() {

    // R행 C열
    cin >> R >> C;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> c;
            
            if(c == 'D'){ // 비버 굴 : D - 3
                arr[i][j] = 3;
            }
            else if(c == '*'){ // 물로 차있는 지역 : * - 1
                waterSpace.push(make_pair(i, j));
                arr[i][j] = 1;
            }
            else if(c == '.'){ // 비어있는 곳 : . - 0
                emptySpace.push_back(make_pair(i, j));
                arr[i][j] = 0;
            }
            else if(c == 'X'){ // 돌 : X - 2
                stoneSpace.push_back(make_pair(i, j));
                arr[i][j]= 2;
            }
            else if(c == 'S'){ // 고슴도치 위치 : S
                startingPoint.push(make_pair(i, j));
                arr[i][j] = 0;
            }
            else{ return 0;}
        }
    }
//    for(int i=0; i<R; i++){
//        for(int j=0; j<C; j++){
//            cout << arr[i][j] << " ";
//        }cout << endl;
//    }
    
    Move();
    
    if(finish){
        cout << minute;
    }
    else{
        cout << "KAKTUS";
    }
    
    return 0;
}
