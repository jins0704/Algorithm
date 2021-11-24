//
//  main.cpp
//  베스트앨범
//
//  Created by 홍진석 on 2021/09/06.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

struct comp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        if(a.second == b.second){ return a.first > b.first; }
        else{ return a.second < b.second; }
    }
};

bool greaterGenre(pair<string, pair<int, priority_queue<pair<int, int>,vector<pair<int, int>>,comp>>> &a, pair<string, pair<int, priority_queue<pair<int, int>,vector<pair<int, int>>,comp>>> &b){
    return a.second.first > b.second.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //장르 총수 (고유번호,재생수 정보)
    
    map <string, pair<int, priority_queue<pair<int, int>,vector<pair<int, int>>,comp>>> info;
    
    for(int i=0; i<genres.size(); i++){
        //i : 고유번호
        
        if(info.find(genres[i]) == info.end()){//발견x
            priority_queue<pair<int, int>,vector<pair<int, int>>,comp> subInfo;
            subInfo.push(make_pair(i, plays[i]));
            info.insert(make_pair(genres[i], make_pair(plays[i], subInfo)));
        }
        else{//발견
            info[genres[i]].first += plays[i];
            info[genres[i]].second.push(make_pair(i, plays[i]));
        }
    }
    
    vector<pair<string, pair<int, priority_queue<pair<int, int>,vector<pair<int, int>>,comp>>>> v(info.begin(), info.end());
    
    sort(v.begin(), v.end(), greaterGenre);

    for(int i=0; i<v.size(); i++){
        answer.push_back(v[i].second.second.top().first);
        v[i].second.second.pop();
        if(!v[i].second.second.empty()){
            answer.push_back(v[i].second.second.top().first);
        }
    }
    return answer;
}

int main() {
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};
    
    vector<int> a = solution(genres, plays);
    
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    
    return 0;
}
