//
//  main.cpp
//  1074_분할정복
//
//  Created by 홍진석 on 2021/01/31.
//

#include <iostream>
#include <math.h>

using namespace std;

int N, r ,c;
int cnt;

void find(int x, int y, int s){
    
    if(x == r && y == c && s ==1){
        printf("%d", cnt);
        return;
    }
    else{
        if(r < x+s/2 && c < y+s/2){
            find(x, y, s/2);
        }
        else if(r < x+s/2 && c >= y+s/2){
            cnt += s/2*s/2;
            find(x, y+s/2, s/2);
        }
        else if(r >= x+s/2 && c < y+s/2){
            cnt += s*s/2;
            find(x+s/2, y, s/2);
        }
        else{
            cnt += s/2*s/2*3;
            find(x+s/2, y+s/2, s/2);
        }
    }
}

int main() {
    scanf("%d %d %d", &N,&r,&c);

    int n = pow(2,N);
    find(0,0,n);
    
    return 0;
}
