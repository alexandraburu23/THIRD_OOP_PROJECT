#include "Persoana.h"

Persoana::Persoana()
{
    cnp=0;
    nume="";
    film = new Film;
    salariu=0;
    //std::cout<<"P const\n";
}
Persoana::Persoana(int c,std::string nm,Film f, double s): cnp(c),nume(nm), salariu(s)
{
    film = new Film(f);
    //std::cout<<"P const\n";
}
Persoana::~Persoana()
{
    cnp=0;
    nume="";
    delete film;
    salariu=0;
    //std::cout<<"P destr\n";
}
Persoana::Persoana(const Persoana& other)
{
    this->cnp=other.cnp;
    this->nume=other.nume;
    this->film=new Film(*(other.film));
    this->salariu=other.salariu;
    //std::cout<<"P copy\n";
}
void Persoana::operator=(const Persoana& p)
{
    this->cnp=p.cnp;
    this->nume=p.nume;
    this->film=new Film(*(p.film));
    this->salariu=p.salariu;
}
std::istream& operator>> (std::istream& fin, Persoana& obj)
{
    std::cout<<"\nCNP-ul este: ";
    fin>>obj.cnp;
    std::cout<<"\nNumele este: ";
    fin>>obj.nume;
    std::cout<<"\nSalariul este: ";
    fin>>obj.salariu;
    std::cout<<"\nFilmul este: ";
    fin>>(Film&)(*obj.film);
    return fin;

}
std::ostream& operator<< (std::ostream& fout, Persoana& obj)
{
    obj.afisare();
    return fout;
}
Film Persoana::get_film(){
    return *film;
}
double Persoana::venit()
{

    return salariu+bonus();

}
