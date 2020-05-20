#ifndef REGIZOR_H
#define REGIZOR_H
#pragma once
#include "Persoana.h"

class Regizor: public Persoana
{
    const int suma_fixa=100;
    friend std::istream& operator>> (std::istream&, Regizor&);
    friend std::ostream& operator<< (std::ostream&, Regizor&);
    public:
        Regizor();
        Regizor(int,std::string,Film,double);
        Regizor(const Regizor&);
        double bonus();
        void operator=(const Regizor&);
        virtual ~Regizor();
        //void afisare()const;
};

#endif // REGIZOR_H
