#include <future>
#include <iostream>

using namespace std;

int printa(int num)
{
    this_thread::sleep_for(chrono::seconds(1));
    cout << "A: " << num << endl;
    return 1;
}

int printb(int num)
{
    this_thread::sleep_for(chrono::seconds(1));
    cout << "B: " << num << endl;
    return 1;
}

void use()
{
    auto t1 = thread(printa, 2);
    t1.detach();
    cout << "use" << endl;
}

int main()
{
    // auto a1 = async(launch::async, printa, 1);
    // this_thread::sleep_for(chrono::seconds(1));
    // auto b1 = async(launch::async, printb, 2);
    // // a1.get();
    // // b1.get();
    // cout << "main: " << endl;
    use();
}
