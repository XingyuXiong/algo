#include<iostream>
using namespace std;
#define max(x,y) (x>y)?x:y

int cmp(char a[],char b[],int m,int n,int lena,int lenb){
	if(m==lena||n==lenb){
		return 0;
	}
	if(a[m]==b[n])
		return cmp(a,b,m+1,n+1,lena,lenb);
	else{
		return max(cmp(a,b,m+1,n,lena,lenb),cmp(a,b,m,n+1,lena,lenb))+1;
	}	
}
int main(){
	int N;
	cin>>N;
	char a[2*N][64];
	int len[2*N];
	int i=0,j=0;
	int sum=0;
	
	for(i=0;i<2*N;i++) {
		while(getchar()!='\n'){
			cout<<"huanhang";
			cin>>a[i][j];j++;
		}
		len[i]=j;
	}
	for(i=0;i<2*N;i++){
		int lenx=len[i];
		int leny=len[i+N];
		sum+=cmp(a[i],a[i+N],0,0,lenx,leny);
	}
	cout<<sum;
}
