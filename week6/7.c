#include<stdio.h>

typedef struct car
{
	int price;
	int fuel;
}car;

void print(int n,int arr[])
{
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}



void sortcars(int n,car arr[n])
{
	for(int i=0;i<n;i++)
	{
		int done=1;
		for(int j=0;j<n-1;j++)
		{
			if(arr[j].price>arr[j+1].price)
			{
				car temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				done=0;
			}
		}
				
		if(done)
			break;		
	}
	printf("\n");
}
//O(n^2)


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
	//print(n,arr);
	printf("\n");
}

int main()
{
	int n,k,s,t;
	scanf("%d %d %d %d",&n,&k,&s,&t);
	
	car details[n];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&details[i].price,&details[i].fuel);		
	}	
	
	int station[k];
	
	for(int i=0;i<k;i++)	
		scanf("%d",&station[i]);
	
	print(k,station);
	sort(k,station);	
	sortcars(n,details);
	int time,fuel,dist,sno;
	
	for(int i=0;i<n;i++)
	{
		printf("\nTrying car %d rent-%d fuel-%d\n",i+1,details[i].price,details[i].fuel);
		time=0,dist=0,sno=0,fuel=details[i].fuel;
		printf("\nDist Time Fuel");
		while(dist<s && time<t)
		{

			//fill tank
			if(sno<k && dist>=station[sno])
			{
				fuel=details[i].fuel;
				sno++;				
			}
						//exit
			if(fuel<=0)
				break;
				
			printf("\n%4d %4d %4d",dist,time,fuel);
			//calculate next state if traveled in high speed
			int fnext=fuel-2;
			int dist_station=station[sno]-(dist+1);
			// if satisfied go with high speed(mode 1)
			if( ( sno<k && fnext >= dist_station) || (sno>=k && fnext>=(s-(dist+1))))
			{
				dist+=1;
				time+=1;
				fuel-=2;										
			}
			else
			{
				dist+=1;
				time+=2;
				fuel-=1;
			}
		}
		
		if(time>t || dist<s)
		{
			continue;
		}
		else
		{
			printf("\nMininmum rent:%d,fuel capacity:%d",details[i].price,details[i].fuel);			
			return 0;
		}	
		
	}
	printf("\n%d",-1);	
	return 0;
}
