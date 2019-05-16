 #include<stdlib.h>
int ptr=0;
int LcsLength(double x[],double y[])
{
	int m=sizeof(x);
	int n=sizeof(y);
	int c[m+1][n+1],b[m+1][n+1];
	for(int i=0;i<=m;i++) c[i][0]=0;
	for(int i=0;i<=n;i++) c[0][i]=0;
	for(int i=0;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(x[i]==y[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			}
		}
	return c[m][n];
}
void lcs(int i,int j,double x[],int **b,double result[])//sizeof(result)=c[i][j]
{
	if(i==0||j==0) return;
	if(b[i][j]=1)
	{
		lcs(i-1,j-1,x,b,result);
		if(ptr<sizeof(result))
		{
			result[ptr]==x[i];ptr++;
		}
	}
	else if(b[i][j]==2) lcs(i-1,j,x,b,result);
	else lcs(i,j-1,x,b,result);
}
