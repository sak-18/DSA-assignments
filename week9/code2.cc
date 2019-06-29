#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int num;
    cin>>num;
    int arr[20]={};
    int top=19;
    while(num!=0)
    {
        int lbit=num%10;
        arr[top--]=lbit;
        num/=10;
    }
    
    sort(arr+top+1,arr+20,greater<int>());
    int res=1;
    for(int i=19;i>top+1;i--)
    {
        printf("%d",arr[i]);
        if(arr[i]==0)
        {
            arr[i]=9;
            if(arr[i-1]!=0)
            arr[i-1]-=1;
        }
            
    }
    for(int i=top+1;i<=19;i++)
    {    
        if(arr[i]==0)
        	continue;
        res*=arr[i];    
        
    }    
    cout<<endl<<res;
    return 0;
}
