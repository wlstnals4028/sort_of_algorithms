#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void sort(uint* arr, uint sz) {
  uint mx = 0;
  for (int i = 0; i < sz; i++) {
    if(arr[i] > mx) mx = arr[i];
  }
  uint* cnt = (uint*)calloc(mx+1, sizeof(uint));
  for (int i = 0; i < sz; i++)
    cnt[arr[i]]++;
  for (int i = 0, j = 0; i <= mx; i++) {
    while (cnt[i]--)
      arr[j++] = i;
  }
}

int main(void) {
  uint arr[] = {13,32,34,23};
  uint sz = sizeof(arr)/sizeof(uint);
    sort(arr, sz);
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
}
