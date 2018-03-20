#include<stdio.h>
#include<limits.h>

#define		NUMNUM 16
#define		NTHR	4
#define		TNUM	(NUMNUM/NTHR)

int nums[NUMNUM] = {2,3,5,7,5,6,10,12,1,7,8,10,3,5,7,9};
int snums[NUMNUM];


void
merge()
{
	int	idx[NTHR];
	int	i,sidx,minidx,num;

	for (i = 0; i < NTHR; i++)
		idx[i] = i*TNUM;
	for (sidx = 0; sidx < NUMNUM; sidx++)
	{
		num = INT_MAX;
		for (i = 0; i < NTHR; i++)
		{
			if((idx[i] < (i+1)*TNUM) && (nums[idx[i]] < num))
			{
				num = nums[idx[i]];
				minidx = i;
			}
		}

		snums[sidx] = nums[idx[minidx]];
		idx[minidx]++;
	}
}

int
main()
{	
	int j;

	int nums[NUMNUM] = {2,3,5,7,5,6,10,12,1,7,8,10,3,5,7,9};
	int snums[NUMNUM];
	merge();
	
	for (j = 0; j < NUMNUM; j++)
	{
		printf("%d/t",snums[j]);
	}

	return 0;
}
