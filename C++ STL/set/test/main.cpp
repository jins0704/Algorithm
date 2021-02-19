//
//  main.cpp
//  test
//
//  Created by 홍진석 on 2021/02/19.
//

#include <iostream>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // 무작위로 set에 추가
    set<int> s;
    
    s.insert(10); s.insert(23); s.insert(50);
    s.insert(3);  s.insert(20); s.insert(80);
    s.insert(2);  s.insert(30);
    
    set<int>::iterator i;
    
    //set 출력 오름차순으로
    for(i=s.begin(); i!=s.end(); i++){
        cout << *i << endl;
    }

    //set에 추가
    s.insert(56);
    s.insert(123);
    cout << endl;
    
    //자동으로 오름차순으로 출력
    for(i=s.begin(); i!=s.end(); i++){
        cout << *i << endl;
    }
    
    //원소 찾기
    i = s.find(23);
    if(i != s.end()){ cout << "존재" << endl;
        //삭제도 가능 s.erase(i);
    }
    else{cout << "없음" << endl;}
    
    cout << s.size() << endl;
    return 0;
}
