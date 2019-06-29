#include<stdio.h>

int arr[100000000]={};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);    
    }
    int num=arr[n-1];
    int i;
    for( i=n-2;i>-1;i--)
    {
        if(arr[i]==num)
            continue;
    
        else
            break;
    }
    printf("%d",i+1);
    return 0;
}
