#include <iostream>

using namespace std;

void fun(int);

int main()
{
    fun(5);

    return 0;
}

void fun(int x)
{
    if(x > 0){
        fun(--x);
        cout << x << " ";
        fun(--x);
    }
}