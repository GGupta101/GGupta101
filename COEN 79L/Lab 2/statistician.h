//Name: Gagan Gupta
//Date: 01/17/20
//Assignment: Lab 2 Part 1 Header File
//Description: Header file for the statistician class

// FILE: statistician.h
// CLASS PROVIDED: statistician
//
//  COEN 79
//  --- Behnam Dezfouli, COEN, SCU ---
//
//   (a class to keep track of statistics on a sequence of real numbers)
//   This class is part of the namespace coen79_2C
//
// CONSTRUCTOR for the statistician class:
//   statistician( );
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of numbers. Various statistics will be calculated about the
//     sequence.
//
// PUBLIC MODIFICATION member functions for the statistician class:
//   void next(double r)
//     The number r has been given to the statistician as the next number in
//     its sequence of numbers.
//   void reset( );
//     Postcondition: The statistician has been cleared, as if no numbers had
//     yet been given to it.
//   
// PUBLIC CONSTANT member functions for the statistician class:
//   int length( ) const
//     Postcondition: The return value is the length of the sequence that has
//     been given to the statistician (i.e., the number of times that the
//     next(r) function has been activated).
//   double sum( ) const
//     Postcondition: The return value is the sum of all the numbers in the
//     statistician's sequence.
//   double mean( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the arithmetic mean (i.e., the
//     average of all the numbers in the statistician's sequence).
//   double minimum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the tiniest number in the
//     statistician's sequence.
//   double maximum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the largest number in the
//     statistician's sequence.
//
// NON-MEMBER functions for the statistician class:
//   statistician operator +(const statistician& s1, const statistician& s2)
//     Postcondition: The statistician that is returned contains all the
//     numbers of the sequences of s1 and s2.
//   statistician operator *(double scale, const statistician& s)
//     Postcondition: The statistician that is returned contains the same
//     numbers that s does, but each number has been multiplied by the
//     scale number.
//   bool operator ==(const statistician& s1, const statistician& s2)
//     Postcondition: The return value is true if s1 and s2 have the zero
//     length. Also, if the length is greater than zero, then s1 and s2 must
//     have the same length, the same  mean, the same minimum, 
//     the same maximum, and the same sum.
//     
// VALUE SEMANTICS for the statistician class:
// Assignments and the copy constructor may be used with statistician objects.

#ifndef STATS_H     // Prevent duplicate definition
#define STATS_H
#include <vector>
#include <algorithm>
#include <iostream>

namespace coen79_lab2{
    class statistician{
        public:
            //Required functions to analyze data from the sequence
            statistician();
            void next(double r);
            void reset();
            int length() const;
            double sum() const;
            double mean() const;
            double minimum() const;
            double maximum() const;
            //Operator definitions for statistician addition and statistician scaling
            //Use of friend to allow these two non-member operator definitions to access private variables
            friend statistician operator +(const statistician& s1, const statistician& s2);
            friend statistician operator *(double scale, const statistician& s);
        
        private:
            //Required variables for the data analysis and for operator use
            int len;
            double sumSeq;
            double min;
            double max;
    };
    //Non-member Operator that does not need access to the private variables
    bool operator ==(const statistician& s1, const statistician& s2);
}

#endif
