//
//  main.cpp
//  10773_Stack
//
//  Created by 홍진석 on 2021/01/25.
//

#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int K;
int N;
int sum;
int main() {
    cin >> K;
    while(K--){
        cin >> N;
        if(N==0){
            st.pop();
        }else{
            st.push(N);
        }
    }
    
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    cout << sum;
    return 0;
}
