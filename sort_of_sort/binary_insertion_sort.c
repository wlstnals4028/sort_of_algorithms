#include <stdio.h>
#include <stdlib.h>

void swap(int* val_1, int* val_2) {
  int temp = *val_1;
  *val_1 = *val_2;
  *val_2 = temp;
}

void sort(int* arr, int sz) {
  int i, j, val;
  for (i = 1; i < sz; i++) {
    val = arr[i];
    j = i - 1;
    
    int l = 0;
    int r = i;
    while (l < r) {
      int md = l + (r - l) / 2;
      if (arr[md] <= val) l = md + 1;
      else r = md;
    }
    for (j = i - 1; j >= l; j--)
      arr[j + 1] = arr[j];
    arr[l] = val;
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
