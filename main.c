#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_func.h"
#define Maxsize 200



int main()
{
    int a[40] = {3,10,26,17,15,27,18,16,28,2,29,14,0,30,5,31,14,32,12,33,7,
                34,9,35,8,36,11,37,13,38,12,39,19,20,21,22,23,24,40,25};
    int num, i;
    scanf("%d", &num);
    switch(num)
    {
        case 1: BubbleSort_1(a, 40); break;
        case 2: BubbleSort_2(a, 40); break;
        case 3: BubbleSort_3(a, 40); break;
        case 4: Insert_Sort(a, 40); break;
        case 5: MergeSort_1(a, 0, 40); break;
        case 6: MergeSort_2(a, 0, 40); break;
        case 7: QuickSort_1(a, 0, 40); break;
        case 8: QuickSort_2(a, 0, 40); break;
        case 9: QuickSort_3(a, 0, 40); break;
        case 10: MaxHeap_Sort(a, 40); break;
        default: printf("Please input a integer again!");
    }
    for(i=0; i<40; i++)
        printf("%d ", a[i]);

    return 0;
}

