#include "Actor.h"

Actor::Actor(): Persoana()
{
    rol="";
    //std::cout<<"A const\n";
}

Actor::Actor(int c,std::string nm,Film f, double s,std::string r): Persoana(c,nm,f,s)
{
    rol=r;
    //std::cout<<"A const\n";
}
Actor::Actor(const Actor& other): Persoana(other)
{
    this->rol=other.rol;
    //std::cout<<"A copy\n";
}
Actor::~Actor()
{
    rol="";
    //std::cout<<"A destr\n";
}
double Actor::bonus()
{
    if(rol=="principal")
        return salariu*10/100;
    return 0;
}
std::string Actor::get_rol()
{
    return rol;
}

void Actor::operator=(const Actor& obj)
{
    Persoana::operator=(obj);
    this->rol=obj.rol;
}
std::istream& operator>> (std::istream& fin, Actor& obj)
{
    fin>>dynamic_cast<Persoana&>(obj);
    std::cout<<"\nRolul este: ";
    fin>>obj.rol;
    return fin;
}
std::ostream& operator<< (std::ostream& fout, Actor& obj)
{
    obj.afisare();
    fout<<"Rol: "<<obj.rol<<'\n';
    return fout;
}
