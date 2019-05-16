#include<iostream>
using namespace std;

int iter=0;
int re[1024*1024][10];
int cal(int n,int k,int kk,int r[]){
	int i,j;
	if(n==0){
		for(i=0;i<k;i++){
			re[iter][kk-k+i]=0;
		}
		iter++;
		return 0;
	}
	if(k==1){
		re[iter][kk-k]=n;
		iter++;
		return 0;
	}
	
	for(i=n;i>=0;i--){
		re[iter][kk-k]=i;
		cal(n-i,k-1,kk,r);		
	}
	return 0;
}
int main(){
	int n,k;
	cin>>n>>k;
	int a[k];
	int r[k];
	cal(n,k,k,r);
	cout<<iter<<endl;
	int i,j,l;
	for(i=0;i<iter;i++){
		for(j=0;j<k;j++){
			for(l=0;l<re[i][j];l++){
				cout<<"*";
			}
			if(j!=k-1)
				cout<<"|";
		}
		cout<<endl;
	}
}

