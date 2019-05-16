#include<stdlib.h> 
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
void knapsack(int *v,int *w,int c,int **m)
{
	int n=sizeof(v)/sizeof(int)-1;
	int jmax=min(w[n]-1,c);
	for(int j=0;j<=jmax;j++)
	m[n][j]=0;
	for(int j=w[n];j<=c;j++)
	m[n][j]=v[n];
	for(int i=n-1;i>1;i--)
	{
		jmax=min(w[i]-1,c);
		for(int j=0;j<=jmax;j++)
		m[i][j]=m[i+1][j];
		for(int j=w[i];j<=c;j++)
		m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
	}
	m[1][c]=m[2][c];
	if(c>=w[1])
	m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
}

void traceback(int **m,int *w,int c,int *x)
{
	int n=sizeof(w)/sizeof(int);
	for(int i=1;i<n;i++)
	if(m[i][c]==m[i+1][c])x[i]=0;
	else
	{
		x[i]=1;
		c-=w[i];
	}
	x[n]=(m[n][c]>0)?1:0;
}
