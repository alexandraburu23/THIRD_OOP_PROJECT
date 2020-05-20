#include <iostream>
#include<vector>
#include<set>
#include<tuple>
#include<string>
#include "Persoana.h"
#include "Actor.h"
#include "Film.h"
#include "Regizor.h"
#include "Personal_Tehnic.h"
#include "NotAnOption.h"
#include <typeinfo>


class exception
{
public:
    exception () noexcept;
    exception (const exception&) noexcept;
    exception& operator= (const exception&) noexcept;
    virtual ~exception();
    virtual const char* what() const noexcept;
};
template<typename T>

class FirmaDistributie
{
    std::vector<Film*> filme;
    std::vector<T*> personal;
    static int nr_personal;
    static int nr_filme;
    friend std::istream& operator>>(std::istream&, FirmaDistributie<T>&);
    friend std::ostream& operator<<(std::ostream& fout, FirmaDistributie<T>&);

public:

    FirmaDistributie()
    {

    }
    FirmaDistributie(std::vector<Film*> f,std::vector<T*> p)
    {
        for(int i=0; i<p.size(); ++i)
            personal.push_back(p[i]);
        nr_personal+=p.size();
        for(int i=0; i<f.size(); ++i)
            filme.push_back(f[i]);
        nr_filme+=f.size();
    }
    ~FirmaDistributie()
    {
        nr_personal-=personal.size();
        nr_filme-=filme.size();
        for(int i=personal.size()-1; i>=0; --i)
            delete personal[i];
        for(int i=filme.size()-1; i>=0; --i)
            delete filme[i];
    }
    void addPersonal(T x)
    {
        const std::type_info& r1 = typeid(x);
        std::cout<<"Am adaugat angajat de tipul "<<r1.name()<<'\n';
        T* pers=new T(x);
        personal.push_back(pers);
        bool flag=true;
        for(int i=0; i<filme.size(); ++i)
            if(*filme[i]==x.get_film())
            {
                flag=false;
                break;
            }
        if(flag)
        {
            Film* temp=new Film(x.get_film());
            filme.push_back(temp);
            nr_filme++;
        }
        nr_personal++;
    }
    void addFilm(Film f)
    {
        Film* temp=new Film(f);
        filme.push_back(temp);
        nr_filme++;
    }
    void operator= (const FirmaDistributie& other)
    {
        for(int i=0; i<other.personal.size(); ++i)
        {
            T* pers=new T(*other.personal[i]);
            personal.push_back(pers);
        }
        nr_personal+=other.personal.size();
        for(int i=0; i<other.filme.size(); ++i)
        {
            Film* temp=new Film(*other.filme[i]);
            filme.push_back(temp);
        }
        nr_filme+=other.filme.size();
    }

    FirmaDistributie(const FirmaDistributie& other)
    {
        for(int i=0; i<other.personal.size(); ++i)
        {
            T* pers=new T(*other.personal[i]);
            personal.push_back(pers);
        }
        nr_personal+=other.personal.size();
        for(int i=0; i<other.filme.size(); ++i)
        {
            Film* temp=new Film(*other.filme[i]);
            filme.push_back(temp);
        }
        nr_filme+=other.filme.size();
    }

};

std::istream& operator>>(std::istream& fin, FirmaDistributie<Regizor>& vect_reg)
{
    int nr_reg;
    std::cout<<"Introduceti nr de regizori ai firmei: ";
    fin>>nr_reg;
    for(int i=0; i<nr_reg; ++i)
    {
        Regizor* temp=new Regizor;
        fin>>*temp;
        vect_reg.addPersonal(*temp);
    }
    return fin;
}
std::istream& operator>>(std::istream& fin, FirmaDistributie<Personal_Tehnic>& vect_teh)
{
    int nr_teh;
    std::cout<<"Introduceti nr de tehnicieni ai firmei: ";
    fin>>nr_teh;
    for(int i=0; i<nr_teh; ++i)
    {
        Personal_Tehnic* temp=new Personal_Tehnic;
        fin>>*temp;
        vect_teh.addPersonal(*temp);
    }
    return fin;
}

std::ostream& operator<<(std::ostream& fout, FirmaDistributie<Regizor>& other)
{
    std::cout<<'\n'<<"Nr de regizori ai firmei este: "<<other.personal.size()<<'\n';
    for(int i=0; i<other.personal.size(); ++i)
    {
        fout<<*other.personal[i];
        fout<<'\n';
    }
    std::cout<<"Nr de filme ale firmei este: "<<other.filme.size()<<'\n';
    for(int i=0; i<other.filme.size(); ++i)
    {
        other.filme[i]->afisare();
        fout<<'\n';
    }
    return fout;
}

