#ifndef ACTOR_H
#define ACTOR_H
#pragma once
#include "Persoana.h"

class Actor: public Persoana
{
    std::string rol;
    friend std::istream& operator>> (std::istream&, Actor&);
    friend std::ostream& operator<< (std::ostream&, Actor&);

public:

    Actor();
    Actor(int,std::string,Film,double,std::string);
    Actor(const Actor& other);
    std::string get_rol();
    virtual ~Actor();
    virtual double bonus();
    void operator=(const Actor&);
    //void afisare(Actor&)const;

};

#endif // ACTOR_H
