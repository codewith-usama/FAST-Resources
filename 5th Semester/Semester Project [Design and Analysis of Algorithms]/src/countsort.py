from .data import DataSeq



def CountingSort(ds):
    assert isinstance(ds, DataSeq), "Type Error"

    Length = ds.length
    D = Length//2
    while D>0:
        i=0
        while i<Length:
            tmp = ds.data[i]

            j=i
            while j>=1 and ds.data[j-D]>tmp:
                ds.SetVal(j, ds.data[j-D])
                j-=D
            ds.SetVal(j, tmp)

            i+=D
        D//=2

    with open('sorted.txt', 'w') as f:
        f.write('Count Sort::\n')
        f.write(str(ds.data))




if __name__ == "__main__":
    ds=DataSeq(64)
    ds.Visualize()
    ds.StartTimer()
    CountingSort(ds)
    ds.StopTimer()
    ds.SetTimeInterval(0)
    ds.Visualize()
