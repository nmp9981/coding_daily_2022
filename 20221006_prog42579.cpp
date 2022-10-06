#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string,int> playNum;//재생 횟수
vector<pair<string,int>> playNumVec;//재생 횟수 벡터
vector<pair<int,pair<string,int>>> playList;//재생 횟수, 장르, 인덱스

//재생 횟수기준 내림차순
bool cmp(pair<string,int> a,pair<string,int>b){
    return a.second > b.second;
}
//플레이, 인덱스 기준 정렬
bool compair(pair<int,pair<string,int>> a,pair<int,pair<string,int>> b){
    if(a.first==b.first){//낮은 인덱스
        return a.second.second<b.second.second;
    }
    return a.first > b.first;//재생 수 기준
}

//재생 앨범 목록
void Album(vector<string> genres, vector<int> plays){
    for(int i=0;i<genres.size();i++){
        playNum[genres[i]]+=plays[i];//재생 횟수 추가
        playList.push_back({plays[i],{genres[i],i}});//재생 횟수, 장르, 인덱스
    }
    for(auto iter:playNum){
        playNumVec.push_back({iter.first,iter.second});//장르명, 총 재생 횟수
    }
    sort(playNumVec.begin(),playNumVec.end(),cmp);//총 재생 횟수 기준 내림차순
    sort(playList.begin(),playList.end(),compair);//플레이, 인덱스 기준 정렬
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    Album(genres,plays);//재생 앨범 목록
    //앨범 정리
    vector<int> answer;
    for(int i=0;i<playNumVec.size();i++){//총 재생 횟수 순 장르
        int cnt = 0;
        for(int j=0;j<playList.size();j++){
            string name = playList[j].second.first;//장르명
            if(name==playNumVec[i].first){//장르명이 동일
                answer.push_back(playList[j].second.second);//인덱스
                cnt++;
            }
            if(cnt>=2) break;//각 장르당 최대 2개씩
        }
    }
    return answer;
}
