# searchmiro
백준 2178번 미로탐색 문제풀이 입니다.

## 구현계획
### 미로(miro), 방문확인(visit), 최단거리(sp) 배열을 2차원 동적배열로 만든다.
대신 미로의 주위를 벽으로 둘러쌌다고 생각하고 주위를 0으로 둘러싸는 배열을 만든다

[IMG_0037](https://user-images.githubusercontent.com/54317630/73428272-0d844780-437c-11ea-8aca-701b2309801f.jpeg)

```c++
int** miro = new int*[tc];	
int** sp = new int*[tc];
bool** visit = new bool*[tc];
for(int count = 0 ; count < tc; ++count){
miro[count] = new int[tr];
sp[count] = new int[tr];
visit[count] = new bool[tr];	
```

### visit은 전부 false로 초기화, sp는 10^23제곱으로 초기화한다
```c++

for(int i=0; i<tc; i++){	
	for(int j=0; j<tr; j++){
	
	if(1<=i && i<=c && 1<=j && j<=r){
	
	if(j==1){
	for(int t=1; t<=r; t++){
	scanf("%1d", &miro[i][t]);
	}
	
	}
	}
	
	else{
	
	miro[i][j] = 0;
	
	}
	visit[i][j] = false;
	sp[i][j] = 100000000000000000000000; // 최대수
	}
```

## 최단거리 알고리즘 (BFS) 사용.
방문 하지 않은 모든 점에 대해서 bfs를 하며 모든 점의 sp에 최단거리를 비교하며 저장한다. 그리고 방문했던 점에 대해서는 전부 visit = true 처리를 한다.
그리고 반복의 맨 처음에서 도착지점인지 계속 확인을 하며 도착지점이면 도착지점의 최단거리를 출력하며 프로그램을 종료한다.

```c++
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
	
```

## 가장 헤맸던 곳
"붙어서" 입력을 받는 것이 생소해서 조금 헤맸다. 처음에는 1011011 이런식으로 입력되는 것을 10의 몇 제곱으로 나누면서 1과 0을 구분했는데 그렇게 하면 컴퓨터가 10^23이 넘으면 표현을 못하기 때문에 가로의 길이가 24가 넘어가면 미로에 정확한 데이터가 들어가지 않았다. 그래서 알아보았는데 방법은 아주 간단했다. "scanf(%1d, &miro[i][j])" 로 입력받으면 되는 것이었다. 그렇게 프로그램을 수정 후 제출했다.

## 보충해야할 점
2차원 동적배열부터 코드가 급격히 복잡해지고 동적해제를 못하게되었다. 그래서 앞으로는 stl vector를 이용 할 것이다.
