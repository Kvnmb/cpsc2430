// Kevin Bui
// bico.cpp
// 4/8/22
// Purpose: this program takes inputs from the user for an exponent and term,
// returns the i-th coefficient of the binomial (x+y)^n
// Input: two positive integers
// Processing: for loops to create factorials to calculate the coefficient
// Output: the coefficient of the i-th term

#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

int newBico(int, int); // function that returns i-th coefficient

int main(int argc, char * argv[])
{
    auto start = high_resolution_clock::now();

    int binom = -1, term = -1, result = 0; // -1 for since index starts at 0

    while(binom < 0){ // makes sure that answer is valid
        cout << "\n\nPlease input the degree of the binomial: ";
    
        binom = stoi(argv[1]);
    }

    while(term < 0 || term > binom){ // keeps term number within valid parameters,
    // which is from 0 - (exponent + 1) but we omit the 1 since index starts at 0

        cout << "\nPlease input the index of the coefficient: ";

        term = stoi(argv[2]);
    }

    result = newBico(binom, term);

    cout << "\nThe result is: " << result << endl << endl;

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << duration.count() << endl;

    return 0;
}

// recursive method of finding coefficient
int newBico(int binom, int term) 
{
    if(term == 0 || term == binom){
        return 1;
    }else{
        return newBico(binom - 1, term - 1) + newBico(binom - 1, term);
    }
}