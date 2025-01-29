#include <stdio.h>//heap sort
#include <stdlib.h>
#include <string.h>

void swap(int* val_1, int* val_2) {
  int temp = *val_1;
  *val_1 = *val_2;
  *val_2 = temp;
}

void make_heap(int* heap, int loc, int heap_sz) {
  while (loc != 1 && heap[loc] < heap[loc >> 1]) {
    swap(&heap[loc], &heap[loc >> 1]);
    loc >>= 1;
  }
  while (loc << 1 <= heap_sz) {
    int child = loc << 1;
    if (child + 1 <= heap_sz && heap[child + 1] < heap[child]) {
      child++;
    }
    if (heap[loc] <= heap[child]) {
      break;
    }
    swap(&heap[loc], &heap[child]);
    loc = child;
  }
}

void sort(int* arr, int sz) {
  int* heap = (int*)malloc((sz+1) * sizeof(int));
  int heap_sz = 0;
  for (int i = 0; i < sz; i++) {
    heap[++heap_sz] = arr[i];
    make_heap(heap, heap_sz, heap_sz);
  }
  for (int i = 0; i < sz; i++) {
    arr[i] = heap[1];
    heap[1] = heap[heap_sz--];
    make_heap(heap, 1, heap_sz);
  }
  free(heap);
}

int main(void) {
  int arr[] = {123,23,323,2323,21};
  int sz = sizeof(arr)/sizeof(int);
  sort(arr, sz);
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
}
