//
//  main.cpp
//  9663_Backtracking
//
//  Created by 홍진석 on 2021/02/03.
//

#include <iostream>

using namespace std;

int arr[16][16];
int N;
int sol;
int check[16][16];

void Queen(int cnt){
    //성공 가짓 수 증가
    if(cnt == N){
       sol++;
    }
    
    else{
        //위아래대각선에 놓으면 안된다.
        for(int i=0; i<N; i++){
            
            if(check[cnt][i] == 0){
                
                arr[cnt][i] = 1;
                
                //막기
                check[cnt][i]++;
                
                for(int w=0; w<N; w++){
                    
                    //자기 제외 좌우 양옆 막기
                    if(w != cnt){
                        check[w][i]++;
                    }
                    if(w != i){
                        check[cnt][w]++;
                    }
                    
                    // 자기 제외 '\'대각선 막기
                    if(cnt-w>=0 && i-w>=0 && w>=1){
                        check[cnt-w][i-w]++;
                    }
                    if(cnt+w<N && i+w<N && w>=1){
                        check[cnt+w][i+w]++;
                    }
                    
                    // '/'대각선 막기
                    if(cnt-w>=0 && i+w <N && w>=1){
                        check[cnt-w][i+w]++;
                    }
                    if(cnt+w<N && i-w >=0 && w>=1){
                        check[cnt+w][i-w]++;
                    }
                    
                }
                Queen(cnt+1);
                arr[cnt][i] = 0;
                
                //해제
                check[cnt][i]--;
                for(int w=0; w<N; w++){
                    if(w != cnt){
                        check[w][i]--;
                    }
                    if(w != i){
                        check[cnt][w]--;
                    }
                    
                    if(cnt-w>=0 && i-w>=0 && w>=1){
                        check[cnt-w][i-w]--;
                    }
                    if(cnt+w<N && i+w<N && w>=1){
                        check[cnt+w][i+w]--;
                    }
                    
                    if(cnt-w>=0 && i+w <N && w>=1){
                        check[cnt-w][i+w]--;
                    }
                    if(cnt+w<N && i-w>=0 && w>=1){
                        check[cnt+w][i-w]--;
                    }
                }
            }
        }
    }
}

int main() {
    
    scanf("%d",&N);
    
    Queen(0);
    
    printf("%d",sol);
    return 0;
}
