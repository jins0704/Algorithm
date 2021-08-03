//
//  main.cpp
//  전화번호_목록
//
//  Created by 홍진석 on 2021/06/21.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    // for(int i=0; i< phone_book.size(); i++){
    //     cout << phone_book[i] << endl;
    // }
    for(int i=0; i< phone_book.size(); i++){
        for(int j=i+1; j< phone_book.size(); j++){
            if(phone_book[i].length() == phone_book[j].length()){break;}
            if(phone_book[i].at(0) != phone_book[j].at(0)){break;}
    
            int check = false;
            
            for(int k=0; k<phone_book[i].size(); k++){
                if(phone_book[i].at(k) != phone_book[j].at(k)){
                    check = true;
                    break;
                }
            }
            if(!check){return false;}
        }
    }
    
    return answer;
}
