//
//  main.cpp
//  2447_분할정복
//
//  Created by 홍진석 on 2021/02/01.
//

#include <iostream>

using namespace std;

int N;
char arr[7000][7000];

void star(int x, int y, int size){
    
    //크기 3의 별 찍기
    if(size == 3){
        for(int i = x; i<x+size; i++){
            for(int j=y; j<y+size; j++){
                if(i == x+1 && j == y+1){
                    arr[i][j] = ' ';
                }
                else{
                    arr[i][j] = '*';
                }
            }
        }
    }
    
    //3보다 클 경우 가운데 빼고 분할
    else{
        star(x,y,size/3);
        star(x,y+size/3,size/3);
        star(x,y+size/3*2,size/3);
        
        
        star(x+size/3,y,size/3);
        
        star(x+size/3,y+size/3*2,size/3);
        
        
        star(x+size/3*2,y,size/3);
        star(x+size/3*2,y+size/3,size/3);
        star(x+size/3*2,y+size/3*2,size/3);
    }
    

}

int main(int argc, const char * argv[]) {
    
    scanf("%d",&N);
    
    //arr 전부 빈칸으로 초기화
    for(int i = 0; i<N; i++){
        for(int j =0; j<N; j++){
            arr[i][j] = ' ';
        }
    }
    
    star(0,0,N);
    
    for(int i = 0; i<N; i++){
        for(int j =0; j<N; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
