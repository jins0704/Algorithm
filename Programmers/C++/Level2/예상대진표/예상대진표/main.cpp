//
//  main.cpp
//  예상대진표
//
//  Created by 홍진석 on 2021/06/22.
//

#include <iostream>
#include <math.h>

using namespace std;
bool meetAB;
int result;
int A,B;

void cut(int first, int last, int cutCnt){
    if(meetAB){return;}
    else{
        int mid = (first+last)/2;
        if((A <= mid && B > mid)){
            meetAB = true;
            result = cutCnt;
        }
        else{
            if(A>=first && B<= mid){
               cut(first,mid,cutCnt+1);
            }
            else if(A>mid && B<=last){
              cut(mid+1,last,cutCnt+1);
            }
        }
    }
}

int solution(int n, int a, int b)
{
    int answer, rounds = 0;
    if(a < b){
        A = a;
        B = b;
    }
    else{
        A = b;
        B = a;
    }
    
    while(1){
        if(pow(2,rounds) == n){break;}
        rounds++;
    }
    
    cut(1,n,0);
    answer = rounds - result;
    
    return answer;
}
