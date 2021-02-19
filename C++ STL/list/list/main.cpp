//
//  main.cpp
//  list
//
//  Created by 홍진석 on 2021/02/19.
//

//list : sequence container - 순서를 유지하는 구조
//double linked list - 이중 연결 리스트라고 생각
//vetor, deque 와 다른점은 sort, merge, splice(이어붙이기)가 가능
#include <iostream>
#include <list>

using namespace std;

int main() {
    
    list<int> list1;
    list<string> list2;
    
    list<int> lt(3,2); //2값으로 초기화 된 원소 3개
    list<int> lt2(lt); //lt 복사
    
    cout << "맨앞원소 " << lt.front() << endl;
    cout << "맨뒤원소 " << lt.back() << endl;
    cout << "사이즈 "<< lt.size() << endl;
    
    //참조 객체
    list<int>::iterator iter;
    iter = lt.begin();
    //iter = lt.end();
    
    // 앞뒤로 넣고 빼기 가능
    lt.push_back(4); //lt.push_front(4);
    lt.pop_back(); //lt.pop_front();
    
    cout << "첫 상태 : ";
    for(iter = lt.begin(); iter != lt.end(); iter++){
        cout << *iter << " ";
    }cout << endl;
    
    for(iter = lt.begin(); iter != lt.end(); iter++){

        if(*iter == 2){
            cout << "2 발견, 내맘대로 삭제 추가 : 1,2,3 " << endl;
            lt.insert(iter,1); //iter가 가르키는 원소 3 삽입
            lt.insert(iter,2);
            lt.insert(iter,3);
            lt.erase(iter);
        }
    }
    
    for(iter = lt.begin(); iter != lt.end(); iter++){
        cout << *iter << " ";
    }cout << endl;
    
    // 2와 같은 원소 모두 제거
    lt.remove(2);
    cout << "2 제거 : ";
    for(iter = lt.begin(); iter != lt.end(); iter++){
        cout << *iter << " ";
    }cout << endl;
    
    // 순서 전부 뒤집기
    lt.reverse();
    cout << "순서뒤집기 : ";
    for(iter = lt.begin(); iter != lt.end(); iter++){
        cout << *iter << " ";
    }cout << endl;
    
    //default 오름차순으로 정렬
    lt.sort();
    cout << "정렬하기 ㅣ ";
    for(iter = lt.begin(); iter != lt.end(); iter++){
        cout << *iter << " ";
    }cout << endl;
    
    //중복제거 (인접하며 중복할때만 적용된다.)
    lt.unique();
    for(iter = lt.begin(); iter != lt.end(); iter++){
        cout << *iter << " ";
    }cout << endl;
    
    return 0;
}

