//
//  main.cpp
//  14888_Backtracking
//
//  Created by 홍진석 on 2021/02/02.
//

#include <iostream>

using namespace std;

int N,myMax, myMin;
int arr[12];
int newarr[12];
int mathOperation[4];
int mathSum;
bool firstValue;

int calculation(int x, int y, int m){
    if(m ==0){
        return x+y;
    }
    else if(m == 1){
        return x-y;
    }
    else if(m == 2){
        return x*y;
    }
    else{
        return x/y;
    }
}

void MaxMin(int cnt){
    
    if(cnt == mathSum){
        int sum = arr[0];
        
        for(int i = 0; i < cnt; i++){
    
            sum = calculation(sum, arr[i+1], newarr[i]);
        }
        if(!firstValue){
            myMax = sum;
            myMin = sum;
            firstValue = true;
        }
        else{
            if(sum > myMax){
                myMax = sum;
            }
            if(sum < myMin){
                myMin = sum;
            }
        }
    }
    else{
        for(int j=0; j<4; j++){
            if(mathOperation[j]>0){
                mathOperation[j]--;
                newarr[cnt] = j;
                MaxMin(cnt+1);
                mathOperation[j]++;
            }
        }
    }
}

int main() {
    //수의 개수 입력
    cin >> N;
    
    //A1,A2, ... AN 입력
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    //덧셈,뺄셈,곱셈,나눗셈 순으로 개수 입력
    for(int i=0; i<4; i++){
        cin >> mathOperation[i];
        mathSum += mathOperation[i];
    }
    
    //최대최소 출력
    MaxMin(0);
    
    printf("%d\n", myMax);
    printf("%d\n", myMin);
    
    return 0;
}
