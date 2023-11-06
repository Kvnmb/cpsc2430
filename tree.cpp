#include <iostream>

using namespace std;

int main()
{
    cout << "\n\n";

    for(int x = 0; x < 10; x++){
        cout << "*\n";
    }

    for(int y = 0; y < 10; y++){
       int count = y;
       int counter = 0;
       
       while(counter < count){
            cout << "*";
            counter++;
        }
        cout << endl;
    }

    cout << endl;

    int rows = 0;
    cout << "Enter a number of rows: ";
    cin >> rows;
    cout << endl;

    for(int x = 0; x < rows; x++){
        int counter = 0;
        while(counter < (rows - x)){
            cout << " ";
            counter++;
        }
        for(int y = 0; y <= x; y++){
            cout << "*";
        }
        for(int z = 0; z < x; z++){
            cout << "*";
        }
        
        cout << endl;
    }
    return 0;
}