std::ostream& operator<<(std::ostream& fout, FirmaDistributie<Personal_Tehnic>& other)
{
    std::cout<<'\n'<<"Nr de tehnicieni ai firmei este: "<<other.personal.size()<<'\n';
    for(int i=0; i<other.personal.size(); ++i)
    {
        fout<<*other.personal[i];
        fout<<'\n';
    }
    std::cout<<"Nr de filme ale firmei este: "<<other.filme.size()<<'\n';
    for(int i=0; i<other.filme.size(); ++i)
    {
        other.filme[i]->afisare();
        fout<<'\n';
    }
    return fout;
}

template<>
class FirmaDistributie<Actor>
{
    std::vector<Film*> filme;
    std::vector<Actor*> personal;
    static int nr_actori_principali;
    static int nr_personal;
    static int nr_filme;
    friend std::istream& operator>>(std::istream&, FirmaDistributie<Actor>&);
    friend std::ostream& operator<<(std::ostream& fout, FirmaDistributie<Actor>&);

public:

    FirmaDistributie() {}
    FirmaDistributie(std::vector<Film*> f,std::vector<Actor*> p)
    {
        for(int i=0; i<p.size(); ++i)
        {
            personal.push_back(p[i]);
            if(p[i]->get_rol()=="principal")
                nr_actori_principali++;
        }
        nr_personal+=p.size();
        for(int i=0; i<f.size(); ++i)
            filme.push_back(f[i]);
        nr_filme+=f.size();
    }
    ~FirmaDistributie()
    {
        nr_personal-=personal.size();
        nr_filme-=filme.size();
        for(int i=personal.size()-1; i>=0; --i)
        {
            if(personal[i]->get_rol()=="principal")
                nr_actori_principali--;
            delete personal[i];

        }
        for(int i=filme.size()-1; i>=0; --i)
            delete filme[i];
    }
    void addPersonal(Actor x)
    {
        const std::type_info& r1 = typeid(x);
        std::cout<<"Am adaugat angajat de tipul "<<r1.name()<<'\n';
        Actor* pers=new Actor(x);
        personal.push_back(pers);
        bool flag=true;
        for(int i=0; i<filme.size(); ++i)
            if(*filme[i]==x.get_film())
            {
                flag=false;
                break;
            }
        if(flag)
        {
            addFilm(x.get_film());
        }
        nr_personal++;
        if(x.get_rol()=="principal")
            nr_actori_principali++;
    }
    void addFilm(Film f)
    {
        Film* temp=new Film(f);
        filme.push_back(temp);
        nr_filme++;
    }
    void operator= (const FirmaDistributie& other)
    {
        for(int i=0; i<other.personal.size(); ++i)
        {
            Actor* pers=new Actor(*other.personal[i]);
            personal.push_back(pers);
            if(pers->get_rol()=="principal")
                nr_actori_principali++;
        }
        nr_personal+=other.personal.size();
        for(int i=0; i<other.filme.size(); ++i)
        {
            Film* temp=new Film(*other.filme[i]);
            filme.push_back(temp);
        }
        nr_filme+=other.filme.size();
    }
    FirmaDistributie(const FirmaDistributie& other)
    {
        for(int i=0; i<other.personal.size(); ++i)
        {
            Actor* pers=new Actor(*other.personal[i]);
            personal.push_back(pers);
            if((other.personal[i])->get_rol()=="principal")
                nr_actori_principali++;
        }
        nr_personal+=other.personal.size();
        for(int i=0; i<other.filme.size(); ++i)
        {
            Film* temp=new Film(*other.filme[i]);
            filme.push_back(temp);
        }
        nr_filme+=other.filme.size();
    }
    static int get_numar_actori()
    {
        return nr_actori_principali;
    }

};

std::ostream& operator<<(std::ostream& fout, FirmaDistributie<Actor>& other)
{
    std::cout<<'\n'<<"Nr de actori ai firmei este: "<<other.personal.size()<<'\n';
    for(int i=0; i<other.personal.size(); ++i)
    {
        fout<<*other.personal[i];
        fout<<'\n';
    }
    std::cout<<"Nr de filme ale firmei este: "<<other.filme.size()<<'\n';
    for(int i=0; i<other.filme.size(); ++i)
    {
        other.filme[i]->afisare();
        fout<<'\n';
    }
    return fout;
}


std::istream& operator>>(std::istream& fin, FirmaDistributie<Actor>& vect_act)
{
    int nr_actori;
    std::cout<<"Introduceti nr de actori ai firmei: ";
    fin>>nr_actori;
    for(int i=0; i<nr_actori; ++i)
    {
        Actor* temp=new Actor;
        fin>>*temp;
        vect_act.addPersonal(*temp);
    }
    return fin;

}

