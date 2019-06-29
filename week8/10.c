
#include<stdio.h>

int queue[100000000]={};

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int lights[n];
    char ch;
    for(int i=0;i<n;i++)
    {       
           scanf(" %c",&ch);
           switch(ch)
           {
               case 'G':
                        lights[i]=3;
                        break;
               case 'Y':
                        lights[i]=2;
                        break;
               case 'R':
                        lights[i]=1;
           }
    }
    int ans=0;
    int shift=0;
    int tot_shifts=0;
    int start=0,end=0;
    for(int i=0;i<n;i++)
    {
        lights[i]+=tot_shifts;
        shift=(3-(lights[i]%3))%3;
        queue[end++]=shift;
        
            tot_shifts+=shift;
            ans+=shift;
        if(i>=k-1)
        {
            tot_shifts-=queue[start++];
        }
    }
    printf("\n%d",ans);
}
