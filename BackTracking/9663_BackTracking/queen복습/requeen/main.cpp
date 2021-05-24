//
//  main.cpp
//  requeen
//
//  Created by 홍진석 on 2021/05/24.
//

#include <iostream>

using namespace std;

int N;
int arr[16][16];
int cnt;
int check[16][16];

void makeLimit(int h, int l, int N){
    for(int i =1; i<=N; i++){
        check[h][i]++; //좌우
        if(h-i >=1){check[h-i][l]++;} //위
        if(h+i <=N){check[h+i][l]++;} //아래
        if(h-i >=1 && l-i >=1){check[h-i][l-i]++;}//왼쪽 위 대각선
        if(h+i <=N && l-i >=1){check[h+i][l-i]++;}//왼쪽 아래 대각선
        if(h-i >=1 && l+i <=N){check[h-i][l+i]++;}//오른쪽 위 대각선
        if(h+i <=N && l+i <=N){check[h+i][l+i]++;}//오른쪽 아래 대각선
    }
}

void looseLimit(int h, int l, int N){
    for(int i =1; i<=N; i++){
        check[h][i]--; //좌우
        if(h-i >=1){check[h-i][l]--;} //위
        if(h+i <=N){check[h+i][l]--;} //아래
        if(h-i >=1 && l-i >=1){check[h-i][l-i]--;}//왼쪽 위 대각선
        if(h+i <=N && l-i >=1){check[h+i][l-i]--;}//왼쪽 아래 대각선
        if(h-i >=1 && l+i <=N){check[h-i][l+i]--;}//오른쪽 위 대각선
        if(h+i <=N && l+i <=N){check[h+i][l+i]--;}//오른쪽 아래 대각선
    }
}

void queen(int h){
    if(h > N){
        cnt ++;
        return;
    }
    
    else{
        for(int i=1; i<=N; i++){
            if(check[h][i] == 0 && arr[h][i] == 0){
                makeLimit(h,i,N);
                arr[h][i] = 1;
                queen(h+1);
                arr[h][i] = 0;
                looseLimit(h, i, N);
            }
        }
    }
    
}
int main() {
    
    cin >> N;

    queen(1);
    
    cout << cnt;
    return 0;
}
