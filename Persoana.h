#ifndef PERSOANA_H
#define PERSOANA_H
#pragma once
#include "Film.h"

class Persoana
{
    int cnp;
    std::string nume;
    Film* film;
    friend std::istream& operator>> (std::istream&, Persoana&);
    friend std::ostream& operator<< (std::ostream&, Persoana&);
protected:
    double salariu;

public:
    Persoana();
    Persoana(int,std::string,Film,double);
    Persoana(const Persoana&);
    virtual double bonus()=0;
    double venit();
    Film get_film();
    void operator=(const Persoana&);
    virtual ~Persoana();
    virtual void afisare()const
    {
        std::cout<<"CNP: "<<this->cnp<<'\n';
        std::cout<<"Nume: "<<this->nume<<'\n';
        std::cout<<"Salariu: "<<this->salariu<<'\n';
        std::cout<<*(this->film);
    };

};

#endif // PERSOANA_H
