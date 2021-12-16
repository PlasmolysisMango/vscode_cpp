#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    // version 1 范围for
    for (int (&p)[4] : ia)
    {
        for (int q : p)
            cout << q << " ";
    }
    cout << endl;

    // version 2 下标
    for (size_t p = 0; p != 3; ++p)
    {
        for (size_t q = 0; q != 4; ++q)
            cout << ia[p][q] << " ";
    }
    cout << endl;

    // version 3 指针
    for (int(*p)[4] = ia; p != ia + 3; ++p)
    {
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
    }
    cout << endl;

    // version 4 类型别名
    using int_array = int[4];
    for (int_array *p = ia; p != ia + 3; ++p)
    {
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
    }
    cout << endl;

    return 0;
}