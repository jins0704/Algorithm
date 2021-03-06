#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int check[8][8][1000];
// 8x8
int arr[8][8];
queue<pair<pair<int, int>,int>> loc;
queue<pair<pair<int, int>,int>> wall;

bool finish = false;

char c;
// 인접한 칸 혹은 대각선 방향으로 이동하거나 서있는 것이 가능하다.
int xx[8] = {-1,-1,-1,0,0,1,1,1};
int yy[8] = {-1,0,1,-1,1,-1,0,1};
void Move(){
    
    int time = 0;
    
    loc.push(make_pair(make_pair(7, 0),0));
    check[7][0][0] = 1;
    
    while(!loc.empty()){
        // 1초 마다 모둔 벽이 아래에 있는 행으로 한칸 내려간다. 행이 없다면 벽은 사라진다

        unsigned long lsize = loc.size();
    
        for(unsigned i=0; i < lsize; i++){
            int fx = loc.front().first.first;
            int fy = loc.front().first.second;
            int ft = loc.front().second;
            
            loc.pop();
            
            if(arr[fx][fy] == 1 || ft != time){
               // cout << fx << " " << fy << " " << ft << " 불가능"<< endl;
                continue;}
            
            if(fx == 0 && fy ==7){
                // 가능하면 1 없으면 0
                finish = true;
                return;
            }
            //cout << fx << " " << fy <<  " " << ft <<" 제자리"<< endl;
            loc.push(make_pair(make_pair(fx, fy),ft+1));
            check[fx][fy][ft+1] = 1;
            
            for(int j=0; j<8; j++){
                int nx = fx + xx[j];
                int ny = fy + yy[j];
                
                if(nx >=0 && ny >=0 && nx < 8 && ny <8){
                    // 이동할 때는 빈칸으로만 이동할 수 있다.
                    if(arr[nx][ny] == 0 && ft == time && check[nx][ny][ft] == 0){
                        loc.push(make_pair(make_pair(nx, ny),ft+1));
                        check[nx][ny][ft+1] = 1;
                      //  cout << nx << " "  << ny <<  " " << ft << " 이동" << endl;
                    }
                }
            }
        }
        
        if(!wall.empty()){
            
            unsigned long wsize = wall.size();
            
            for(unsigned i=0; i < wsize; i++){
                int fx = wall.front().first.first;
                int fy = wall.front().first.second;
                int ft = wall.front().second;
                
                wall.pop();
                
                //한칸씩 아래로 이동
                if(fx <7 && fx >=0){
                    arr[fx][fy] = 0;
                    arr[fx+1][fy] = 1;
                    wall.push(make_pair(make_pair(fx+1, fy),ft+1));
                   // cout << fx+1 << " " << fy <<  " " << ft << " 벽 내려감"<< endl;
                }
                else{
                    arr[fx][fy] = 0;
                }
            }
        }
        
        time++;
    
    }
}
int main(int argc, const char * argv[]) {
    
    for(int i = 0; i < 8; i++){
        for(int j=0; j< 8; j++){
            cin >> c;
            if(c == '.'){
                arr[i][j] = 0; // . : 빈칸 - 0
            }
            else{
                arr[i][j] = 1; // # : 벽 - 1
                wall.push(make_pair(make_pair(i, j),0));
            }
        }
    }
    
    Move();
    
    cout << finish;
    
    return 0;
}
