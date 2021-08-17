/******************************************************************************

Autor: Scott Madeux
Hergestellt: 06.08.2021

Das ist ein Repository von Testfunktionen die haben benutzt sein um die IAR und
GCC Compilers zu vergleichen. Sehen Sie das Testdokument für weiter information
zu nutzung diesen Tests.

*******************************************************************************/
#include <stdlib.h>

#define SORT_ARRAY_SIZE 20

void Random_Int_Array(int array[], int size)
{
	for(int i = 0; i < size; i++)
	{
		array[i] = rand();
	}
}

void Test_Matrix_Dot_Produkt()
{
	int M1[10][10] = {{1,2,3,4,5,6,7,8,9,10},
					  {1,2,3,4,5,6,7,8,9,10},
					  {1,2,3,4,5,6,7,8,9,10},
					  {1,2,3,4,5,6,7,8,9,10},
					  {1,2,3,4,5,6,7,8,9,10},
					  {1,2,3,4,5,6,7,8,9,10},
					  {1,2,3,4,5,6,7,8,9,10},
					  {1,2,3,4,5,6,7,8,9,10},
					  {1,2,3,4,5,6,7,8,9,10},
					  {1,2,3,4,5,6,7,8,9,10}};
					  
	int ret_matrix[10][10];
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			int sum = 0;
			for(int k = 0; k < 10; k++)
			{
				sum += M1[i][k] * M1[k][j];
			}
			ret_matrix[i][j] = sum;
		}
	}
}

char Test_Switch_Case_Seq(int num)
{
  char x = '\n';
	switch(num)
	{
		case 1:
			x = 'A';
			break;
		case 2:
			x = 'B';
			break;
		case 3:
			x = 'C';
			break;
		case 4:
			x = 'D';
			break;
		case 5:
			x = 'E';
			break;
		case 6:
			x = 'F';
			break;
		case 7:
			x = 'G';
			break;
		case 8:
			x = 'H';
			break;
		case 9:
			x = 'I';
			break;
		case 10:
			x = 'J';
			break;
		default:
			x = 'Z';
			break;
	}
	
	return x;
}

char Test_Switch_Case_Nicht_Seq(int num)
{
	char x = '\n';
	switch(num)
	{
		case 1:
			x = 'A';
			break;
		case 5:
			x = 'B';
			break;
		case 8:
			x = 'C';
			break;
		case 12:
			x = 'D';
			break;
		case 35:
			x = 'E';
			break;
		case 36:
			x = 'F';
			break;
		case 86:
			x = 'G';
			break;
		case 22:
			x = 'H';
			break;
		case 85:
			x = 'I';
			break;
		case 99:
			x = 'J';
			break;
		default:
			x = 'Z';
			break;
	}
	
	return x;
}

int Test_Dividier_Zufaellige_Int(int i)
{
	int r = 100 + rand();
	int x = r / i;
	return x;
}

float Test_Dividier_Zufaellige_Float(int i)
{
	float r = ((float)rand()/RAND_MAX)*(float)(100.0);
	float x = r / i;
	return x;
}

void Test_Bubble_Sort()
{
	int array[SORT_ARRAY_SIZE];
	Random_Int_Array(array, SORT_ARRAY_SIZE);

	int a = 0;
	int b = 1;
	int switchCount = 0;
	int temp;

	do
	{
		a = 0;
		b = 1;
		switchCount = 0;
		for(;b < SORT_ARRAY_SIZE; a++, b++)
		{
			if(array[a] > array[b])
			{
				temp = array[a];
				array[a] = array[b];
				array[b] = temp;
				switchCount++;
			}
		}
	} while(switchCount > 0);
}

void Test_printf()
{
	printf("Hello STM32H743ZI\n");
}