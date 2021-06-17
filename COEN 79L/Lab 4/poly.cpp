// FILE: poly.cpp
//Name: Gagan Gupta
//Date: 01/31/20
//Assignment: Lab 4 Poly Implementation File

#ifndef COEN79_POLY_CPP
#define COEN79_POLY_CPP

#include <iostream>  // Provides ostream
#include <iomanip>
#include <cassert>
#include <climits>
#include <cmath>
#include "poly.h"

namespace coen79_lab4
{
    //HELPER MEMBER FUNCTIONS for the polynomial class
    void polynomial::update_current_degree(){
        //Find highest nonzero coefficient position and return
        for(unsigned int i=0;i<polynomial::MAXIMUM_DEGREE;i++){
            if(exp[i]!=0){
                highExp=i;
            }
        }
    }
    
    //CONSTRUCTOR for the polynomial class
    polynomial::polynomial(double c , unsigned int exponent){
        //Init all the positions to 0
        for(int i=0;i<=MAXIMUM_DEGREE;i++){
            exp[i]=0;
        }
        //Set the Highest exponent and place the coefficient
        highExp=exponent;
        exp[exponent]=c;
    }
    
    //MODIFICATION MEMBER FUNCTIONS for the polynomial class
    void polynomial::assign_coef(double coefficient, unsigned int exponent){
        //Assign coefficient at the exponent position
        exp[exponent]=coefficient;
    }
    void polynomial::add_to_coef(double amount, unsigned int exponent){
        //Add the amount to the coefficient at the exponent position
        exp[exponent]+=amount;
    }
    void polynomial::clear(){
        //Upate the current degree and clear the array
        update_current_degree();
        for(int i=0;i<=MAXIMUM_DEGREE;i++){
            exp[i]=0;
        }
    }
    
    //CONSTANT MEMBER FUNCTIONS for the polynomial class
    polynomial polynomial::antiderivative() const{
        //Antiderivative shifted the whole array one to the right with the formula in the for loop
        polynomial temp;
        for(int i=degree();i>=0;i--){
            temp.exp[i+1]= exp[i]/(i+1);
        }
        temp.update_current_degree();
        return temp;
    }
    double polynomial::coefficient(unsigned int exponent) const{
        //Function to return coefficient for non member functions
        if(exponent>MAXIMUM_DEGREE) return 0;
        return exp[exponent];
    }
    double polynomial::definite_integral(double x0, double x1) const{
        //Calls the antiderivative function into 2 calls of the eval to calculate the definite interval
        polynomial temp=antiderivative();
        return (temp.eval(x1)-temp.eval(x0));
    }
    unsigned int polynomial::degree( ) const{
        //Returns the highest degree term in the polynomial
        int deg=0;
        for (int i=0;i<=MAXIMUM_DEGREE;i++) {
            if (exp[i]!= 0) {
                deg=i;
            }
        }
        return deg;
    }
    polynomial polynomial::derivative( ) const{
        //Derivative shifts everything one to the left with the formula in the for loop
        polynomial temp;
        for(int i=1;i<=degree();i++){
            temp.exp[i-1]=exp[i+1]*i;
        }
        temp.update_current_degree();
        return temp;
    }
    double polynomial::eval(double x) const{
        //Evaluates the function based on the given x value and the polynomial coefficients
        double sum=0;
        for(int i=0;i<=degree();i++){
            sum += (pow(x,i) * exp[i]);
        }        return sum;
    }
    bool polynomial::is_zero( ) const{
        //Checks if the polynomial has zero terms
        return (degree()==0 && exp[0]==0);
    }
    unsigned int polynomial::next_term(unsigned int e) const{
        //Finds the next highest term in the polynomial. If there isn't one it will return 0.
        for(int i=e+1;i<=degree();i++){
            if(exp[i]!=0){
                return i;
            }
        }
        return 0;
    }
    unsigned int polynomial::previous_term(unsigned int e) const{
        //Finds the next lowest term in the polynomial. If there isn't one it will return UINT_MAX
        for(int i=e-1;i>=0;i--){
            if(exp[i]!=0){
                return i;
            }
        }
        return UINT_MAX;
    }
    
