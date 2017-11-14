#include <iostream>
using namespace std;

void main()

{





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