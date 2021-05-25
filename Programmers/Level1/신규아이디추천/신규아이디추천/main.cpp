//
//  main.cpp
//  신규아이디추천
//
//  Created by 홍진석 on 2021/05/26.
//

#include <iostream>

using namespace std;

bool isPossible(char c){
    if(c=='~' || c=='!'|| c=='@'|| c=='#'|| c=='$'|| c=='%'|| c=='^'|| c=='&'||c=='*' || c=='('|| c == '+' || c == '=' || c=='['|| c==']'|| c==')'|| c=='{'|| c=='}'|| c== ':' ||c=='?' || c==','|| c=='<'|| c=='>'|| c=='/'){
        return false;
    }
    else{
        return true;
    }
}
string solution(string new_id) {
    string answer = "";
    
    //1번 규칙
    for(int i=0; i<new_id.size(); i++){
        new_id[i] = tolower(new_id[i]);
    }
    //2번 규칙
    string a2;
    for(int i=0; i<new_id.size(); i++){
        if(isPossible(new_id[i])){
            a2 += new_id[i];
        }
    }
    
    //3번 규칙
    string a3;
    for(int i=0; i<a2.size(); i++){
        if(i ==0){
            a3 += a2[i];
        }
        else{
            if(a2[i] == '.' && a2[i-1] == '.'){
                continue;
            }
            else{
                a3 += a2[i];
            }
        }
    }
    //4번 규칙
    if(a3.front() == '.'){
        a3.erase(0,1);
    }
    if(a3.back() == '.'){
        a3.erase(a3.size()-1,a3.size());
    }
    
    //5,6,7번 규칙
    if(a3.size()==0){
        answer = "aaa";
    }
    else if(a3.size()>=16){
        
        a3.erase(15,a3.size());
        
        while(a3.back()=='.'){
            a3.erase(a3.size()-1,a3.size());
        }
    
        answer = a3;
    }
    else if(a3.size()<=2){
        int lastChar = a3.back();
        
        while(a3.size()<=2){
            a3 += lastChar;
        }
        answer = a3;
    }
    else{
        answer = a3;
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
