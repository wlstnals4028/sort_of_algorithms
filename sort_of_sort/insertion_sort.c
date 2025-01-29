#include <stdio.h>
#include <stdlib.h>

void swap(int* val_1, int* val_2) {
  int temp = *val_1;
  *val_1 = *val_2;
  *val_2 = temp;
}

void sort(int* arr, int sz) {
  for (int i = 1, loc; i < sz; i++) {
    loc = i;
    while (loc != 1 && arr[loc] < arr[loc-1]) {
      swap(&arr[loc], &arr[loc-1]);
      loc--;
    }
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
