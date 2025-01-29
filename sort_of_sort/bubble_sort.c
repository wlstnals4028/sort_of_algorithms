#include <stdio.h>

void swap(int* val_1, int* val_2) {
  int temp = *val_1;
  *val_1 = *val_2;
  *val_2 = temp;
}

void sort(int* arr, int sz) {
  for (int i = 0; i < sz; i++) for (int j = 0; j < sz-1; j++) {
    if(arr[j] > arr[j+1])
      swap(&arr[j], &arr[j+1]);
  }
}

int main(void) {
  int arr[] = {13,32,34,23};
  int sz = sizeof(arr)/sizeof(int);
    sort(arr, sz);
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
}
