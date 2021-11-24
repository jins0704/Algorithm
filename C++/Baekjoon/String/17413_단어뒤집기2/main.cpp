//
//  main.cpp
//  17413_단어뒤집기2
//
//  Created by 홍진석 on 2021/10/10.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string storeStr;

string backStr(){
    string returnS = "";
    
    for(int i=0; i< storeStr.size(); i++){
        returnS += storeStr[storeStr.size()-1-i];
    }
    storeStr.clear();
    
    return returnS;
}

int main() {
    string s;
    string answer = "";
    getline(cin, s);
    int idx = 0;
    while(idx < s.size()){
        if(s[idx] == '<'){
            if(storeStr.size() != 0){
                //지금까지 저장한 문자열 뒤집어서 넣기
                string newS = backStr();
                answer += newS;
                storeStr.clear();
            }
            string newS = "<";
            for(int i = idx+1; i<s.size(); i++){
                newS += s[i];
                if(s[i] == '>') {
                    idx = i+1;
                    answer += newS;
                    break;
                }
            }
        }
        else if(s[idx] == ' '){
            if(storeStr.size() != 0){
                //지금까지 저장한 문자열 뒤집어서 넣기
                string newS = backStr();
                answer += newS;
                storeStr.clear();
            }
            idx++;
            answer += ' ';
        }
        
        else{
            storeStr += s[idx];
            idx++;
        }
    }
    
    if(storeStr.size() != 0){
        string newS = backStr();
        answer += newS;
    }
    cout << answer;
    return 0;
}

