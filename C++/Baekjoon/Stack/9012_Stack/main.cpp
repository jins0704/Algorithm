//
//  main.cpp
//  9012_Stack
//
//  Created by 홍진석 on 2021/02/02.
//

#include <iostream>
#include <stack>

using namespace std;
string str;
stack<char> st;

int main() {
    int N;
    
    scanf("%d",&N);
    
    while(N--){
        cin >> str;
       
        for(int i=0; i<str.length(); i++){
            if(str[i] == '('){
                st.push('(');
            }
            else{
                if(!st.empty() && st.top() =='('){
                    st.pop();
                }else{
                    st.push(')');
                    break;
                }
            }
        }
        
            
        if(st.empty()){
            printf("YES\n");
        }
        else{
            printf("NO\n");
            
            while(!st.empty()){
                st.pop();
            }
        }
    }
    
    return 0;
}
