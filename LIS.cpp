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
		//�������Minv�����һ��Ԫ�ؾ�ֱ�ӷŵ���ĩβ 
		{
			Minv[len]=a[i];
			len++;
		}
		else
		{
			pos=BiSearch(Minv,len,a[i]);
			//�ҵ�Minv������0��len֮�����a[i]��Ԫ��(����ȡ����Ľϴ�Ԫ�أ��±� 
			Minv[pos]=a[i];
			//�൱����������a�е�һ��Minv[pos]<=x<Minv[pos+1]��ʹ�� 
		}
	}
	return Minv[len];
}
void SaveResult(int *a,int Lis,int *result,int len)
//Lis=LIS(a,n); Ϊ�������е����һ��Ԫ��,lenΪ�������г��� 
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
	return right;//�ϴ�ֵ 
}
