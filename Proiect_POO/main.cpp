#include <iostream>
#include <cstring>
using namespace std;

class Note{

    public:
        void init_note(int x);
        void af_medie();
        Note& operator += (Note&);
        Note& operator += (int);
        Note& operator -= (Note&);
        Note& operator -= (int);
        Note operator + ();
        Note operator - ();
        friend Note operator + (Note&, Note&);
        friend Note operator + (Note&, int);
        friend Note operator + (int, Note&);
        friend Note operator - (Note&, Note&);
        friend Note operator - (Note&, int);
        friend Note operator - (int, Note&);
        friend bool operator == (Note&, Note&);
        friend bool operator != (Note&, Note&);
        friend std::ifstream& operator >> (std::ifstream&, Note &);
        friend std::istream& operator >> (std::istream&, Note &);
        friend std::ofstream& operator << (std::ofstream&, Note &);
        friend std::ostream& operator >> (std::ostream&, Note &);
    private:
        int nr_nota=0;
        int note[30];
        int medie=0;

};

class Catalog{

    public:
        void init_materie(char nume[20]);
        void afisare_materie();
    private:
        Note nott;
        char Materie[20];
};

class Elev
{
    public:
        void init_elev(char nume[20],char prenume[20],char cnp[20],char adresa[50], int varsta);
        void afisare_elev();
    private:
        Catalog cat;
        char Nume[20],Prenume[20],CNP[20],Adresa[50];
        int Varsta;
};











inline void Elev::init_elev(char nume[20],char prenume[20],char cnp[20],char adresa[50], int varsta)
{
    int i;
    strlen(nume);
    for(i=0;i<strlen(nume);i++)
        this->Nume[i]=nume[i];
    for(i=0;i<strlen(prenume);i++)
        this->Prenume[i]=prenume[i];
    for(i=0;i<strlen(cnp);i++)
        this->CNP[i]=cnp[i];
    for(i=0;i<strlen(adresa);i++)
        this->Adresa[i]=adresa[i];
    this->Varsta=varsta;

}

inline void Catalog::init_materie(char nume[20])
{
    int i;
    for(i=0;i<strlen(nume);i++)
        this->Materie[i]=nume[i];
}

inline void Note::init_note(int x)
{
    nr_nota++;
    this->note[nr_nota]=x;
}

inline void Elev::afisare_elev()
{
    int i;
    cout<<"Nume: ";
    i=0;
        while((int(Nume[i])>=97&&int(Nume[i])<=122)||(int(Nume[i])>=65&&int(Nume[i]<=90)))
        {
            cout<<Nume[i];
            i++;
        }
    cout<<endl;
    cout<<"Prenume: ";
    i=0;
        while((int(Prenume[i])>=97&&int(Prenume[i])<=122)||(int(Prenume[i])>=65&&int(Prenume[i]<=90)))
        {
        cout<<Prenume[i];
        i++;
        }
    cout<<endl;

    cout<<"CNP: ";
    for(i=0;i<strlen(CNP);i++)
        cout<<CNP[i];
    cout<<endl;

    cout<<"Adresa: ";
    i=0;
        while((int(Prenume[i])>=97&&int(Prenume[i])<=122)||(int(Prenume[i])>=65&&int(Prenume[i]<=90)))
    {
        cout<<Adresa[i];
        i++;
    }
    cout<<endl;
    cout<<"Varsta: "<<Varsta<<endl;
}

inline void Catalog::afisare_materie()
{
    int i;
    for(i=0;i<strlen(Materie);i++)
        cout<<Materie[i];
    cout<<endl;
}





inline void Note::af_medie()
{
    float s=0;
    int i;
    for(i=1;i<=nr_nota;i++)
        s+=note[i];
    cout<<"Media:";
    cout<<s/nr_nota<<endl;
}

Note& Note::operator += (Note & n1)
{
    medie= n1.medie + medie;
    return *this;
}

Note& Note::operator += (int n1)
{
    medie= medie + n1;
    return *this;
}

Note& Note::operator -= (Note & n1)
{
    medie -= n1.medie;
    return *this;
}

Note& Note::operator -= (int n1)
{
    medie= medie - n1;
    return *this;
}

Note Note::operator + ()
{
    return *this;
}

Note Note::operator - ()
{
    return *this;
}

Note operator +(Note& n1, Note& n2)
{
    Note rez(n1);
    rez += n2;
    return rez;
}

Note operator +(Note& n1, int n2)
{
    Note rez(n1);
    rez += n2;
    return rez;
}

Note operator +(int n1, Note& n2)
{
    Note rez(n2);
    rez += n2;
    return rez;
}

Note operator -(Note& n1, Note n2)
{
    Note rez(n1);
    rez -= n2;
    return rez;
}
Note operator -(Note& n1, int n2)
{
    Note rez(n1);
    rez -= n2;
    return rez;
}
Note operator -(int n1, Note& n2)
{
    Note rez(n2);
    rez -= n2;
    return rez;
}

bool operator == (Note& n1, Note& n2)
{
    if(n1.medie!=n2.medie)
        return false;
    else
        return true;
}

bool operator != (Note& n1, Note& n2)
{
    if(n1.medie==n2.medie)
        return false;
    else
        return true;
}

/*
std::ifstream& operator >> (std::ifstream& stream, Note & n1){
        int i;
        for(i=0;i<n1.nr_nota;i++)
            stream >> n1.note[i];
    return stream;
}

std::istream& operator >> (std::istream& stream, Note & n1){
        int i;
        for(i=0;i<n1.nr_nota;i++)
            stream >> n1.note[i];
    return stream;
}

std::ofstream& operator << (std::ofstream& stream, Note & n1){
        int i;
        for(i=0;i<n1.nr_nota;i++)
            stream << n1.note[i] << " ";
        stream << "\n";
    }
    return stream;
}

std::ostream& operator << (std::ostream& stream, Note & n1){
        int i;
        for(i=0;i<n1.nr_nota;i++)
            stream << n1.note[i] << " ";
        stream << "\n";
    }
    return stream;
}
*/

int main()
{
    /*
    Elev e1;
    e1.init_elev("Marcel","Adrian","123","Arges",18);
    e1.afisare_elev();
    Note nt;
    Catalog ct;
    nt.init_note(1);
    nt.af_medie();
    ct.init_materie("Istorie");
    ct.afisare_materie();
    */
    Elev e1;
    e1.init_elev("Ana","Floare","124","Bacau",19);
    e1.afisare_elev();
    Note nt;
    Catalog ct;
    nt.init_note(1);
    nt.init_note(9);
    nt.af_medie();
    ct.init_materie("Istorie");
    ct.afisare_materie();
    return 0;
}
