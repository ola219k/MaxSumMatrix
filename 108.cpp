#include <bits/stdc++.h>
using namespace std;

#define fi "108.INP"
#define fo "108.OUT"
#define ROW 100
#define COL 100

int kadane(int *arr, int *start, int *finish, int n)
{
	int sum = 0, maxElement = INT_MIN, i;

	*finish = -1;

	int local_start = 0;

	for (i = 0; i < n; ++i)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > maxElement)
		{
			maxElement = sum;
			*start = local_start;
			*finish = i;
		}
	}

	if (*finish != -1)
		return maxElement;

	maxElement = arr[0];
	*start = *finish = 0;

	for (i = 1; i < n; i++)
	{
		if (arr[i] > maxElement)
		{
			maxElement = arr[i];
			*start = *finish = i;
		}
	}
	return maxElement;
}

void findMaxSum(int A[][COL], int n)
{
	int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
	int left, right, i;
	int temp[n], sum, start, finish;
	for (left = 0; left < n; ++left)
	{
		memset(temp, 0, sizeof(temp));
		for (right = left; right < n; ++right)
		{
			for (i = 0; i < n; ++i)
			{
				temp[i] += A[i][right];
			}
			sum = kadane(temp, &start, &finish, n);
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}

	printf("%d\n", maxSum);
}

void run(int A[][COL])
{
	freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &A[i][j]);
			}
		}
		findMaxSum(A, n);
	}
}

int main()
{
	int A[ROW][COL];
	run(A);
	return 0;
}
