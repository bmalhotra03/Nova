// Author: Brij Malhotra
// Filename: lumen.h
// Version: Version 1
// Description: This is the class implementation of the Lumen object

#include "lumen.h"
#include <cmath>

Lumen :: Lumen(int b, int s, int p){
    
    if(b < 0 || s < 0 || p < 0){
        b = abs(b);
        s = abs(s);
        p = abs(p);
    }
    
    initialBrightness = b;
    initialPower = p;
    brightness = b;
    size = s;
    power = p;
    glowCount = 0;
    active = true;
    MIN_POWER = (p / 5);
    RESET_THRESHOLD = (p / s);
    MAX_POWER = p * s;
}

bool Lumen :: isActive(){
    return (power > MIN_POWER);
}

bool Lumen :: isStable(){
    return (brightness > (initialBrightness / size) && power < MAX_POWER);
}

int Lumen :: magnifiedValue(){
    return (brightness * size);
}

int Lumen :: dimnessValue(){
    return (brightness / 2);
}

int Lumen :: erraticPower(){
    return ((power * brightness) / size);
}

int Lumen :: glow(){
    glowCount++;
    power--;
    active = isActive();
    stable = isStable();

    if (!active)
    {
        return dimnessValue();
    }

    if (stable)
    {
        return magnifiedValue();
    }

    return erraticPower();
}

void Lumen :: reset(){
    if (glowCount >= RESET_THRESHOLD && (power > 0)){
        brightness = initialBrightness;
        power = initialPower;
        glowCount = 0;
        active = true;
        } else {
            brightness--;
        }
}

void Lumen :: copy(const Lumen& obj){
    initialBrightness = obj.initialBrightness;
    initialPower = obj.initialPower;
    size = obj.size;
    brightness = obj.brightness;
    power = obj.power;
    glowCount = obj.glowCount;
    active = obj.active;
    stable = obj.stable;
    MIN_POWER = obj.MIN_POWER;
    RESET_THRESHOLD = obj.RESET_THRESHOLD;
    MAX_POWER = obj.MAX_POWER;
}

void Lumen :: increasePower(){
    if(stable){
        power += initialPower/4;
    }
}