//
//  main.cpp
//  3진법뒤집기
//
//  Created by 홍진석 on 2021/06/22.
//

#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int arr[1001];

int solution(int n) {

    int answer = 0;
    
    //3진법 바꾸기
    int cnt = 0;
  
    while(n > 0){
        arr[cnt] = n%3;
        n = n/3;
        cnt++;
    }

    for(int i=0; i< cnt; i++){
        answer += pow(3,i) * arr[cnt-1-i];
    }
    
    return answer;
}
