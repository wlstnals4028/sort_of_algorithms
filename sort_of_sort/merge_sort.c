#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int* arr, int st, int ed) {
  if(st >= ed) return;
  
  int md = (st + ed) / 2;
  sort(arr, st, md);
  sort(arr, md+1, ed);
  
  int* l = (int*)malloc((md - st + 1) * sizeof(int));
  int* r = (int*)malloc((ed - md) * sizeof(int));
  memcpy(l, &arr[st], (md - st + 1) * sizeof(int));
  memcpy(r, &arr[md + 1], (ed - md) * sizeof(int));
  
  int li = 0, ri = 0;
  int ai = st;
  while(li < md-st+1 && ri < ed-md) {
    if(l[li] <= r[ri]) {
      arr[ai++] = l[li++];
    } else {
      arr[ai++] = r[ri++];
    }
  }
  while(li < md-st+1) {
    arr[ai++] = l[li++];
  }
  while(ri < ed-md) {
    arr[ai++] = r[ri++];
  }
  free(l);
  free(r);
}

int main(void) {
  int arr[] = {64,22,445,23,124,12};
  int sz = sizeof(arr) / sizeof(int);
  sort(arr, 0, sz-1);
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
