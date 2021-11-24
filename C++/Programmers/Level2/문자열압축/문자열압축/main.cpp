//
//  main.cpp
//  문자열압축
//
//  Created by 홍진석 on 2021/08/06.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = int(s.size());

    for(int i= 1; i<=s.size()/2; i++){//자를 길이
        string str = s;
        int length = 0;
        
        while(str.size() >= i){
            string word = str.substr(0,i);
            
            str = str.substr(i,-1);
            int cnt = 1;
            
            while (str.size() >= i) {
                if(word == str.substr(0,i)){
                    cnt ++;
                    str = str.substr(i,-1);
                }
                else{break;}
            }
            
            
            length += word.size();
            if(cnt != 1){
                length += to_string(cnt).size();
            }
        }
        if(answer > length + str.size()){answer = int(length + str.size());}
    }
    return answer;
}

int main() {
    cout << solution("aaaaaaaaaa");
    
    return 0;
}
