//
//  main.cpp
//  12100_Simulation
//
//  Created by 홍진석 on 2021/05/12.
//

#include <iostream>
#include <vector>

using namespace std;

//한번의 이동 - 상하좌우
//같은 값을 갖는 두 블록이 충돌하면 하나로 합쳐진다
//이미 합쳐진 블록은 또 다른 블록과 합쳐질 수 없다
//이동하려고 하는 쪽의 칸이 먼저 합쳐진다. 위로 이동키는 경우 위쪽에 있는 블록이 먼저 합쳐진다.
//최대 5번 이동해서 만들 수 있는 가장 블록의 값

//첫째줄 : 보드 크기 N
//둘째줄 : 게임판의 초기상태
//0은 빈칸 나머지는 블록
//블록은 2<= 1024보다 작거나 같은 2의 제곱꼴

int N,n;
int dx[4] ={-1,0,0,1};
int dy[4] = {0,-1,1,0}; //위 왼 오 아래 순
int maxValue = 0;

void play(int cnt, int arr[21][21]){
    if(cnt == 5){
        //cout << endl;
        int biggest = 0;
        for(int r = 0; r<N; r++){
            for(int s=0; s<N; s++){
                //cout << arr[r][s] << " ";
                if(biggest < arr[r][s]){
                    biggest = arr[r][s];
                }
            }//cout << endl;
        }
        if(biggest > maxValue){
            maxValue = biggest;
        }
    }
    
    else{
        for(int i=0; i<4; i++){// 위 왼 오 아래 순
            int copyarr[21][21];
            
            for(int j=0; j<21; j++){
                for(int k=0; k<21; k++){
                    copyarr[j][k] = arr[j][k];
                }
            }
            if(i ==0 || i == 3){
                if(i == 0 ){
                    for(int j=0; j<N; j++){
                        for(int k=0; k<N-1; k++){
                            if(copyarr[k][j] !=0){
                                int c = 1;
                                while(k+c < N){
                                    if(copyarr[k+c][j] != 0){
                                        if(copyarr[k][j] == copyarr[k+c][j]){
                                            copyarr[k][j] = copyarr[k][j]*2;
                                            copyarr[k+c][j] = 0;
                                        }
                                        break;
                                    }
                                    else{
                                        c++;
                                    }
                                }
                            }
                        }
                    }
                    //cout << "위 ";
                    for(int j=0; j<N; j++){
                        for(int k=0; k<N-1; k++){
                            if(copyarr[k][j] == 0){
                                for(int l = k; l<N; l++){
                                    if(copyarr[l][j] != 0){
                                        copyarr[k][j] = copyarr[l][j];
                                        copyarr[l][j] = 0;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    play(cnt+1,copyarr);
                }
                else{
                    //cout << "아래 ";
                    for(int j=0; j<N; j++){
                        for(int k=N-1; k>0; k--){
                            if(copyarr[k][j] !=0){
                                int c = -1;
                                while(k+c >=0){
                                    if(copyarr[k+c][j] != 0){
                                        if(copyarr[k][j] == copyarr[k+c][j]){
                                            copyarr[k][j] = copyarr[k][j]*2;
                                            copyarr[k+c][j] = 0;
                                        }
                                        break;
                                    }
                                    else{
                                        c--;
                                    }
                                }
                            }
                        }
                    }
                    for(int j=0; j<N; j++){
                        for(int k=N-1; k > 0; k--){
                            if(copyarr[k][j] == 0){
                                for(int l = k-1; l >= 0; l--){
                                    if(copyarr[l][j] != 0){
                                        //cout << l << " " << j << " 찾음 " << endl;
                                        copyarr[k][j] = copyarr[l][j];
                                        copyarr[l][j] = 0;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    play(cnt+1,copyarr);
                }
            }
            else{
                if(i == 1){
                    //cout << "왼 ";
                    for(int j=0; j<N; j++){
                        for(int k=0; k<N-1; k++){
                            if(copyarr[j][k] !=0){
                                int c = 1;
                                while(k+c < N){
                                    if(copyarr[j][k+c] != 0){
                                        if(copyarr[j][k] == copyarr[j][k+c]){
                                            copyarr[j][k] = copyarr[j][k]*2;
                                            copyarr[j][k+c] = 0;
                                        }
                                        break;
                                    }
                                    else{
                                        c++;
                                    }
                                }
                            }
                        }
                    }
                    for(int j=0; j<N; j++){
                        for(int k=0; k<N-1; k++){
                            if(copyarr[j][k] == 0){
                                for(int l =k; l<N; l++){
                                    if(copyarr[j][l] != 0){
                                        copyarr[j][k] = copyarr[j][l];
                                        copyarr[j][l] = 0;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    play(cnt+1,copyarr);
                }
                else{
                    //cout << "오 ";
                    for(int j=0; j<N; j++){
                        for(int k=N-1; k>0; k--){
                            if(copyarr[j][k] !=0){
                                int c = -1;
                                while(k+c >=0){
                                    if(copyarr[j][k+c] != 0){
                                        if(copyarr[j][k] == copyarr[j][k+c]){
                                            copyarr[j][k] = copyarr[j][k]*2;
                                            copyarr[j][k+c] = 0;
                                        }
                                        break;
                                    }
                                    else{
                                        c--;
                                    }
                                }
                            }
                        }
                    }
                    for(int j=0; j<N; j++){
                        for(int k= N-1; k > 0; k--){
                            if(copyarr[j][k] == 0){
                                for(int l = k-1; l >= 0; l--){
                                    if(copyarr[j][l] != 0){
                                        copyarr[j][k] = copyarr[j][l];
                                        copyarr[j][l] = 0;
                                        //cout << j << " "<< l <<" -> "<<j <<" " << k << " 변경" << endl;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    play(cnt+1,copyarr);
                }
            }
        }
    }
}
int main() {
    cin >> N;
    int arr[21][21];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> n;
            arr[i][j] = n;
        }
    }
    play(0,arr);
    
    cout << maxValue;
    return 0;
}
