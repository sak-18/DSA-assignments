#include<stdio.h>

int flag;
int a[10][10];
int max_row[10], max_col[10], min_row[10], min_col[10];
int x, y;

bool is_saddle(int i, int j) {
    int x = a[i][j];
    return (min_row[i] == x && max_col[j] == x);
}

int main() {
    // code to input x, y and the matrix
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		printf("fill in a[%d][%d]",i,j);
    		scanf("%d %d",&m,&n);
    	}
    }
    

    /* code to visualize the matrix
    ...
    */

    /* populating max and min arrays */
    for (int i = 0; i <= x-1; ++i) {
        max_row[i] = a[i][0], min_row[i] = a[i][0];
        for (int j = 0; j <= y-1; ++j) {
            max_row[i] = max(max_row[i], a[i][j]);
            min_row[i] = min(min_row[i], a[i][j]);
        }
    }

    for (int j = 0; j <= y-1; ++j) {
        max_col[j] = a[0][j], min_col[j] = a[0][j];
        for (int i = 0; i <= x-1; ++i) {
            max_col[j] = max(max_col[j], a[i][j]);
            min_col[j] = min(min_col[j], a[i][j]);
        }
    }

    /* Check for saddle point */
    for (int i = 0; i <= x-1; ++i) {
        for (int j = 0; j <= y-1; ++j) {
            if (is_saddle(i, j)) {
                printf("Saddle points are: ");
                printf("a[%d][%d]=%d",i+1,j+1,a[i][j]);
                flag = 1;
            }
        }
    }

    if (flag == 0) {
        printf("No saddle points\n");
    }
    printf("----------------------------\n");
    return 0;
}
