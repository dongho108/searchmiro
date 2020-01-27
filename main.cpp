//
//  main.cpp
//  백준미로탐색
//
//  Created by dongho on 2020/01/15.
//  Copyright © 2020 dongho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int r, c; //가로 i, 세로 j
    cin >> c >> r;
    
    //미로, 최단거리 기록 배열, 방문확인 배열
    int** miro = new int*[r];
    int** sp = new int*[r];
    bool** visit = new bool*[r];
    for(int count = 0 ; count < r; ++count){
        miro[count] = new int[c];
        sp[count] = new int[c];
        visit[count] = new bool[c];
    }
    
    //미로 민들기, visit배열 초기화, sp배열 초기화
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> miro[i][j];
            visit[i][j] = false;
            sp[i][j] = 10000000; // 최대수
        }
    }
    sp[0][0] = 1;
    //bfs하면서 최단거리 기록
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            queue <int> x;
            queue <int> y;
            x.push(i);
            x.push(j);
            
            while(!x.empty()){
                int xt = x.front();
                int yt = y.front();
                x.pop();
                y.pop();
                //다음 연결되어있느면(1이면) 확인하고 최단거리 바꿔주기
                //방문했으면 visit true
                //
            }
        }
    }
    
    
    
    

}

//
