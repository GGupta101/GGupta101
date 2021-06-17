//Name: Gagan Gupta
//Date: 01/17/20
//Assignment: Lab 2 Part 2 Class Implementation File
//Description: Implementation file for the rand_gen class

// FILE: random.cpp
// CLASS IMPLEMENTED: random (see stats.h for documentation)

#ifndef RAND_NUM_GEN2_H
#define RAND_NUM_GEN2_H

#include <iostream>
#include <cassert>
#include "random.h"

using namespace std;

namespace coen79_lab2 {
    rand_gen::rand_gen(int sd, int mul, int inc, int mod){  //Set all the variables accordingly
        seed=sd;
        mult=mul;
        increment=inc;
        modulus=mod;
    }
    void rand_gen::set_seed(int newSeed){   //Take in int and set it to seed
        seed=newSeed;
    }
    int rand_gen::next(){   //Use formula to find next seed and use set_seed to change the seed
        set_seed((mult * seed + increment) % modulus);
        return seed;        //Return new seed
    }
    void rand_gen::print_info(){    //Print our all 4 variables in the order below
        printf("Seed: %d\nMultiplier: %d\nIncrement: %d\nModulus: %d\n", seed,mult,increment,modulus);
    }
}


#endif
