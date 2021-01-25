//
//  main.cpp
//  10828_Stack
//
//  Created by 홍진석 on 2021/01/25.
//

#include <iostream>

using namespace std;

int N;
string method;
int num;
int arr[10001];
int cnt;

void push(int num){
    arr[cnt] = num;
    cnt ++;
}

void pop(){
    if(cnt == 0){
        cout << "-1" << endl;
    }else{
        cout << arr[cnt-1] << endl;
        cnt --;
    }
}

void size(){
    cout << cnt << endl;
}

void empty(){
    if(cnt == 0){
        cout << "1" << endl;
    }else{
        cout << "0" << endl;
    }
}

void top(){
    if(cnt == 0){
        cout << "-1" << endl;
    }else{
        cout << arr[cnt-1] << endl;
    }
}

int main() {

    cin >> N;

    while(N--){
        cin >> method;
        
        if(method == "push"){
            cin >> num;
            push(num);
        }
        else if(method == "pop"){
            pop();
        }
        else if(method == "size"){
            size();
        }
        else if(method == "empty"){
            empty();
        }else{
            top();
        }
    }
    
    return 0;
}
