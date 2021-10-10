//
//  main.cpp
//  1120_문자열
//
//  Created by 홍진석 on 2021/10/10.
//

#include <iostream>
#include <map>

using namespace std;

int main() {

    string a, b;
    int answer = 50;
    cin >> a >> b;
    int cnt =0;

    string major = "";
    string minor = "";
    
    if(a.size() < b.size()){ major = b; minor = a; }
    else if(a.size() >= b.size()){ major = a; minor = b; }
    
    for(int i=0; i<50; i++){
        cnt = 0;
        if(i+minor.size() > major.size()) { break; }
        for(int j=0; j<minor.size(); j++){
            if(minor[j] != major[i+j]){
                cnt ++;
            }
        }
        answer = min(answer,cnt);
    }
    
    cout << answer;
    return 0;
}


