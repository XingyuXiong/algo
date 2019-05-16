#include<stdlib.h>
int BiSearch(int *a,int len,int w);
int LIS(int *a,int n)
{
	int len=1;
	int Minv[n];
	Minv[0]=a[0];
	int pos=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>Minv[len-1])
		//如果大于Minv中最后一个元素就直接放到最末尾 
		{
			Minv[len]=a[i];
			len++;
		}
		else
		{
			pos=BiSearch(Minv,len,a[i]);
			//找到Minv数组中0到len之间等于a[i]的元素(若无取最近的较大元素）下标 
			Minv[pos]=a[i];
			//相当于用在数组a中的一个Minv[pos]<=x<Minv[pos+1]，使得 
		}
	}
	return Minv[len];
}
void SaveResult(int *a,int Lis,int *result,int len)
//Lis=LIS(a,n); 为所求序列的最后一个元素,len为所求序列长度 
{
	for(int i=sizeof(a)/sizeof(int)-1;i>=0;i--)
	{
		if(a[i]<=Lis)
		{
			result[len-1]=a[i];
			len--;
		}
	}
}
int BiSearch(int *a,int len,int w)
{
	int left=0,right=len-1;
	int mid;
	while(left<=right)
	{
		mid=left+(right-left)/2;
		if(a[mid]>w)
		right=mid-1;
		else if(a[mid]<w)
		left=mid+1;
		else
		return mid;
	} 
	return right;//较大值 
}
