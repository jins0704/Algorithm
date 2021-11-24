//
//  main.cpp
//  11047_Greedy
//
//  Created by 홍진석 on 2021/02/11.
//

#include <iostream>

using namespace std;

//동전 N종류 가치의 합을 K로 만든다.
//필요한 동전 개수의 최솟값

int N, K;
int coin[11];

void make(int cnt, int sum){

    
    if(sum == 0){
        cout << cnt << endl;
    }
    else{
        for(int i=N-1; i>=0; i--){
            if(sum >= coin[i]){
                make(cnt+1,sum-coin[i]);
                break;
            }
        }
    }
}

int main() {
    cin >> N >> K;
    
    for(int i=0; i<N; i++){
        cin >> coin[i];
    }
    
    make(0,K);
    
    return 0;
}
