
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int q;
	scanf("%d",&q);
	char a[q];
	char space,enter;
	int arr[100];
	int g =0;
	int max =-1,min = 100000;
	int freqMin=0,freqMax=0;
	scanf("%c",&enter);
	for(int i=0;i<q;i++){
		scanf("%c%c",&a[i],&enter);
		if(a[i] == 'p'){
			scanf("%d%c",&arr[g],&enter);
			if(arr[g] == max){
				freqMax+=1;
			}
			else if(arr[g]>max) {
				max = arr[g];
				freqMax=1;
			}
			if(arr[g] == min){
				freqMin+=1;
			}
			else if(arr[g]<min){
				min=arr[g];
				freqMin=1;
			}		
			g+=1;			
		}
		else if(a[i] == 'h'){
			if(freqMax == 0){
				printf("-1\n");
			}
			else{
				printf("%d\n",freqMax);
			}
		}
		else if(a[i] == 'l'){
			if(freqMin == 0){
				printf("-1\n");
			}
			else{
				printf("%d\n",freqMin);
			}
		}
		else if(a[i] == 'd'){
			printf("%d\n",(max-min) == -30001 ? -1:max-min);
			
			for(int i=0;i<g;i++){
				if(arr[i] == max){
					arr[i]=-333;
					break;
				}
			}
			for(int i=0;i<g;i++){
				if(arr[i] == min){
					arr[i]=-333;
					break;
				}
			}
			int tmp1=30000;
			for(int i=0;i<g;i++){
				if(arr[i]>0 && arr[i]<tmp1){
					tmp1 = arr[i];
				}
			}
			min = tmp1;
			
			int tmp2=-1;
			for(int i=0;i<g;i++){
				if(arr[i]>0 && arr[i]>tmp2){
					tmp2=arr[i];
				}
			}
			max = tmp2;
			freqMax = 0;
			freqMin =0;
			for(int i=0;i<g;i++){
				if(arr[i] == min){
					freqMin+=1;
				}
				else if(arr[i] == max){
					freqMax+=1;
				}
			}
			/*if(freqMax == 0){
				int tmp = -1;
				for(int j=0;j<g;j++){
					if(arr[j]>tmp && arr[j]!=max){
						tmp = arr[j];
					}
				}
				max = tmp;
				freqMax = 1;
			}
			if(freqMin == 0){
				int tmp = 100000;
				for(int j=0;j<g;j++){
					if(arr[j]<tmp && arr[j]!=min){
						tmp = arr[j];
					}
					
				}
				min = tmp;
				freqMin = 1;
			}*/
		}

	}
return 0;
}

/*
10
h
p 442
h
p 7555
d
p 2799
d
p 8543
d
d*/

