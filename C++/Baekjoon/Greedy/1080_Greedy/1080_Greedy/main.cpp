//
//  main.cpp
//  1080_Greedy
//
//  Created by 홍진석 on 2021/02/13.
//

#include <iostream>

using namespace std;

int N, M, n;
int A[51][51];
int B[51][51];
int NC[51][51];

//뒤집는 횟수
int cnt;

//체크하기
int x[9] = {0,0,1,1,1,2,2,2,0};
int y[9] = {1,2,0,1,2,0,1,2,0};

//뒤집기
void flip(int i, int j){

    cnt++;
    
    for(int q=0; q<9; q++){
        
        int cx = x[q];
        int cy = y[q];
        
        NC[i+cx][j+cy] = !NC[i+cx][j+cy];
        
    }
}

int main() {
    cin >> N >> M;
    
    //A배열 만들기
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &A[i][j]);
        }
    }
    //고칠부분 1로 배열 만들기
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &n);
            if(A[i][j] != n){
                NC[i][j] = 1;
            }
        }
    }

    //3보다 작은 경우
    if(N < 3 || M <3){
        bool littleCheck= false;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(NC[i][j] == 1){
                    littleCheck = true;
                    break;
                }
            }if(littleCheck){break;}
        }
        
        if(littleCheck){cout << "-1";}
        else{cout << 0;}
    }
    //3보다 큰 경우
    else{
        //가능한지 체크
        int imposCheck = false;
        
        for(int i=0; i<N-2; i++){
            for(int j=0; j<M-2; j++){
                if(NC[i][j] == 1 ){
                    //뒤집기
                    flip(i,j);
                }
            }
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(NC[i][j] == 1){
                    imposCheck = true;
                    break;
                }
            }
            if(imposCheck == true){break;}
        }
        
        if(imposCheck){
            cout << "-1";
        }
        else{
            cout << cnt;
        }
    }
}

