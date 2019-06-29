#include<stdio.h>

typedef struct task{
	float ta;
	float ts;
	float tp;
	float td;	
}task;

float max(float a,float b)
{
	return a>b?a:b;
}

int main()
{
	int n;
	scanf("%d",&n);
	task tk[n];
	
	for(int i=0;i<n;i++)
	{
		scanf("%f %f",&tk[i].ta,&tk[i].tp);
	}
	
	//insertion sort
	for(int i=1; i<n; i++)
	{
		task key=tk[i];
		for(int j=i-1;j>=0;j--)
		{
			if(tk[j].ta+tk[j].tp>key.ta+key.tp)
			{
				tk[j+1]=tk[j];
			}
			
			else
			{
				tk[j+1]=key;
			}
		}
	}
	
	float tstarted=tk[0].ta;
	float totwait=0;
	printf("\nprocessing");	
	for(int i=0;i<n;i++)
	{
		//t done: starttime+processing time
		tk[i].td=tstarted+tk[i].tp;		
		//update tstarted
		tstarted=max(tk[i].td,tk[i+1].ta);
		//totwait time
		totwait+=tk[i].td-tk[i].ta;
		printf("\n%f %f",tk[i].ta,tk[i].tp);
	}
	
	float ans=(totwait)/n;
	printf("\ntotwait:%f n:%d avg:%f\n",totwait,n,ans);	
	return 0;
}
