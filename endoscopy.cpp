/*
https://www.hackerearth.com/problem/algorithm/question-7-4
*/

#include <bits/stdc++.h>
using namespace std;
struct Node{
	bool left, right, top, bottom;
};

int n, m, srx, sry, len;
Node pipes[1001][1001];
int vis[1001][1001], dis[1001][1001];
int arr[1001][1001];
int result;

bool isValid(int i, int j){
	return (i>=0 && i<n && j>=0 && j<m);
}
void bfs(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			dis[i][j] = 0, vis[i][j] = 0;
		}
	}
	result = 1;
	queue<pair<int, int>>q;
	if(arr[srx][sry] == 0){
		result = 0;
		return;
	}
	vis[srx][sry] = 1;
	dis[srx][sry] = 1;
	q.push({srx, sry});
	while(!q.empty()){
		auto elem = q.front();
		q.pop();
		int x = elem.first;
		int y = elem.second;
		if(dis[x][y] >= len) continue;
		//left
		if(isValid(x,y-1) && !vis[x][y-1] && pipes[x][y-1].right && pipes[x][y].left){
			vis[x][y-1] = 1;
			dis[x][y-1] = dis[x][y] + 1;
			result++;
			q.push({x,y-1});
		}
		//right
		if(isValid(x,y+1) && !vis[x][y+1] && pipes[x][y+1].left && pipes[x][y].right){
			vis[x][y+1] = 1;
			dis[x][y+1] = dis[x][y] + 1;
			result++;
			q.push({x,y+1});
		}
		//top
		if(isValid(x-1,y) && !vis[x-1][y] && pipes[x-1][y].bottom && pipes[x][y].top){
			vis[x-1][y] = 1;
			dis[x-1][y] = dis[x][y] + 1;
			result++;
			q.push({x-1,y});
		}
		//bottom
		if(isValid(x+1,y) && !vis[x+1][y] && pipes[x+1][y].top && pipes[x][y].bottom){
			vis[x+1][y] = 1;
			dis[x+1][y] = dis[x][y] + 1;
			result++;
			q.push({x+1,y});
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>srx>>sry>>len;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>arr[i][j];
				if(arr[i][j] == 0){
					pipes[i][j].left = false;
					pipes[i][j].right = false;
					pipes[i][j].top = false;
					pipes[i][j].bottom = false;
				}else if(arr[i][j] == 1){
					pipes[i][j].left = true;
					pipes[i][j].right = true;
					pipes[i][j].top = true;
					pipes[i][j].bottom = true;
				}else if(arr[i][j] == 2){
					pipes[i][j].left = false;
					pipes[i][j].right = false;
					pipes[i][j].top = true;
					pipes[i][j].bottom = true;
				}else if(arr[i][j] == 3){
					pipes[i][j].left = true;
					pipes[i][j].right = true;
					pipes[i][j].top = false;
					pipes[i][j].bottom = false;
				}else if(arr[i][j] == 4){
					pipes[i][j].left = false;
					pipes[i][j].right = true;
					pipes[i][j].top = true;
					pipes[i][j].bottom = false;
				}else if(arr[i][j] == 5){
					pipes[i][j].left = false;
					pipes[i][j].right = true;
					pipes[i][j].top = false;
					pipes[i][j].bottom = true;
				}else if(arr[i][j] == 6){
					pipes[i][j].left = true;
					pipes[i][j].right = false;
					pipes[i][j].top = false;
					pipes[i][j].bottom = true;
				}else{
					pipes[i][j].left = true;
					pipes[i][j].right = false;
					pipes[i][j].top = true;
					pipes[i][j].bottom = false;
				}
			}
		}
		bfs();
		cout<<result<<"\n";
	}
	return 0;
}
