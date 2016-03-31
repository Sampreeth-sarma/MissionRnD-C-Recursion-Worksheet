/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include "stdafx.h"
#include<stdlib.h>
void Nsnipers_rec(int , int , int **, int *,int *);
bool check(int , int , int *, int );
int solve_nsnipers(int *battlefield, int n){
	if (battlefield == NULL)
		return 0;
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	int **visited = (int **)calloc(20, sizeof(int *));
	for (int i = 0; i<20; i++)
		visited[i] = (int *)calloc(20, sizeof(int));
	int val = 0;
	 Nsnipers_rec(1, n, visited, battlefield,&val);
	 return val;
}
void Nsnipers_rec(int k, int n, int **visited, int *battlefield,int *val)
{
	for (int i = 1; i <= n; i++)
	{
		if (check(k, i, battlefield,n))
		{
			*((battlefield + (k)*n + i)) = 1;
			if (k == n)
			{
				for (int in = 1; in <= n; in++)
				{
					for (int j = 1; j <= n; j++)
					{
						if (*((battlefield + (in)*n + j)) == 1)
							visited[in][j] = 1;
						else
							visited[in][j] = 0;
					}
				}
				*val = 1;
			}
			else
				Nsnipers_rec(k + 1, n, visited, battlefield,val);
		}
	}
}
bool check(int k, int i, int *battlefield,int n)
{
	int j;
	for (j = 1; j <= k - 1; j++)
	{
		if (*((battlefield + (i)*n + j)) == 1 || abs(*((battlefield + (i)*n + j)) - i) == abs(j - k))
			return false;

	}
	return true;
}

