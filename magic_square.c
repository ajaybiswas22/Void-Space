/* C Program to Print Magic Square
   31 Aug,2016
 Programmer : Ajay Biswas
*/

#include<stdio.h>
#include <stdlib.h>
#define MAX 100
int ar[MAX][MAX];

void generateSquare(int);

int main(int argc, char **argv)
{
 
 int counter; 
 
    if(argc == 1) 
        printf("\ntype .\\magic_square.c size size2 ...\n"); 
    else if(argc>=2) 
    { 
        printf("\n");
        generateSquare(atoi(argv[1]));
    } 

	return 0;
}

void generateSquare(int n)
{
	int a,b,i,j,k;
	// PROCESSING

 	i=n/2;           // for assigning 1 to mid location
 	j=n-1;          //  from right
  	for(k=1;k<=(n*n);k++)
   	{
     	if(ar[i][j]==0)
     	ar[i][j]=k;

     	i++;      // Moving
     	j++;      // Diagonally

 		if(i==n&&j==n)  // Last location of Magic Square
 		{
   			i--;    // Moving Left
   			j=j-2;
 		}
 		else if(i==n)
 			i=0;
 		else if(j==n)
 			j=0;
 
 		if(ar[i][j]!=0) // If diagonal element is not empty move left
 		{
 			i--;
 			j=j-2;
 		}
    }

	// DISPLAY 
	for(a=0;a<n;a++)
	{
 		for(b=0;b<n;b++)
 		{
  			if(ar[a][b]<10)    // Aligning the table (optional)
  				printf(" ");
 			printf("%d\t",ar[a][b]);
 		}
 		printf("\n\n\n\n");
	}	
}

    
