#include <iostream> 
#include <iomanip> 

using namespace std;

typedef int keytype;
struct INF {
    keytype key; 
    char info;
};
int findpivot(int i, int j, INF* A) {

    keytype firstkey;

    firstkey = A[i].key;

    for (int k = i + 1; k <= j; k++) {

        if (A[k].key > firstkey)

            return k;

        else if (A[k].key < firstkey)

            return i;

    }
    return -1;

}





int partition(int i, int j, int pivot, INF* A) {
    int l, r; 
    l = i;
    r = j;   
    do {
        swap(A[l], A[r]);

        while (A[l].key < pivot)

            l++;

        while (A[r].key >= pivot)

            r--;

    } while (l <= r);
    return l;

}
void quicksort(int i, int j, INF* A) {

    keytype pivot;

    int pivotindex;
    int k;
    pivotindex = findpivot(i, j, A);

    if (pivotindex != -1) {

        pivot = A[pivotindex].key;

        k = partition(i, j, pivot, A);

        quicksort(i, k - 1, A);

        quicksort(k, j, A);
    }
}
int main() {
    srand(time(0));

    const int size = 10;
    INF Array[size];

    for (int i = 0; i < size; i++)
    {
        Array[i].key = rand() % 1001;
        Array[i].info = 97 + i;
    }
    cout << "Array before sorting" << endl;     for (int i = 0; i < size; i++)
        cout << "Key:" << left << setw(5) << Array[i].key << "Info: " << Array[i].info << endl;

    quicksort(0, size - 1, Array);

    cout << endl << "Array after sorting" << endl;     for (int i = 0; i < size; i++)
        cout << "Key:" << left << setw(5) << Array[i].key << "Info: " << Array[i].info << endl;
}
