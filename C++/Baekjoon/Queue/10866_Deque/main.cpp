//
//  main.cpp
//  10866_Deque
//
//  Created by 홍진석 on 2021/01/26.
//

#include <iostream>
#include <deque>

using namespace std;
deque<int> d;
string s;
int n;
int N;
int tmp;
int main() {
    
    cin >> N;
    
    while (N--) {
        cin >> s;
        if(s == "push_back"){
            cin >> n;
            d.push_back(n);
        }
        else if(s == "push_front"){
            cin >> n;
            d.push_front(n);
        }
        else if(s == "pop_back"){
            if(!d.empty()){
                tmp = d.back();
                d.pop_back();
                cout << tmp << endl;
            }else{
                cout << "-1" << endl;
            }
        }
        else if(s == "pop_front"){
            if(!d.empty()){
                tmp = d.front();
                d.pop_front();
                cout << tmp << endl;
            }else{
                cout << "-1" << endl;
            }
        }
        else if(s == "size"){
            cout << d.size() << endl;
        }
        else if(s== "empty"){
            if(d.empty()){
                cout << "1" << endl;
            }else{
                cout << "0" << endl;
            }
        }
        else if(s== "front"){
            if(!d.empty()){
                cout << d.front() << endl;
            }else{
                cout << "-1" << endl;
            }
        }
        else{
            if(!d.empty()){
                cout << d.back() << endl;
            }else{
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}
