#include <stdio.h>

void swap(int* val_1, int* val_2) {
  int temp = *val_1;
  *val_1 = *val_2;
  *val_2 = temp;
}

void sort(int* arr, int sz) {
  for (int i = 0, mn, mn_idx; i < sz-1; i++) {
    mn = arr[i+1]; mn_idx = i+1;
    for (int j = i+2; j < sz; j++) if(mn > arr[j]) {
      mn = arr[j]; mn_idx = j;
    }
    swap(&arr[i], &arr[mn_idx]);
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
