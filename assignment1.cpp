#include <iostream>

using namespace std;

int rec_sum(int);

int iter_sum(int);

int main()
{
    int n;

    cout << "\n\nPlease input a positive integer: ";

    cin >> n;

    cout << endl << rec_sum(n) << endl;

    cout << endl << iter_sum(n) << endl;

    return 0;
}

int rec_sum(int n)
{
    int a = n;
    if(a == 1)
    return 1;
    else
    return a + rec_sum(n-1);
}

int iter_sum(int n)
{
    int num = 0;

    for(int x = 1; x <= n; x++){
        num += x;
    }

    return num;
}