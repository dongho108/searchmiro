//
//  main.cpp
//  백준미로탐색
//
//  Created by dongho on 2020/01/15.
//  Copyright © 2020 dongho. All rights reserved.
//

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int main() {
    int c, r;
    cin >> c >> r;
    
    int tr = r+2; //실제 만들어지는 미로의 크기 (입력되는 미로 주위를 0으로 둘러쌈)
    int tc = c+2;
    
    //미로, 최단거리 기록 배열, 방문확인 배열
    int** miro = new int*[tc];
    int** sp = new int*[tc];
    bool** visit = new bool*[tc];
    for(int count = 0 ; count < tc; ++count){
        miro[count] = new int[tr];
        sp[count] = new int[tr];
        visit[count] = new bool[tr];
    }
    
    //붙어서입력된다. 각 행씩. 가로길이입력따라 자리수가 1인지 0인지 판별해서 배열에 입력해야한다.
    //한줄 입력을 10의 제곱으로 나누면 몫이 1아니면 0이 나온다. 이 점을 이용해서 미로에 1과 0을 입력시킨다.
     
    //미로 민들기, visit배열 초기화, sp배열 초기화
    //미로 주위를 0으로 채우야한다.
    int num;
    int mok;
    int temp;
    for(int i=0; i<tc; i++){
        for(int j=0; j<tr; j++){
            
            if(1<=i && i<=c && 1<=j && j<=r){
                
                if(j==1){
                    cin >> num;
                    temp = j;
                    for(int b=(r-1); b>=0; b--){
                        
                        mok = num / int(pow(10,b));
                        num = num % int(pow(10,b));
                        miro[i][temp++] = mok;
                        
                    }
                }
            }
                
            else{
                
                miro[i][j] = 0;
                
            }
            
            visit[i][j] = false;
            sp[i][j] = 10000000; // 최대수
        }
    }
    
    sp[1][1] = 1;
    //bfs하면서 최단거리 기록
    //1,1 부터 시작
    for(int i=1; i<tr; i++){
        for(int j=1; j<tc; j++){
            if(visit[i][j] == true)
                continue;
            
            queue <int> x;
            queue <int> y;
            x.push(i);
            y.push(j);
            
            while(!x.empty()){
                int xt = x.front();
                int yt = y.front();
                visit[xt][yt] = true;
                x.pop();
                y.pop();
                //다음 연결되어있느면(1이면) 확인하고 최단거리 바꿔주기
                //동 (y+1)
                //동쪽에 길이있고, 방문한 적이 없으면->이건 한번 더 생각해보기 ->해야함
                
                //마지막 도착하면 끝내기
                if(xt == c && yt == r){
                    cout << sp[xt][yt];
                    return 0;
                }
                    
                
                if(miro[xt][yt+1] == 1 && visit[xt][yt+1] == false){
                    if(sp[xt][yt] + 1 < sp[xt][yt+1])
                        sp[xt][yt+1] = sp[xt][yt] + 1;
                    x.push(xt);
                    y.push(yt+1);
                    visit[xt][yt+1] = true;
                }
                //서 (y-1)
                if(miro[xt][yt-1] == 1 && visit[xt][yt-1] == false){
                    if(sp[xt][yt] + 1 < sp[xt][yt-1])
                        sp[xt][yt-1] = sp[xt][yt] + 1;
                    x.push(xt);
                    y.push(yt-1);
                    visit[xt][yt-1] = true;
                }
                //남 (x+1)
                if(miro[xt+1][yt] == 1 && visit[xt+1][yt] == false){
                    if(sp[xt][yt] + 1 < sp[xt+1][yt])
                        sp[xt+1][yt] = sp[xt][yt] + 1;
                    x.push(xt+1);
                    y.push(yt);
                    visit[xt+1][yt] = true;
                }
                //북 (x-1)
                if(miro[xt-1][yt] == 1 && visit[xt-1][yt] == false){
                    if(sp[xt][yt] + 1 < sp[xt-1][yt])
                        sp[xt-1][yt] = sp[xt][yt] + 1;
                    x.push(xt-1);
                    y.push(yt);
                    visit[xt-1][yt] = true;
                }
                //방문했으면 visit true
                
             
            }
        }
    }
    
    
    
    

}

//
