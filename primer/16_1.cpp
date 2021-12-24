#include <iostream>
#include <vector>
#include <string>
#include <list>

// template <typename T>
// int compare(const T &v1, const T &v2)
// {
//     if (v1 < v2)
//         return -1;
//     if (v2 < v1)
//         return 1;
//     return 0;
// }

template <typename IT, typename VA>
IT find(IT beg, IT end, const VA &value)
{
    for (; beg != end; ++beg)
        if (*beg == value)
            return beg;
    return end;
}

template <typename T, unsigned N>
void print(const T (&arr) [N])
{
    for (const T &elem : arr)
        std::cout << elem << " ";
}

template <typename T, unsigned N>
const T* begin(const T (&arr) [N])
{
    return &arr[0];
}

template <typename T, unsigned N>
const T* end(const T (&arr) [N])
{
    return &arr[0] + N;
}

int main()
{
    int a[] = {1, 2, 3};
    for (auto beg = begin(a); beg != end(a); ++beg)
        std::cout << *beg << " ";
}
