//
//  main.cpp
//  체육복
//
//  Created by 홍진석 on 2021/06/21.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int arr[31];
    for(int i=0; i<=n; i++){
        arr[i] = 1;
    }
    
    for(int i=0; i< reserve.size(); i++){
        arr[reserve.at(i)]++;
    }
    
    for(int i=0; i< lost.size(); i++){
         arr[lost.at(i)]--;
    }

    for(int i=1; i<=n/2; i++){
        if(arr[i] == 0){
            
            if(i >=2  && arr[i-1] >= 2 ){
                arr[i] ++;
                arr[i-1] --;
            }
            else if(arr[i+1] >=2){
                arr[i] ++;
                arr[i+1] --;
            }
        }
        if(arr[n+1-i] == 0){
            if(2 <= i  && arr[n+2-i] >= 2){
                arr[n+1-i] ++;
                arr[n+2-i] --;
            }
            else if(arr[n-i] >=2){
                arr[n+1-i] ++;
                arr[n-i] --;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        if(arr[i] >=1){answer ++;}
        cout << arr[i] << " ";
    }
    
    return answer;
}
