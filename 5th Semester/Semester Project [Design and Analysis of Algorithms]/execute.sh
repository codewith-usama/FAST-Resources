#!/bin/bash

echo $'Select Sorting\n 0. Time Complexities \n 1. Insertion sort\n 2. Bubble sort \n 3. Merge Sort \n 4. Heap Sort \n 5. Quick sort \n 6. Radix Sort \n 7. Bucket Sort\n 8. Counting Sort\n 9. hybirdQuickSort'

arr=(InsertionSort BubbleSort MergeSort HeapSort QuickSort RadixSort BucketSort CountingSort hybirdSort)


read NUM
n=0

if [ $n -eq $NUM ]
then
        echo "| Sorting Algorithm | AverageTime Complexity | Bad Time Complexity
| ----------------- | ---------------------- | ------------------- |"
        echo "| Insertion Sort    | O(N^2)                 | O(N^2)           "
        echo "| Bubble Sort       | O(N^2)                 | O(N^2)             "
        echo "| Merge Sort        | O(NlogN)               | O(NlogN)          "
        echo "| Heap Sort         | O(NlogN)               | O(NlogN)        "
        echo "| Quick Sort        | O(NlogN)               | O(N^2)         "
        echo "| Radix Sort        | O(N)                   | O(N)             "
        echo "| Bucket Sort       | O(N)                   | O(N)             "
        echo "| Counting Sort     | Θ(N + k)               | O(N + k)  "
        




else

    

    echo "Enter the length of the Array: " 
    read LENGTH

    python3 main.py -l $LENGTH -t ${arr[NUM-1]}


fi
