// Author: Brij Malhotra
// Filename: nova.h
// Version: Version 1
// Description: This is the class definition of the Nova object

#include "lumen.h"
#include <iostream>

using namespace std;

#ifndef NOVA_H
#define NOVA_H

class Nova{
    
    private:
        int power;
        int brightness;
        int size;
        int arrSize;
        Lumen * ptr;
        int max;
        int min;
        void novaCopy(const Nova&);

    public:
        Nova(int, int, int, int arrSize = 10);
        Nova(const Nova&);
        ~Nova();
        void operator=(const Nova&);    // Assignment operator
        void operator=(Nova&&);         // Move assignment operator
        Nova(Nova&&);                   // Move copy constructor
        

        void glow(int);
        void recharge();
        int getMax();
        int getMin();
        
};

#endif 