
#include<stdio.h>
	int main()
	{
	    int n,ans=0;
	    scanf("%d",&n);
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&a[i]);
	    }
	    if(a[0]-a[1]<0)
	    {
	        printf("inside loop\n");
	        //a[0]=a[1];
	        ans=ans+a[1]-a[0];
	        a[0]=a[1];
	    }
	    for(int i=1;i<n-1;i++)
	    {
	        if(a[i]-a[i+1]<0)
	        {
	            if(a[i-1]>=a[i+1])
	            {
	                ans=ans+a[i+1]-a[i];
	                a[i]=a[i+1];
	            }
	            else if(a[i-1]<a[i+1])
	            {
	                ans=ans+a[i+1]-a[i];
	                a[i]=a[i-1];
	                a[i+1]=a[i-1];
	            }
	        }
	    }
	    printf("%d\n",ans);
	    return 0;
	}
 
