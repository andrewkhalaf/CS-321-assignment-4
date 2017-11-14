#include <iostream>
#include<time.h>
using namespace std;
#define N 100

int qselect(int A[], int p, int r, int k);
int partition(int A[], int p, int r);


void main()

{
	srand(time(NULL));
	int A[N];

	for (int i = 0; i < N; i++)
	{

		A[i] = i;

	}
	for (int i = 2; i < N; i++)
		swap(A[i], A[rand() % i + 1]);


	int median = qselect(A, 0, N-1, N / 2);


	for (int i = 0; i < N; i++)
		cout << A[i] << endl << endl;


	cout << endl;
	cout << median;

	system("pause");



}


int qselect(int A[], int p, int r, int k)
{
	if (p == r) return A[p];
	else
	{

		int q = partition(A, p, r + 1);
		int L = q - p + 1;
		if (k == L) return A[q];
		else
			if (k < L) return qselect(A, p, q - 1, k);
			else return qselect(A, q + 1, r, k - L);
	}
}

int partition(int A[], int p, int r)
{
	int pivot = A[p];
	int i = p, j = r;

	do {
		do { i++; } while (A[i] < pivot);
		do { j--; } while (A[j] > pivot);

		if (i < j) swap(A[i], A[j]);
	
	} while (i < j);

	A[p] = A[j];
	A[j] = pivot; 

	return j;


}