#include "Personal_Tehnic.h"

Personal_Tehnic::Personal_Tehnic(): Persoana()
{
    //std::cout<<"T const\n";
}
Personal_Tehnic::Personal_Tehnic(int c,std::string nm,Film f, double s): Persoana(c,nm,f,s)
{
    //std::cout<<"T const\n";
}
Personal_Tehnic::Personal_Tehnic(const Personal_Tehnic& other): Persoana(other)
{
    //std::cout<<"T copy\n";
}
Personal_Tehnic::~Personal_Tehnic()
{
    //std::cout<<"T destr\n";
}
double Personal_Tehnic::bonus()
{
    return 0;
}

void Personal_Tehnic::operator=(const Personal_Tehnic& obj)
{
    Persoana::operator=(obj);
}
std::istream& operator>> (std::istream& fin, Personal_Tehnic& obj)
{
    fin>>dynamic_cast<Persoana&>(obj);
    return fin;
}
std::ostream& operator<< (std::ostream& fout, Personal_Tehnic& obj)
{
    obj.afisare();
    return fout;
}
