#include <stdio.h>

int size, low, high, A[100];

void swap(int A[], int x, int y) {
  int t = A[x];
  A[x] = A[y];
  A[y] = t;
}

int Quicksort(int A[], int low, int high) {
  if (high > low) {
    int pivot_item = Partition(A, low, high);
    Quicksort(A, low, pivot_item - 1);
    Quicksort(A, pivot_item + 1, high);
  }
}

int Partition(int A[], int low, int high) {
  int pivot_item = A[low];
  int left = low;
  int right = high;
  while (left < right) {
    while (A[left] <= pivot_item) {
      left++;
    }
    while (A[right] >= pivot_item) {
      right--;
    }
    if (left < right) {
      swap(A, left, right);
    }
  }

  A[low] = A[right];
  A[right] = pivot_item;
  return right;
}

int main() {
  printf("Enter the size: ");
  scanf("%d", &size);

  printf("Enter the elements: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &A[i]);
  }

  low = 0;
  high = size - 1;
  Quicksort(A, low, high);

  printf("The sorted elements are: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", A[i]);
  }

  return 0;
}
