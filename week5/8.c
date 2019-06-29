#include<stdio.h>
#include<string.h>
int xbox[100000];
int ps4[100000];
int endx=0,endp=0;

void sort(int n,int arr[n])
{
	for(int i=0;i<n;i++)
	{
		int done=1;
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				done=0;
			}
		}
				
		if(done)
			break;		
	}
}

void print(int n,int arr[])
{
	printf("\nprinting\n");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
}

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	
	int m;
	scanf("%d",&m);
	
	for(int i=0;i<m;i++)
	{
		char* str;
		int cost;
		scanf("%d %s",&cost,str);
		printf("\n%d %s",cost,str);
		if(strcmp("XBOX",str)==0)
			xbox[endx++]=cost;
		
		else
			ps4[endp++]=cost;		
	}
	print(endx,xbox);
	print(endp,ps4);
	printf("\nps4:%d,xbox:%d",endp,endx);
	sort(endp,ps4);
	sort(endx,xbox);
	
	print(endx,xbox);
	print(endp,ps4);
	
	int countx=0,countp=0,countany=0;
	int sum=0;
	for(int i=0;i<endx && countx!=a;i++)
	{
		sum+=xbox[i];
		countx++;
	}
	
	for(int i=0;i<endp && countp!=b;i++)
	{
		sum+=ps4[i];
		countp++;
	}
	
	int p=countx,q=countp;
	
	for(int i=0;i<endx && countany!=c && p < endx && q < endp ;i++)
	{
		int y;
		
		if(xbox[p]<=ps4[q])
		{
			y=xbox[p++];
		}
		else
		{
			y=ps4[q++];
		}
		sum+=y;
		countany++;
	}
	
	
	printf("\n\n***%3d***%2d",sum,countx+countp+countany);
	
	return 0;
}
