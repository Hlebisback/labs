#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>


void show(const char * sMessage, int *piArray, int iSize)
{

	int *piCur;		
	int row, col;	

	printf("\n\t%s\n", sMessage); 

	for (row = 0, piCur = piArray; row < iSize; row++)
	{
		printf("\t%c", '+'); for (col = 0; col < iSize; col++) printf("--+"); printf("\n");						

		printf("\t%c", '|'); for (col = 0; col < iSize; col++, piCur++) printf("%2d|", *piCur); printf("\n");		

	}

	printf("\t%c", '+'); for (col = 0; col < iSize; col++) printf("--+"); printf("\n");							

}



void fill(int *piArray, int iSize)
{

	int *piCur = (piArray + iSize*iSize - 1);				
	int row, col;											

	for (row = iSize - 1; row >= 0; row--)					
	{

		for (col = iSize - 1; col >= 0; col--, piCur--)		
		{
			*piCur = rand() % 100 + 1;						
		}
	}

}


void turn_clockwise_90(int *piArray, int iSize)
{

	int *piCopy;												
	int *piCur;													
	int *piCup;													
	int row, col;												 

																
	if ((piCopy = (int *)malloc(sizeof(int)*iSize*iSize)) == NULL) {
		printf("leftturn90: Unsuffisient memory for matrix copy\n");
		return;
	}

	
	piCur = piArray;											
	piCup = piCopy;												
	for (row = 0; row < iSize; row++)							
		for (col = 0; col < iSize; col++)						
		{
			*piCup = *piCur;									
			piCur++;											
			piCup++;											
		}



	piCur = piArray;											

																
	for (col = iSize - 1; col >= 0; col--)						
	{
		for (row = 0; row < iSize; row++)						
		{
			piCup = piCopy + (row*iSize + col);					
			*piCur = *piCup;									
			piCur++;											
		}
	}

	free(piCopy);
}



int main(int argc, char** argv)
{

	int *Ar; 
	int S;   


			
	printf("Enter the matrix size : ");
	scanf_s("%d", &S);

	
	if (S <= 0) {
		printf("The size is too low\n");
		exit(0);
	}
	else if (S>24) {
		printf("The size is too big\n");
		exit(0);
	}
	else
		printf("Matrix size is - %dX%d\n", S, S);

	
	if ((Ar = (int *)malloc(sizeof(int)*S*S)) == NULL) {
		printf("Unsuffisient memory\n");
		exit(0);
	}

	fill(Ar, S);												

	show("Initial matrix :", Ar, S);							

	turn_clockwise_90(Ar, S); 									

	show("Turned matrix :", Ar, S);								

	_getch();													

	return 0;
}