template <typename T>
int FirmaDistributie<T>::nr_filme=0;
template <typename T>
int FirmaDistributie<T>::nr_personal=0;
int FirmaDistributie<Actor>::nr_actori_principali=0;
int FirmaDistributie<Actor>::nr_personal=0;
int FirmaDistributie<Actor>::nr_filme=0;


void afisare_meniu()
{
    std::cout<<"1.Cititi n persoane si filmele aferente. \n";
    std::cout<<"2.Afisati structura de n persoane. \n";
    std::cout<<"3.Adaugare actor in firma de distributie. \n";
    std::cout<<"4.Adaugare regizor in firma de distributie. \n";
    std::cout<<"5.Adaugare personal tehnic in firma de distributie. \n";
    std::cout<<"6.Afisare firma de distributie. \n";
    std::cout<<"7.Aflati nr de actori principali din firma de distributie. \n";
    std::cout<<"8.Exit. \n";


}



int main()
{
    Film f1("Mammamia","comedie",100,100000);
    //Actor om(6,"Andreas",f1,1000,"principal");
    //Regizor om2(6,"Andreas",f1,1000);
    //Persoana *pers = new Personal_Tehnic(6,"Andreas",f1,1000);
    //std::cout<<*pers;

    FirmaDistributie<Personal_Tehnic> fp;
    FirmaDistributie<Actor> fa;
    FirmaDistributie<Regizor> fr;
    std::set<std::tuple<Persoana*, Film*, double>> structura;
    do
    {
        try
        {
            afisare_meniu();
            int op;
            std::cin>>op;
            if(op==1)
            {
                int n;
                std::cout<<"nr de persoane: ";
                std::cin>>n;
                for(int i=0; i<n; ++i)
                {
                    do
                    {
                        int p;
                        std::cout<<"Alegeti tipul de persoana (1=actor, 2=regizor, 3=personal tehnic): ";
                        std::cin>>p;
                        if(p==1)
                        {
                            Actor* a= new Actor;
                            std::cin>>*a;
                            Film* f=new Film(a->get_film());
                            double b=a->bonus();
                            std::tuple<Persoana*, Film*, double> temp =std::make_tuple (a,f,b);
                            structura.insert(temp);
                            break;
                        }
                        else if(p==2)
                        {
                            Regizor* r= new Regizor;
                            std::cin>>*r;
                            Film* f=new Film(r->get_film());
                            double b=r->bonus();
                            std::tuple<Persoana*, Film*, double> temp =std::make_tuple (r,f,b);
                            structura.insert(temp);
                            break;
                        }
                        else if(p==3)
                        {
                            Personal_Tehnic* p= new Personal_Tehnic;
                            std::cin>>*p;
                            Film* f=new Film(p->get_film());
                            double b=p->bonus();
                            std::tuple<Persoana*, Film*, double> temp =std::make_tuple (p,f,b);
                            structura.insert(temp);
                            break;
                        }
                        else std::cout<<"Nu e un tip de persoana. Alegeti din nou. \n";
                    }
                    while(true);

                }

            }
            else if(op==2)
            {
                int nr=1;
                for(std::set<std::tuple<Persoana*,Film*,double>>::iterator it=structura.begin(); it!=structura.end(); ++it)
                {
                    std::cout<<"Elementul "<<nr++<<'\n';
                    std::tuple<Persoana*,Film*,double> temp=*it;
                    Persoana* p=std::get<0>(temp);
                    std::cout<<*p;
                    Film * f=std::get<1>(temp);
                    std::cout<<*f;
                    double b=std::get<2>(temp);
                    std::cout<<"Bonus: "<<b<<"\n\n";
                }
            }
            else if(op==3)
            {
                Actor temp;
                std::cin>>temp;
                fa.addPersonal(temp);
            }
            else if(op==4)
            {
                Regizor temp;
                std::cin>>temp;
                fr.addPersonal(temp);
            }
            else if(op==5)
            {
                Personal_Tehnic temp;
                std::cin>>temp;
                fp.addPersonal(temp);
            }
            else if(op==6)
            {
                std::cout<<"Actori: \n"<<fa<<'\n';
                std::cout<<"Regizori: \n"<<fr<<'\n';
                std::cout<<"Personal tehnic: \n"<<fp<<'\n';
            }
            else if(op==7)
            {
                std::cout<<"Nr de actori principali este: "<<fa.get_numar_actori()<<'\n';
            }
            else if(op==8) break;
            else throw(NotAnOption());
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << "\n\n";
            break;
        }
    }
    while(true);


    return 0;
}
