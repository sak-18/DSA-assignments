#include<stdio.h>
int count=0;
void print(int n,int arr[n])
{
	printf("\n******************************\n");
	for(int i=0;i<n;i++)
	{
			printf("%d ",arr[i]);
	}		
	printf("\n******************************\n");
}


void merge(int starta,int mid,int endb,int arr[])
{
	if(starta==endb)
	{
		return;
	}
	int startb=mid+1;
	int enda=mid;
	int done=0;
	int i=starta,j=startb,k=0;
	int len=endb-starta+1;
	int new[len];
	int x;
	while(!done)
	{
		if(arr[i]<arr[j])
		{
			new[k++]=arr[i];
			i++;
		}
		else
		{
			new[k++]=arr[j];
			j++;
		}
		
		if(i>enda||j>endb)
		{			
			(i>enda)?(x=j):(x=i);
			done=1;			
		}
	}
	
	for(;k<len;k++)
	{
		new[k]=arr[x++];
	}
	int s=starta;
	//copy it into arr
	for(int p=0;p<len;p++)
	{
		arr[s++]=new[p];
	}
	print(len,new);
}


int mergesort(int l,int r,int arr[])
{
	int mid=(l+r)/2;
	if(l!=r)
	{
		mergesort(l,mid,arr);
		mergesort(mid+1,r,arr);
	}
	
	for(int x=l,y=mid+1;x<=mid && y<=r;)
	{
		if(arr[x]<arr[y])
		{
			x++;
		}
		else
		{
			count+=mid-x+1;
			y++;
		}
	}
	merge(l,mid,r,arr);		
	return count;
}

/*int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	mergesort(0,n-1,arr);	
	
	return 0;
}*/
