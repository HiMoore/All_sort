#ifndef SORT_FUNC_H_INCLUDED
#define SORT_FUNC_H_INCLUDED
typedef int ElemType;

extern void swap(int *a, int *b);
extern void Bucket_Sort(int a[], int n);
extern void Insert_Sort(ElemType A[], int n);

extern void BubbleSort_1(ElemType a[], int n);
extern void BubbleSort_2(ElemType a[], int n);
extern void BubbleSort_3(ElemType a[], int n);

extern void Merge_1(ElemType A[], int p, int q, int r);
extern void MergeSort_1(ElemType A[], int p, int r);
extern void Merge_2(ElemType A[], int p, int q, int r);
extern void MergeSort_2(ElemType A[], int p, int r);

extern void Partition_1(ElemType A[], int p, int r);
extern void QuickSort_1(ElemType A[], int p, int r);
extern void Partition_2(ElemType A[], int p, int r);
extern void QuickSort_2(ElemType A[], int p, int r);
extern void QuickSort_3(ElemType A[], int p, int r);

extern void Max_Heapify(ElemType A[], int i, int heapsize);
extern void Build_Max_Heap(ElemType A[], int i, int heapsize);
extern void MaxHeap_Sort(ElemType A[], int heapsize);
#endif // SORT_FUNC_H_INCLUDED
