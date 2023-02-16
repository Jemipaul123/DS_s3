#include<stdio.h>

int temp[100];
int arr[100];
int low;
int high;

void merge_sort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid+1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high) {
    int i=low;
    int k=low;
    int j=mid+1;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= high) {
        temp[k++] = arr[j++];
    }
    for (int i=low; i<=high; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for (int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    low = 0;
    high = size - 1;
    merge_sort(low, high);
    printf("Sorted array: ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
