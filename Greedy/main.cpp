//
//  main.cpp

//

//

#include <iostream>

using namespace std;

int N,K;
int arr[11];

void coin(int index, int sum){
    if(sum == K){
        printf("%d",index);
    }
    
    for(int i=1; i<=N; i++){
        if(K-sum >= arr[N-i]){
            coin(index+1,sum+arr[N-i]);
            break;
        }
    }
}
int main() {
    
    scanf("%d %d",&N,&K);
    
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    
    coin(0,0);
    return 0;
}

