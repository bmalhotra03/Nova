// Author: Brij Malhotra
// Filename: P2.cpp
// Version: Version 1
// Description: Driver file for nova class

#include "nova.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    Nova nova1(rand() % 1000, rand() % 1000, rand() % 1000, 10);
    Nova nova2(rand() % 1000, rand() % 1000, rand() % 1000, 10);
    Nova nova3(rand() % 1000, rand() % 1000, rand() % 1000, 10);
    Nova nova4(rand() % 1000, rand() % 1000, rand() % 1000, 10);
    Nova nova6(rand() % 1000, rand() % 1000, rand() % 1000, 10);

    

    cout << endl;

    nova1.glow(5);
    cout << "Max Nova1 value: " << nova1.getMax() << endl;
    cout << "Min Nova1 value: " << nova1.getMin() << endl << endl;

    nova2.glow(5);
    cout << "Max Nova2 value: " << nova2.getMax() << endl;
    cout << "Min Nova2 value: " << nova2.getMin() << endl << endl;

    nova3.glow(5);
    cout << "Max Nova3 value: " << nova3.getMax() << endl;
    cout << "Min Nova3 value: " << nova3.getMin() << endl << endl;

    nova4.glow(8);
    cout << "Max Nova4 value: " << nova4.getMax() << endl;
    cout << "Min Nova4 value: " << nova4.getMin() << endl << endl;

    // Use of copy constructor
    cout << "Creating nova5 using nova2" << endl << endl;
    Nova nova5 = nova2;

    nova5.glow(5);
    cout << "Max Nova5 value: " << nova5.getMax() << endl;
    cout << "Min Nova5 value: " << nova5.getMin() << endl << endl;

    cout << "Verifying copied nova2 is unchanged: " << endl << endl;
    nova2.glow(1);
    cout << "Max Nova2 value: " << nova2.getMax() << endl;
    cout << "Min Nova2 value: " << nova2.getMin() << endl << endl;

    nova6.glow(5);
    cout << "Max Nova6 value: " << nova6.getMax() << endl;
    cout << "Min Nova6 value: " << nova6.getMin() << endl << endl;

    // Use of assignment operator
    cout << "Assigning nova6 to nova2" << endl << endl;
    nova6 = nova2;

    nova6.glow(5);
    cout << "Verifying nova6 object has been modified: " << endl;
    cout << "Max Nova6 value: " << nova6.getMax() << endl;
    cout << "Min Nova6 value: " << nova6.getMin() << endl << endl;

    cout << "Simulating 100 glows on nova4 ----" << endl << endl;

    for(int i = 0; i < 100; i++){
        nova4.glow(8);
    }

    cout << "Simulation complete- nova4 is now going to be recharged as max and minimum values go unchanged." << endl;

    for(int i = 0; i < 6; i++){
        nova4.recharge();
    }

    cout << "Recharge complete!" << endl << endl;

    nova4.glow(5);
    cout << "Max Nova4 value: " << nova4.getMax() << endl;
    cout << "Min Nova4 value: " << nova4.getMin() << endl << endl;
    
    return 0;
}