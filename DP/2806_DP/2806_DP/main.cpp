//
//  main.cpp
//  2806_DP
//
//  Created by 홍진석 on 2021/07/24.
//

#include <iostream>

using namespace std;
//1. 한글자가 다른 글자로 변경
//2. 첫번째 부터 K글자 까지 모두 변경
//최소 몇번으로 전부 A분자로 만들지 구하기

int N;
char c[1000001];

void changeMethodB(int index, char c[]){
    for(int i=0; i<= index; i++){
        c[i] = (c[i] == 'A') ? 'B' : 'A';
    }
}

bool checkComplete(char c[], int N){
    for(int i=0; i<N; i++){
        if(c[i] == 'B'){return true;}
    }
    return false;
}

int main() {
    int count = 0;
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> c[i];
    }
    
    int checkIndex = N-1;
    
    while(checkComplete(c, N)){
        for(int i=0; i< N; i++){
            cout << c[i] << " ";
        }cout << endl;
        
        if(count == 30){break;}
        
        if(c[checkIndex] == 'B'){
            if(checkIndex == 0){
                cout << "A선택" << endl;
                c[checkIndex] = 'A';
            }
            else{
                if(c[checkIndex-1] == 'A'){
                    cout << "A선택" << endl;
                    c[checkIndex] = 'A';
                }
                
                for(int j=1; j<=checkIndex; j++){
                    if(c[checkIndex-j] != 'B'){
                        cout << "B선택" << endl;
                        changeMethodB(checkIndex, c);
                        checkIndex = checkIndex-j+1;
                        break;
                    }
                }
            }
        
            count ++;
        }
        else{
            while(c[checkIndex] == 'A'){
                if(checkIndex == 0){break;}
                checkIndex--;
            }
        }
        
        for(int i=0; i< N; i++){
            cout << c[i] << " ";
        }cout << endl;
        cout << "===========" << endl;
        cout << checkIndex << endl;
    }
    
    
    cout << count;
    return 0;
}

