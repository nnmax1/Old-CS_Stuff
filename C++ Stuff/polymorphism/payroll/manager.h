// CISC 2000   Fordham University  Spring 2020
// Instructor: Vincent Mierlak
// 
// Header file manager.h.
// This is the interface for the class Manager.
// Managers receive a monthly salary PLUS a bonus.

#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "corpemployee.h"
using std::string;

class Manager : public CorporateEmployee
{
    public:
        Manager() : CorporateEmployee() { }
        Manager(string e_name, string e_ssn, double e_sal, double e_bonus);
        
        virtual double get_total_pay() const;

        double get_bonus() const;
        void set_bonus(double new_bonus);

    private:
        double bonus = 0.0;
};

#endif //_MANAGER_H_
