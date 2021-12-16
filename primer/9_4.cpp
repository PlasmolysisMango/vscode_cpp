#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> ivec;
    // cout << "ivec: size = " << ivec.size() << endl;
    // cout << "ivec: capacity = " << ivec.capacity() << endl;
    for (int ix = 0; ix != 10; ++ix) {
        ivec.push_back(ix);
        cout << "No: " << ix;
        cout << "ivec: size = " << ivec.size() << endl;
        cout << "ivec: capacity = " << ivec.capacity() << endl;
        cout << endl;
    }
    // cout << "ivec: size = " << ivec.size() << endl;
    // cout << "ivec: capacity = " << ivec.capacity() << endl;
    // ivec.shrink_to_fit();
    // cout << "ivec: size = " << ivec.size() << endl;
    // cout << "ivec: capacity = " << ivec.capacity() << endl;

}
