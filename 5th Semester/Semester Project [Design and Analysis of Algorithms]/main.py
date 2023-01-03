from src.data import DataSeq
from src.bubblesort import BubbleSort
from src.bucketsort import BucketSort
from src.heapsort import HeapSort
from src.insertionsort import InsertionSort
from src.mergesort import MergeSort
from src.quicksort import QuickSort
from src.radixsort import RadixSort
from src.countsort import CountingSort
from src.hybirdQuickSort import  hybirdSort

import argparse

def parse_args():
    parser=argparse.ArgumentParser(description="Sort Visulization")
    parser.add_argument('-l','--length',type=int,default=64)
    parser.add_argument('-i','--interval',type=int,default=30)
    parser.add_argument('-t','--sort-type',type=str,default='BubbleSort', 
                                        choices=["BubbleSort","BucketSort",
                                                "CountingSort","HeapSort","InsertionSort",
                                                "MergeSort","QuickSort",
                                                "RadixSort","hybirdSort"])
    args=parser.parse_args()

    return args


if __name__ == "__main__":
    args = parse_args()
    MAXLENGTH=1000
    Length     = args.length if args.length<MAXLENGTH else MAXLENGTH
    Interval   = args.interval
    SortType   = args.sort_type

    try:
        SortMethod=eval(SortType)
    except:
        raise RuntimeError("Sort Type Not Found! Please Check if %s Exists or Not!"%SortType)
        exit()
    #if not NoSound and sound_interval*10<Interval:
     #   raise UserWarning("UserWarning: sound interval too small")
     
     

    ds=DataSeq(Length, time_interval=Interval, 
                        sort_title=SortType)
                        #sound=not NoSound, sound_interval=sound_interval)
    ds.StartTimer()
    SortMethod(ds)
    ds.StopTimer()
    ds.Hold()
