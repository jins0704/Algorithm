//
//  main.cpp
//  짝지어제거하기
//
//  Created by 홍진석 on 2021/06/23.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;
    
    for(int i=0; i< s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else{
            if(st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    return answer;
}
