//
//  main.cpp
//  1600_BFS
//
//  Created by 홍진석 on 2021/03/07.
//

#include <iostream>
#include <queue>

using namespace std;

int arr[201][201][31];
int K,W,H;
bool finish;
//말처럼은 K번 원숭이처럼은 자유
//맨 왼쪽위(1,1) -> 맨 오른쪽 아래(W,H)
//원숭이 동작 수의 최솟값 출력, 도착할수 없는 경우에는 -1

//말 이동방식
int hx[8] = {-2,-2,-1,-1,1,1,2,2};
int hy[8] = {-1,1,-2,2,-2,2,-1,1};

//원숭이 이동방식
int mx[4] = {-1,1,0,0};
int my[4] = {0,0,-1,1};
int sol =1000000;
struct monkey{
    int horseTime = K;
    int monkeyTime = 0;
    int cx = 0;
    int cy = 0;
};


//x,y좌표와 시간
queue<monkey> loc;
void Move(){
    
    monkey curMonkey;
    curMonkey.horseTime = 0;
    curMonkey.monkeyTime = 0;
    curMonkey.cx = 1;
    curMonkey.cy = 1;
    
    loc.push(curMonkey);
    
    while(!loc.empty()){
        
        unsigned long lsize = loc.size();
        
        for(int i=0; i<lsize; i++){
            int fx = loc.front().cx;
            int fy = loc.front().cy;
            int fmt = loc.front().monkeyTime;
            int fht = loc.front().horseTime;
            
            loc.pop();
            
            if(fx == H && fy == W){
                int sum = fmt+fht;
                //cout << fmt+fht << " 원숭이 횟수써서 도착" << endl;
                finish = true;
                if(sol>= sum){
                    sol = sum;
                }
                continue;
            }
            
            if(fht < K){
                for(int j =0; j<8; j++){
                    int nx = fx + hx[j];
                    int ny = fy + hy[j];
                    
                    if(nx>=1 && ny>=1 && nx <=H && ny <=W){
                        if(arr[nx][ny][fht+1] == 0 && arr[nx][ny][0] == 0){
                            arr[nx][ny][fht+1] = 1;
                            monkey newM ;
                            newM.cx = nx;
                            newM.cy = ny;
                            newM.monkeyTime = fmt;
                            newM.horseTime = fht+1;
                            //cout << newM.cx << " " << newM.cy << " " << newM.monkeyTime << " " << newM.horseTime << " 이동" << endl;
                            loc.push(newM);
                        }
                    }
                }
            }
            
            for(int k = 0; k <4; k++){
                int nx = fx + mx[k];
                int ny = fy + my[k];
                
                if(nx>=1 && ny>=1 && nx <=H && ny <=W){
                    if(arr[nx][ny][fht] == 0 && arr[nx][ny][0] == 0){
                        arr[nx][ny][fht] = 1;
                        monkey newM ;
                        newM.cx = nx;
                        newM.cy = ny;
                        newM.monkeyTime = fmt+1;
                        newM.horseTime = fht;
                        //cout << newM.cx << " " << newM.cy << " " << newM.monkeyTime << " " << newM.horseTime << " 이동" << endl;
                        loc.push(newM);
                    }
                }
            }
        }
    }
}

int main() {
    
    cin >> K;
    cin >> W >> H;
    
    //여행길
    //0 : 평지, 1 : 장애물
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            cin >> arr[i][j][0];
        }
    }
    
    Move();
    
    if(finish){cout << sol;}
    else{
        cout << -1;
    }
    
    return 0;
}
