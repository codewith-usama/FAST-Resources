def __heapify(lst, n, root):
    
    largest = root
    left = 2 * root +1
    right = 2 * root +2
    
    if left < n and lst[left] > lst[largest]:
        largest = left;
        
    if right < n and lst[right] > lst[largest]:
        largest = right
        
    if largest != root:
        
        lst[root], lst[largest] = lst[largest], lst[root]
        
        __heapify(lst, n, largest)

def __buildHeap(lst):
    
    n = len(lst)
    
    
    for i in reversed( range(n // 2)):
        
        __heapify(lst, n, i)
        
heap = [15, 5, 20, 1, 17, 10, 20]
print(heap)
__buildHeap(heap)
print(heap)


def __heapSort(lst):
    
    n = len(lst)
    
    __buildHeap(heap)
    
    for i in reversed( range(n)):
        
        lst[i], lst[0] = lst[0], lst[i]
        
        __heapify(lst, i, 0)
        
heap = [15, 5, 20, 1, 17, 10, 20]

print(heap)

__heapSort(heap)
print(heap)