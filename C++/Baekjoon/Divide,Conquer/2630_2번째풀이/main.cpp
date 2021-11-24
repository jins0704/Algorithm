//
//  main.cpp
//  2630_2번째풀이
//
//  Created by 홍진석 on 2021/01/30.
//

#include <iostream>
#include <algorithm>

using namespace std;
int arr[200][200];
int N, n, c;
int white, blue;
bool err;//에러 확인을 통해 빠르게 다음케이스로 넘어감
void cut(int startX, int startY, int size){
    
    c = arr[startX][startY];
    
    if(size == 1){
        if(c ==1){blue++;}
        else{white++;}
        return;
    }
    else{
        for(int i=startX; i<startX+size; i++){
            for(int j=startY; j<startY+size; j++){
                if(arr[i][j] != c){
                    err = true;
                    break;
                }
            }
            if(err == true){
                break;
            }
        }
        if(err == false){
            if(c ==1){blue ++;}
            else{white ++;}
            return;
        }
        else{
            err = false;
            cut(startX, startY, size/2);
            cut(startX+size/2, startY, size/2);
            cut(startX, startY+size/2, size/2);
            cut(startX+size/2, startY+size/2, size/2);
        }
    }
}

int main() {
    
    scanf("%d", &N);
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    cut(0,0,N);

    cout << white << "\n" << blue;
    return 0;
}
