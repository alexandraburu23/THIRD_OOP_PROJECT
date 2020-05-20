#ifndef FILM_H
#define FILM_H
#pragma once
#include <iostream>
#include <string>

class Film
{
    std::string nume,tip;
    int durata;
    double incasari;
    friend std::istream& operator>> (std::istream&, Film&);
    friend std::ostream& operator<< (std::ostream&, Film&);
public:
    Film();
    Film(std::string,std::string,int,double);
    void operator=(const Film&);
    bool operator==(const Film&);
    virtual ~Film();
    void afisare()const
    {
        std::cout<<"Titlu film: "<<this->nume<<'\n';
        std::cout<<"Tip: "<<this->tip<<'\n';
        std::cout<<"Durata: "<<this->durata<<'\n';
        std::cout<<"Incasari: "<<this->incasari<<'\n';
    };

};

#endif // FILM_H
