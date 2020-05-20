#include "Regizor.h"

Regizor::Regizor(): Persoana()
{
    //std::cout<<"R const\n";
}

Regizor::Regizor(int c,std::string nm,Film f, double s): Persoana(c,nm,f,s)
{
    //std::cout<<"R const\n";
}
Regizor::Regizor(const Regizor& other): Persoana(other)
{
    //std::cout<<"R copy\n";
}
Regizor::~Regizor()
{
    //std::cout<<"R destr\n";
}
double Regizor::bonus()
{
    return suma_fixa;
}

void Regizor::operator=(const Regizor& obj)
{
    Persoana::operator=(obj);
   // this->suma_fixa=obj.suma_fixa;
}
std::istream& operator>> (std::istream& fin, Regizor& obj)
{
    fin>>dynamic_cast<Persoana&>(obj);
    //std::cout<<"\nSuma fixa este: ";
   // fin>>obj.suma_fixa;
    return fin;
}
std::ostream& operator<< (std::ostream& fout, Regizor& obj)
{
    obj.afisare();
    fout<<"Suma fixa: "<<obj.suma_fixa<<'\n';
    return fout;
}
