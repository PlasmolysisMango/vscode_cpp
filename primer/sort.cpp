#include <iostream>
#include <vector>

using namespace std;

int medium3(vector<int> &A, int left, int right)
{
    int mid = (right - left) / 2 + left;
    if (A[left] > A[mid])
        swap(A[left], A[mid]);
    if (A[mid] > A[right])
        swap(A[mid], A[right]);
    if (A[left] > A[mid])
        swap(A[left], A[mid]);
    swap(A[mid], A[right - 1]);
    return A[right - 1];
}

void qsort(vector<int> &A, int left, int right)
{
    if (left > right)
        return;
    if (right - left < 2) {
        if (A[left] > A[right])
            swap(A[left], A[right]);
        return;
    }
    int pviot = medium3(A, left, right);
    int beg = left, end = right - 1;
    while (true) {
        while (A[++beg] < pviot)
            ;
        while (A[--end] > pviot)
            ;
        if (beg < end)
            swap(A[beg], A[end]);
        else
            break;
    }
    swap(A[beg], A[right-1]);
    qsort(A, left, beg - 1);
    qsort(A, beg + 1, right);
}

void quick_sort(vector<int> &A)
{
    if (A.empty())
        return;
    qsort(A, 0, A.size() - 1);
}

int main()
{
    vector<int> A = {6,5,4, 3, 2, 1};
    quick_sort(A);
    for (auto i : A)
        cout << i << ' ';
    return 0;
}