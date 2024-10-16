// Author: Brij Malhotra
// Filename: nova.cpp
// Version: Version 1
// Description: This is the class implementation of the Nova object


// Class invariant:
//    The nova object requires 4 positive integer parameters that will be used to create
//    an object. In the constructor, the parameters in order: brightness, size, power, array Size. 
//    If the constructor is empty, default values of brightness = 100, size = 10, power = 100
//    are set and functions will return results based on that. Once an object has been created,
//    the client can invoke functions glow(int), recharge(), getMax() and getMin(). glow(int)
//    returns values of the lumen objects in the nova, the parameter for glow decides how many objects
//    will have the function invoked on it. recharge() increases the power of lumen objects in the nova object
//    only if more than half are inactive. getMax() and getMin() allow the user to query the nova object and to
//    retrieve the maximum and minimum glow values of lumen objects in the nova object. 

#include "nova.h"

// Pre conditions: 4 positive values are passed as arguments, if negative, absolute values are taken.
// If constructor is empty, default values will be taken to create the object.
// Post conditions: None
Nova :: Nova(int b, int s, int p, int arraySize){
    
    if(b < 0 || s < 0 || p < 0 || arraySize < 0){
        b = abs(b);
        s = abs(s);
        p = abs(p);
        arraySize = abs(arraySize);
    }
    
    brightness = b;
    size = s;
    power = p;
    arrSize = arraySize;
    max = 0;
    min = 0;

    ptr = new Lumen[arrSize];

    for(int i = 0; i < arrSize; i++){
        ptr[i] = Lumen((b+i),(s+i),(p+i));
    }
}

// Copy constructor
// Pre conditions: A Nova object 'obj' exists.
// Post conditions: A new Nova object is created with the same values as obj. 
// A deep copy of obj's ptr array is made and assigned to the new object's ptr.
Nova :: Nova(const Nova& obj){
    power = obj.power;
    brightness = obj.brightness;
    size = obj.size;
    arrSize = obj.arrSize;
    ptr = new Lumen[arrSize];
    max = obj.max;
    min = obj.min;

    for (int i = 0; i < arrSize; i++){
        ptr[i] = obj.ptr[i];
    }
}

// Destructor
// Pre conditions: A Nova object exists
// Post conditions: The 'ptr' array is deleted and set to nullptr. The object is destroyed.
Nova :: ~Nova(){
    delete [] ptr;
    ptr = nullptr;
}

// Assignment operator
// Pre conditions: A Nova object 'obj' exists.
// Post conditions: The calling Nova object is assigned the same values as 'obj'.
// 'obj's' 'ptr' array is transferred to the calling object's 'ptr', and 'obj.ptr' is set to nullptr.
void Nova :: operator=(const Nova& orig){
    if(this != &orig){
        delete [] ptr;
        power = orig.power;
        brightness = orig.brightness;
        size = orig.size;
        arrSize = orig.arrSize;
        max = orig.max;
        min = orig.min;
        ptr = orig.ptr;

        novaCopy(orig);
    }
}

// Move assignment operator
// Pre conditions:
void Nova :: operator=(Nova&& obj){
    swap(power, obj.power);
    swap(brightness, obj.brightness);
    swap(size, obj.size);
    swap(arrSize, obj.arrSize);
    swap(max, obj.max);
    swap(min, obj.min);   
    swap(ptr, obj.ptr);
}

// Move copy constructor
// Pre conditions: A Nova object 'obj' exists.
// Post conditions: A new Nova object is created with the same values as obj. 
// A deep copy of obj's ptr array is made and assigned to the new object's ptr.
Nova :: Nova(Nova&& obj){
    max = obj.max;
    min = obj.min;
    arrSize = obj.arrSize;
    ptr = obj.ptr;

    obj.arrSize = 0;
    obj.ptr = nullptr;
}

// Nova copy function
void Nova :: novaCopy(const Nova& obj){
    arrSize = obj.arrSize;
    ptr = new Lumen[arrSize];

    for(int i = 0; i < obj.arrSize; i++){
        ptr[i].copy(obj.ptr[i]);
    }
}

// Nova glow function
// Pre conditions: 'ptr' is a valid array of 'Lumen' objects.
// Post conditions: The 'glow()' function of each of the first num objects in 'ptr' is called, 
// and 'max' and 'min' are updated to reflect the maximum and minimum return values of the 'glow()' function, respectively.
void Nova :: glow(int num){

    if(num > arrSize){
        num = arrSize;
    }
    
    for (int i = 0; i < num; i++){
        int temp = ptr[i].glow();

        if(temp > max){
            max = temp;
        }

        if(min == 0){
            min = temp;
        } else if(temp < min){
            min = temp;
        }
    }
}

// Pre-conditions: None.
// Post-conditions: Returns the current value of 'max'.
int Nova :: getMax(){
    return max;
}

// Pre-conditions: None.
// Post-conditions: Returns the current value of 'min'.
int Nova :: getMin(){
    return min;
}

// Pre-condition: 'ptr' is a valid array of 'Lumen' objects.
// Post-condition: If more than half of the 'Lumen' objects in ptr are active, 
// the 'increasePower()' function of each object in 'ptr' is called.
void Nova :: recharge(){
    
    int count = 0;
    
    for(int i = 0; i < arrSize; i++){
        if(ptr[i].isActive()){
            count++;
        }
    }

    if(count > arrSize/2){
        for(int i = 0; i < arrSize; i++){
            ptr[i].increasePower();
            if(!ptr[i].isStable()){
                ptr[i].reset();
            }
        }
    }
}


// Implementation invariant:
//    The client is not able to control the lumen object glow directly. There are no set functions, 
//    once values have been given to initialize an object, the functions will be invoked upon those values only.
//    Client does not know whether the object is stable or active, all they receive is an integer value 
//    related to the glow(int) function and its conditions based on their input, only int number of objects
//    in the nova object will have glow() invoked on them. The functions getMax() and getMin() allow the user
//    to query the nova object and to retrieve the maximum and minimum glow values of the objects in it. The
//    recharge() function can be called and the power will be recharge IF and ONLY IF more than half of the 
//    Lumen objects in the Nova object are inactive. Consistent unstable objects may be replaced. 