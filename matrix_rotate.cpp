#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n][n],b[n][n];
    int i=0,j=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    int time;
    cin>>time;
    int type=time%4;
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++){
    		if(type==0)
    			b[i][j]=a[i][j];
    		if(type==1)
    			b[j][n-1-i]=a[i][j];
    		if(type==2)
    			b[n-1-i][n-1-j]=a[i][j];
    		if(type==3)
    			b[n-1-j][i]=a[i][j];
		}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
    		cout<<b[i][j]<<' ';
    	}
    	cout<<b[i][n-1];
    	cout<<endl;
	}
	for(j=0;j<n-1;j++)
		cout<<b[n-1][j]<<' ';
	cout<<b[n-1][n-1];
}
