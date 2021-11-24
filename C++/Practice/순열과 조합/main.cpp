//
//  main.cpp
//  순열과 조합
//
//  Created by 홍진석 on 2021/09/08.
//

#include <iostream>
#include <vector>

using namespace std;

vector<char> p;
bool check[101];
int cnt;
void permutation(vector<char> &v, int n){
    if(p.size() == n){
        for(int i=0; i< p.size(); i++){
            cout << p[i] << " ";
        }cout << endl;
        cnt++;
    }
    
    else{
        for(int i=0; i<v.size(); i++){
            if(!check[i]){
                //if(p.empty()){
                    p.push_back(v[i]);
                    check[i] = true;
                    permutation(v, n);
                    p.pop_back();
                    check[i] = false;
                //}
            }
        }
    }
}
int combination(vector<int> &v){
    // || p.back() <= v[i]
    return 0;
}
int main() {
    vector<char> v = {'a','a','b','c'};
    permutation(v,2);
    cout << cnt;
    //combination(c,5);
    
    return 0;
}
