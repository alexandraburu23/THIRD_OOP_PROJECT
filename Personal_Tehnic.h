#ifndef PERSONAL_TEHNIC_H
#define PERSONAL_TEHNIC_H
#pragma once
#include "Persoana.h"

class Personal_Tehnic : public Persoana
{
    friend std::istream& operator>> (std::istream&, Personal_Tehnic&);
    friend std::ostream& operator<< (std::ostream&, Personal_Tehnic&);
    public:
        Personal_Tehnic();
        Personal_Tehnic(int,std::string,Film,double);
        Personal_Tehnic(const Personal_Tehnic&);
        double bonus();
        void operator=(const Personal_Tehnic&);
        virtual ~Personal_Tehnic();


};

#endif // PERSONAL_TEHNIC_H
