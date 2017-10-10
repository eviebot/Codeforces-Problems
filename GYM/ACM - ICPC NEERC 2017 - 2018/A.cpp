#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int p[110][4];
	cin>>n;
	for(int i = 0; i < 110; i++){
		p[i][0] = p[i][1] = p[i][2] = p[i][3] = -1;
	}
	for(int i = 0; i < n; i++){
		cin>>p[i][1]>>p[i][2];
		p[i][1]--;
		p[i][2]--;
		if(p[i][0] == -1)
			p[i][0] = p[i][1];
		if(p[i][3] == -1)
			p[i][3] = p[i][2];
		if(p[i][1] != -1)
			p[i][0] = p[p[i][1]][0];
		if(p[i][2] != -1)
			p[i][3] = p[p[i][2]][3];
		if(p[i][0] != -1){
			for(int j = 0; j < i; j++){
				if(p[j][0] == i){
					p[j][0] = p[i][0];
				}
			}
		}
		if(p[i][3] != -1){
			for(int j = 0; j < i; j++){
				if(p[j][3] == i){
					p[j][3] = p[i][3];
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(p[i][2] == -1){
			for(int j = i + 1; j < n; j++){
				if(p[j][1] == -1 && p[i][0] != j){
					p[j][1] = i;
					p[j][0] = p[i][0];
					p[i][2] = j;
					p[i][3] = p[j][3];
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout<<p[i][1] + 1<<" "<<p[i][2] + 1<<endl;
	}
}