#include <stdio.h>
#include <vector>

using namespace std;
#define MAX_BOLTS 500
#define MAX_NUTS 500

int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS];
void read_input_data(void){
	int n,b;
	scanf("%d%d",&bolts,&nuts);
	for(b=0;b<bolts;b++){
		for(n=0;n<nuts;n++){
			scanf("%d",&fits[b][n]);
		}
	}
}

vector<int> match, vis;

int Aug(int l) {
	if (vis[l]) return 0;
	vis[l] = 1;
	for (int r = 0; r < bolts; r++) {
		if (fits[r][l] == 0) continue;
		if (match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int main(){
	int cases,caseno;
	scanf("%d",&cases);
	for(caseno=1;caseno<=cases;caseno++){
		read_input_data();
		int MCBM = 0;
		match.assign(nuts+bolts, -1);
		for (int l = 0; l < nuts; l++) {
			vis.assign(nuts+bolts, 0);
			MCBM += Aug(l);
		}
		printf("Case %d: ",caseno);
		printf("a maximum of %d nuts and bolts ",MCBM);
		printf("can be fitted together\n");
	}
	return 0;
}
