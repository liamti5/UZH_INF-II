#include <stdio.h>

int largest(int A[], int l, int r) {
	int mid = (l + r)/2;
	if (l==r) return A[l];
	else if (A[mid] < A[mid +1]) {
		return largest(A, mid +1, r); 
	}
	else {
		return largest(A, l, mid); 
	}
} 

int main() {
	int A[] = {1, 4, 7, 8,  2, 0};
	printf("%d", largest(A, 0, 5)); 
}