    //CONSTANT OPERATORS for the polynomial class
    double polynomial::operator() (double x) const{
        //Same as the Eval function but as an operator
        return eval(x);
    }

    // NON-MEMBER BINARY OPERATORS
    polynomial operator +(const polynomial& p1, const polynomial& p2){
        //+ operator for the polynomial class. It is nonmember so we access the data with public functions
        polynomial temp;
        int hDegree = 0;
        
        if (p1.degree() > p2.degree()) hDegree = p1.degree();
        else hDegree = p2.degree();
        
        for (int i = 0; i <= hDegree; i++) {
            temp.assign_coef(p1.coefficient(i) + p2.coefficient(i),i);
        }
        temp.update_current_degree();
        return temp;
    }
    polynomial operator -(const polynomial& p1, const polynomial& p2){
        //- operator for the polynomial class. It is nonmember so we access the data with public functions
        polynomial temp;
        int hDegree = 0;
        
        if (p1.degree() > p2.degree()) hDegree = p1.degree();
        else hDegree = p2.degree();
        
        for (int i = 0; i <= hDegree; i++) {
            temp.assign_coef(p1.coefficient(i) - p2.coefficient(i),i);
        }
        
        temp.update_current_degree();
        return temp;
    }
    polynomial operator *(const polynomial& p1, const polynomial& p2){
        //* operator for the polynomial class. It is nonmember so we access the data with public functions
        polynomial temp;
        for(int i=0;i<=p1.degree();i++){
            for(int j=0;j<=p2.degree();j++){
                temp.add_to_coef(p1.coefficient(i)*p2.coefficient(j),(i+j));
            }
        }
        temp.update_current_degree();
        return temp;
    }

    // NON-MEMBER OUTPUT FUNCTIONS
    std::ostream& operator << (std::ostream& out, const polynomial& p) {
        //Print statement for the Polynomial class if it is used with the cout operator
        out<<std::fixed;
        out<<std::setprecision(1);
        double co;
        
        //Test for the eay print statements: iszero and if it is only a constant
        if(p.is_zero()){
            out << 0.0;
            return out;
        }
        else if(p.degree()==0 && p.coefficient(0)!=0){
            out<<p.coefficient(0);
            return out;
        }
        
        //Print the polynomial position with coefficient not equal to 0
        for (int i=p.degree();i>=0;i--) {
            co = p.coefficient(i);
            //std::cout<<co;
            if (co != 0) {
                if (i == 1) {
                    //no exponent
                    if (co > 0) {
                        //if positive, print with +
                        if (co == 1) {
                            out << " + ";
                        } else {
                            out << " + " << abs(co);
                        }
                        
                    } else {
                        // if negative, print with -
                        if (co == 1) {
                            out << " - ";
                        } else {
                            out << " - " << abs(co);
                        }
                    }
                    out << "x";
                    
                }
                else if (i == 0) {
                    //constant
                    if (co > 0) {
                        if (co == 1) {
                            out << " + ";
                        } else {
                            out << " + " << abs(co);
                        }
                        
                    } else {
                        if (co == 1) {
                            out << " - ";
                        } else {
                            out << " - " << abs(co);
                        }
                    }
                }
                else if (i == p.degree()) {
                    //first term
                    if(co == 1) {
                        out << "x^" << i;
                    }
                    else {
                        out << co << "x^" << i;
                    }
                    
                }
                else {
                    //if past the first term
                    if (co > 0) {
                        if (co == 1) {
                            out << " + ";
                        } else {
                            out << " + " << abs(co);
                        }
                        
                    } else {
                        if (co == 1) {
                            out << " - ";
                        } else {
                            out << " - " << abs(co);
                        }
                    }
                    out << "x^" << i;
                }
                
            }
        }
        return out;
    }
}
#endif
