/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
#include<malloc.h>
int *spiral_rec(int, int, int **,int,int,int *,int,int);

int *spiral(int rows, int columns, int **input_array)
{

	if (rows <= 0 || columns <= 0)
		return NULL;
	if (input_array == NULL)
		return NULL;
	int  *arr, total = rows*columns;

	arr = (int*)malloc(total*sizeof(int));
	int *res= (int *)malloc(total*sizeof(int));
	if (total == 1)
		arr[0] = input_array[0][0];
	else
	arr = spiral_rec(rows, columns, input_array,0,0,res,0,total);
	return arr;
}
int *spiral_rec(int rows,int columns,int **input_array,int starti,int startj,int *res,int pos,int total)
{
	int i, j;
	if (pos<total)
	for ( j = startj; j < columns; j++)
	{
		res[pos++] = input_array[starti][j];
	}
	j = columns - 1;
	if (pos<total)
	for ( i = starti + 1; i < rows; i++)
	{
		res[pos++] = input_array[i][j];
	}
	i =i - 1;
	if (pos<total)
	for (j = j - 1; j >= startj; j--)
	{
		res[pos++] = input_array[i][j];
	}
	 j = j + 1;
	 if (pos<total)
	 for (i = i - 1; i > starti; i--)
	 {
		 res[pos++] = input_array[i][j];
	 }
	 if (pos<total)
	 spiral_rec(rows-1, columns-1, input_array, starti + 1, startj + 1,res,pos,total);
	 return res;
}
