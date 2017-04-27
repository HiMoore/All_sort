#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
#define Max_num 1e6
typedef int ElemType;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void Bucket_Sort(int a[], int n)
{
    int m = n+1, i, j;
    int b[m];
    for(i=0; i<m; i++)
        b[i] = 0;
    for(i=0; i<n; i++)
            b[a[i]]++;

    for(i=0; i<m; i++)
    {
        if(b[i] != 0)
        {
            for(j=0; j<b[i]; j++)
                printf("%d ", i);
        }
    }
}


void Insert_Sort(ElemType A[], int n)
{
    int i, j;
    ElemType key;
    for(j=1; j<n; j++)
    {
        key = A[j];
        i = j-1;
        while(i >=0 && key < A[i])
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}


void BubbleSort_1(ElemType a[], int n)
{
    int i=0, j=0;
    for(i=0; i<n; i++)
        for(j=0; j<n-i; j++)
        {
            if(a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
        }
}

void BubbleSort_2(ElemType a[], int n)
{
    int i=0, j=0;
    int swaped;
    for(i=0; i<n; i++)
    {
        swaped = False;
        for(j=0; j<n-i; j++)
            if(a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
                swaped = True;
            }
        if(!swaped)
            break;
    }
}

void BubbleSort_3(ElemType a[], int n)
{
    int i=0, j=0, k=0;
    int location=n;
    for(i=0; i<n; i++)
        for(j=0; j<location; j++)
            if(a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
                k = j;
            }
            location = k;
}

//包含哨兵位，哨兵位为一个大值
void Merge_1(ElemType A[], int p, int q, int r)
{
    int i, j, k, n1, n2;
    n1 = q-p+1, n2 = r-q;
    ElemType L[n1+1], R[n2+1];
    for(i=0; i<n1; i++)
        L[i] = A[p+i];
    for(j=0; j<n2; j++)
        R[j] = A[q+j+1];
    L[n1] = Max_num, R[n2] = Max_num;
    i=0, j=0;
    for(k=p; k<=r; k++)
        if(L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
}

void MergeSort_1(ElemType A[], int p, int r)
{
    if(p < r)
    {
        int q = (p+r) / 2;
        MergeSort_1(A, p, q);
        MergeSort_1(A, q+1, r);
        Merge_1(A, p, q, r);
    }
}

//不包括哨兵位，需要考虑L和R数组有一个先用完
void Merge_2(ElemType A[], int p, int q, int r)
{
    int i, j, k, n1, n2;
    n1 = q-p+1, n2 = r-q;
    ElemType L[n1], R[n2];
    for(i=0; i<n1; i++)
        L[i] = A[p+i];
    for(j=0; j<n2; j++)
        R[j] = A[q+j+1];
    i=0, j=0, k=p;
    while(i<n1 && j<n2)
        if(L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];

    while(i < n1)
        A[k++] = L[i++];
    while(j < n2)
        A[k++] = R[j++];
}

void MergeSort_2(ElemType A[], int p, int r)
{
    if(p < r)
    {
        int q = (p+r)/2;
        MergeSort_2(A, p, q);
        MergeSort_2(A, q+1, r);
        Merge_2(A, p, q, r);
    }
}

//快排第一版，主元取数组中第一个元素
int Partition_1(ElemType A[], int p, int r)
{
   int i, j;
   ElemType pivot;
   pivot = A[p];
   i = p;
   for(j=p+1; j<=r; j++)
       if(A[j] <= pivot)
            swap(&A[j], &A[++i]);
   A[p] = A[i];
   A[i] = pivot;
   return i;
}

void QuickSort_1(ElemType A[], int p, int r)
{
    if(p < r)
    {
        int q = Partition_1(A, p, r);
        QuickSort_1(A, p, q-1);
        QuickSort_1(A, q+1, r);
    }
}


int Partition_2(ElemType A[], int p, int r)
{
    int i, j;
    ElemType pivot;
    pivot = A[r];
    i = p-1;
    for(j=p; j<r; j++)
    {
        if(A[j] <= pivot)
            swap(&A[++i], &A[j]);
    }
    A[r] = A[i+1];
    A[i+1] = pivot;
    return i+1;
}

void QuickSort_2(ElemType A[], int p, int r)
{
    if(p < r)
    {
        int q = Partition_2(A, p, r);
        QuickSort_2(A, p, q-1);
        QuickSort_2(A, q+1, r);
    }
}

//第三版快排，直接将Partition部分包含在整个函数里面，i即为Partition函数应该返回的q
void QuickSort_3(ElemType A[], int p, int r)
{
    if(p > r)
        return;
    int i, j;
    ElemType pivot;
    i=p, j=r, pivot = A[p];
    while(i != j)
    {
        while(A[j] >= pivot && i<j)
            j--;
        while(A[i] <= pivot && i<j)
            i++;
        if(i < j)
            swap(&A[i], &A[j]);
    }
    A[p] = A[i];
    A[i] = pivot;
    QuickSort_3(A, p, i-1);
    QuickSort_3(A, i+1, r);
}


//堆排序算法包括：保持最大堆，建立堆，堆排序
void Max_Heapify(ElemType A[], int i, int heapsize)
{
    int lchild, rchild, largest;
    lchild=2*i, rchild=2*i+1;
    if(i < (heapsize)/2)
    {
        if(lchild<heapsize && A[i]<A[lchild])
            largest = lchild;
        else
            largest = i;
        if(rchild<=heapsize && A[largest]<A[rchild])
            largest = rchild;
        if(largest != i)
        {
            swap(&A[i], &A[largest]);
            Max_Heapify(A, largest, heapsize);
        }
    }
}

void Build_Max_Heap(ElemType A[], int heapsize)
{
    int i;
    for(i=(heapsize-1)/2; i>=0; i--)
        Max_Heapify(A, i, heapsize);
}

void MaxHeap_Sort(ElemType A[], int heapsize)
{
    Build_Max_Heap(A, heapsize);
    int i;
    for(i=heapsize-1; i>0; i--)
    {
        swap(&A[i], &A[0]);
        heapsize--;
        Max_Heapify(A, 0, heapsize);
    }
}
