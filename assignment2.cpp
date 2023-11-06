// Kevin Bui
// assignment2.cpp
// 4/28/22
// Purpose: To use recursion to solve math problems
// Input: user inputs integers
// Processing: recursion, if statements, math
// Output: sums, roots, quotients, etc

#include <iostream>
#include <cmath>

using namespace std;

int sumDigits(int); // adds up digits of inputted #
int doubleInt(int &); // doubles the input
int halveInt(int); // halves input
int egyptDivision(int, int); // egyptian method of division using arithmetic
double equation(double, double); // calculates the 5th root
double root5(double, double); // finds a good guess for the 5th root of a number
double ramanujan(double); // returns a nested rational approximation
double add(int, double); // helper function

int main()
{
    int num, divisor, dividend;
    double depth, root, guess = 1.0;

    cout << "\n\nPlease input a number: ";
    cin >> num;
    cout << "\nThe sum of these digits is " << sumDigits(num) << endl;

    cout << "\nPlease enter the number you wish to divide: ";
    cin >> divisor;

    cout << "\nPlease enter the number you wish to divide with: ";
    cin >> dividend;

    cout << "\nThe quotient is " << egyptDivision(divisor,dividend) << endl;

    cout << "\nPlease input a number to find the fifth root of: ";
    cin >> root;

    cout << "\nYour answer is " << root5(guess, root) << endl;

    cout << "\nPlease input a depth for the nested radicals: ";
    cin >> depth;

    cout << "\nYour answer is " << ramanujan(depth) << endl;

    cout << "\nAs it goes to infinity the ramanujan will be " << ramanujan(100000) << endl;

    return 0;
}

int sumDigits(int num)
{
    if(num == 1){
        return 1;
    }
    if(num == 0){
        return 0;
    }

    return (num % 10) + sumDigits(num/10); // takes off a digit for each recursion
}

double equation(double y, double n)
{
   return (4 * y + (n/pow(y,4.0))) / 5; // helper equation for 5th root guess
}

double root5(double guess, double num)
{
    if(num == 0){
        return 0;
    }else if(num == 1){
        return 1;
    }else if((abs(pow(equation(guess,num),5.0) - num) < 0.00001)){ // checks if guess is good
        return guess;
    }else{
        return root5(guess + 0.00001,num); // recursion
    }
}

int doubleInt(int &num) // adds 1 to num until it is doubled
{
    int temp = num + num;
    while(num < temp)
    num++;
    return num;
}

int halveInt(int num)// halves the number by only returning 1 for every 2 values
{
    if(num <= 1)
    return 0;
    
    return 1 + halveInt(num - 2);
}

int egyptDivision(int divisor, int dividend)
{
    int a = 1, b = dividend, c = divisor;

    while(b < c){ // double the values till we can divide
        doubleInt(a);
        doubleInt(b);
    }

    int d = 0;

    while(a >= 1){ // checks through list to see if we can divide the number
        if(b <= c){
            d += a;
            c -= b;
        }
        a = halveInt(a); // halves it each iteration
        b = halveInt(b);
   }

    return d;
}

double ramanujan(double depth)
{
    return add(depth, 0); // returns the ramanujan number
}

double add(int depth, double num) // helper
{

    if(depth == 0){
        num = sqrt(6 + num); // if zero, will square root 6 along with any other numbers that were saved if any
        return num;
    }else{
        double total = ((depth + 1) * sqrt((depth + 6) + num)); 
        // adds the previous numbers to the current ones,
        // such as adding 3sqrt(8) to 7 before square rooting
        return add(depth - 1, total); // recursion with any values saved
    }
}

