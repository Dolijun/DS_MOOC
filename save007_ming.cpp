#include <bits/stdc++.h>
using namespace std;
using Pos = pair<int, int>;
const int maxn = 105;
Pos p[maxn];
int n, d;
int fa[maxn];
int getfa(int t){
	if(fa[t] == t)	return t;
	else	return fa[t] = getfa(fa[t]);
}
int main(){
	scanf("%d%d", &n, &d);
	for(int i = 1; i <= n; i++){
		fa[i] = i;
		scanf("%d%d", &p[i].first, &p[i].second);
		int dis = p[i].first * p[i].first + p[i].second * p[i].second;
		if(dis <= (7.5 + 1.0 * d) * (7.5 + 1.0 * d)){
			fa[getfa(i)] = getfa(0);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			int x = p[i].first - p[j].first;
			int y = p[i].second - p[j].second;
			int dis = x * x + y * y;
			if(dis <= d * d)	fa[getfa(i)] = getfa(j);	
		}
	}
	if(2 * d + 15 >= 50){
		puts("Yes");
		return 0;
	}
	for(int i = 1; i <= n; i++){
		if(getfa(i) == getfa(0)){
			int x = p[i].first, y = p[i].second;
			int dis1 = x + 50, dis2 = 50 - x;
			int dis3 = y + 50, dis4 = 50 - y;
			if(dis1 <= d || dis2 <= d || dis3 <= d || dis4 <= d){
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
