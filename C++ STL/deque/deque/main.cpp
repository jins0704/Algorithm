//
//  main.cpp
//  deque
//
//  Created by 홍진석 on 2021/02/19.
//

#include <iostream>
#include <deque>

// deque는 vector의 단점을 보완한다.
// vector와 마찬가지로 배열기반 구조이다.
// vector의 경우 새로운 원소가 추가될 때 메모리 재할당 후 이전 원소 복사하는 방식으로 삽입시 성능 저하
// deque의 경우 여러개의 메모리 블록을 할당하고 하나의 블록처럼 여기는 기능을 제공
// 따라서 메모리가 부족할 때 마다 일정한 새로운 메모리 블록을 할당, 이전 원소를 복사하지 않음

using namespace std;

int main() {

    deque<int> dq(10,4); //4로 초기화 된 10개의 원소를 갖는 dq 생성
    deque<int> dq2(dq); //dq1을 복사
    
    dq.push_back(3);
    dq.push_front(1);
    
    for(int i=0; i<dq.size(); i++){
        //원소 접근
        cout << dq[i] << " ";
        //cout << dq.at(i) << " ";
    }cout << endl;

    cout << "맨앞 : " << dq.front() << " " << "맨뒤 : " << dq.back() << endl;
    
    //dq.clear(); 전부 삭제
  
    //dq.begin(), dq.end() 는 iterator와 사용
    deque<int>::iterator iter;
    
    for(iter = dq.begin(); iter != dq.end(); iter++){
        cout << *iter << " ";
    }cout << endl;
    
    cout << "dq의 사이즈 : " << dq.size() << endl;
    
    dq.resize(20); //비어있는 원소는 0으로 초기화 default
    cout << "dq 20으로 리사이즈 : ";
    for(iter = dq.begin(); iter != dq.end(); iter++){
        cout << *iter << " ";
    }cout << endl;
    
    
    cout << "dq 원소 참조 후 추가,삭제 : ";
    for(iter = dq.begin(); iter != dq.end(); iter++){
        if(*iter == 4){
            dq.erase(iter);
        }
        if(*iter == 3){
            dq.insert(iter,5);
        }
    }
    
    for(iter = dq.begin(); iter != dq.end(); iter++){
        cout << *iter << " ";
    }cout << endl;

    return 0;
}
