// Author: Brij Malhotra
// Filename: lumen.h
// Version: Version 1
// Description: This is the class definition of the Lumen object

#ifndef LUMEN_H
#define LUMEN_H

class Lumen
{
    private:
        // Private variables
        int initialBrightness;
        int initialPower;
        int size;
        int brightness;
        int power;
        int glowCount;
        bool active;
        bool stable;
        int MIN_POWER;
        int RESET_THRESHOLD;
        int MAX_POWER;

        // Private functions
        int magnifiedValue();
        int dimnessValue();
        int erraticPower();

    public:
        // Public functions that client can use
        Lumen(int b = 100, int s = 10, int p = 100);
        int glow();
        void reset();
        bool isActive();
        bool isStable();
        void copy(const Lumen&);
        void increasePower();
};

#endif