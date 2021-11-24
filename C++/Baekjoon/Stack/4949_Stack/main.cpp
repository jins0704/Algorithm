//
//  main.cpp
//  4949_Stack
//
//  Created by 홍진석 on 2021/01/27.
//

#include <iostream>
#include <stack>

using namespace std;
int cnt;

stack<char> st;
char c;

int main() {
    string sa;
    
    while(1){
        //문자열 입력
        getline(cin,sa);
        
        // . 입력시 종료
        if(sa[0]=='.' && sa.length() == 1){
            break;
        }

        bool e = true;
        
        for(int i= 0; i < sa.length(); i++){
            
            c= sa[i];
        
            // [, (면 push
            if(c == '[' || c == '('){
                st.push(c);
            }
            
            // 짝이 맞으면 pop, 이미 글렀으면 해당 문자열은 아닌걸로 판명 후 끝
            if(c == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    e = false;
                    break;
                }
            }
            // ] 와 동일
            if(c== ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    e = false;
                    break;
                }
            }
        }
        
        
        if(e && st.empty()){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
        
        //남은거 빼주기
        while (!st.empty()){
            st.pop();
        }
         
    }
    return 0;
}
