#include<stdlib.h>
int Partition(double a[],int low,int high);
void QSort(double a[],int left,int right)
{
	if(left<right)
	{
		double pos=Partition(a,left,right);
		QSort(a,left,pos-1);
		QSort(a,pos+1,right); 
	}
}
int Partition(double a[],int low,int high)
{
	double pivot=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>pivot) --high;
		a[low]=a[high];
		while(low<high&&a[low]<=pivot) ++low;
		a[high]=a[low];
	}
	a[low]=pivot;
	return low;
}

