//
//  main.cpp
//  1992_쿼드트리_분할정복
//
//  Created by 홍진석 on 2021/01/31.
//

#include <iostream>

using namespace std;

int N,n;
int arr[100][100];
int c;
bool err;

void qt(int x,int y, int size){
    c = arr[x][y];
    
    if(size ==1){
        printf("%d",c);
        
    }
    else{
        //해당 영역 모두 같은 수인지 확인
        for(int i=x; i<x+size; i++){
            for(int j=y; j<y+size; j++){
                if(arr[i][j] != c){
                    err = true;
                    break;
                }
            }
            if(err == true){
                break;
            }
        }
        
        //같은 수가 아니라면 나누기
        if(err == true){
            printf("(");
            err = false;
            
            qt(x,y,size/2);
            qt(x,y+size/2,size/2);
            qt(x+size/2,y,size/2);
            qt(x+size/2,y+size/2,size/2);
            
            printf(")");
        }
        //같은 수 였다면 그냥 출력
        else{
            printf("%d",c);
        }
        
    }
}

int main(int argc, const char * argv[]) {
    
    scanf("%d",&N);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            scanf("%1d",&n);
            arr[i][j] = n;
        }
    }
    
    qt(0,0,N);
    
    return 0;
}
