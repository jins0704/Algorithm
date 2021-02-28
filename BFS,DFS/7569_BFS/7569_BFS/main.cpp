//
//  main.cpp
//  7569_BFS
//
//  Created by 홍진석 on 2021/02/28.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int,pair<int, int>>> q; //높이, x, y
int M,N,H,n,day;
int arr[101][101][101];

//1 : 익은 토마토, 0 : 익지않은 토마토, -1 : 토마토없음
int xx[6] ={0,0,1,-1,0,0};
int yy[6] ={0,0,0,0,1,-1};
int zz[6] ={-1,1,0,0,0,0};

void tomato(){
    
    while(!q.empty()){
        
        unsigned long qsize = q.size();
        
        bool newCheck = false;
        
        for(int w = 0; w < qsize; w++){
            
            int fz = q.front().first;
            int fx = q.front().second.first;
            int fy = q.front().second.second;
            
            q.pop();
            
            arr[fx][fy][fz] = 1;
            
            for(int i=0; i<6; i++){
                int cx = fx + xx[i];
                int cy = fy + yy[i];
                int cz = fz + zz[i];
                
                if(cx >0 && cy > 0 && cz >0 && cx <=N && cy <= M && cz <=H){
                    if(arr[cx][cy][cz] == 0) {
                        
                        arr[cx][cy][cz] = 1;
                        newCheck = true;
                        q.push(make_pair(cz, make_pair(cx, cy)));
                        
                    }
                }
            }
        }
        
        if(newCheck){
            day ++;
        }
        else{
            return ;
        }
    }
}
int main() {
    
    cin >> M >> N >> H;
    
    //토마토 상자 입력
    for(int k=1; k<=H; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                cin >> n;
                arr[i][j][k] = n;
                
                if(n == 1){
                    q.push(make_pair(k, make_pair(i, j)));
                }
            }
        }
    }
    
    tomato();
    
    bool impossibleCheck = false;
    
    for(int k=1; k<=H; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(arr[i][j][k] == 0){
                    impossibleCheck = true;
                    break;
                }
            }
            if(impossibleCheck){break;}
        }if(impossibleCheck){break;}
    }
    
    if(impossibleCheck){
        cout << "-1";
    }
    else{
        cout << day;
    }
    
    return 0;
}
