#include "Film.h"

Film::Film():nume(""),tip(""),durata(0),incasari(0)
{
    //std::cout<<"F const\n";
}

Film::Film(std::string nm="", std::string t="",int d=0,double inc=0): nume(nm),tip(t),durata(d),incasari(inc)
{
    //std::cout<<"F const\n";
}

Film::~Film()
{
    nume="";
    tip="";
    durata=0;
    incasari=0;
    //std::cout<<"F destr\n";
}
void Film::operator=(const Film& other)
{
    this->nume=other.nume;
    this->tip=other.tip;
    this->durata=other.durata;
    this->incasari=other.incasari;
}
bool Film::operator==(const Film&other)
{
    if(this->nume!=other.nume)
        return false;
    if(this->tip!=other.tip)
        return false;
    if(this->durata!=other.durata)
        return false;
    if(this->incasari!=other.incasari)
        return false;
    return true;
}
std::istream& operator>> (std::istream& fin, Film& obj)
{
    std::cout<<"\nNumele filmului este: ";
    fin>>obj.nume;
    std::cout<<"\nTipul filmului este: ";
    fin>>obj.tip;
    std::cout<<"\nDurata filmului este: ";
    fin>>obj.durata;
    std::cout<<"\nIncasari filmului este: ";
    fin>>obj.incasari;
    return fin;
}
std::ostream& operator<< (std::ostream& fout, Film& obj)
{
    obj.afisare();
    return fout;
}
