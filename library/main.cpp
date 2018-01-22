
#include <iostream>
#include <string>
using namespace std;
#define limit 3

struct ksiazka{
    int ID;
    string tytul;
    string autor;
    int rok;
    string gatunek;
    ksiazka* nast;
    ksiazka(): ID(0), tytul(""), autor(""), rok(0), gatunek(""),nast(nullptr) {}
    void wypisz()
    {
        cout<<"ID:"<<ID<<endl;
        cout<<"Tytul:"<<tytul<<endl;
        cout<<"Autor:"<<autor<<endl;
        cout<<"Rok wydania:"<<rok<<endl;
        cout<<"Gatunek:"<<gatunek<<endl<<endl;
    }
};
struct Lista_ksiazki
{
    ksiazka* head;
    ksiazka* tail;
    Lista_ksiazki(): head(nullptr), tail(nullptr) {}
    void dodajksiazke();
    void pokazksiazki();
    void usunksiazke();
    void szukajtytul();
    void szukajautor();
    void szukajrok();
    void szukajgatunek();
};
void Lista_ksiazki::dodajksiazke()
{
    string tytul;
    string autor;
    int rok;
    string gatunek;
    bool dodac;
    cout<<"Tytul:"<<endl;
    cin.ignore();
    getline(cin,tytul);
    cout<<"Autor:"<<endl;
    cin.ignore();
    getline(cin,autor);
    cout<<"Rok wydania:"<<endl;
    cin>>rok;
    cout<<"Gatunek:"<<endl;
    cin.ignore();
    getline(cin, gatunek);
    cout<<"Dodac nastepna ksiazke? Tak-1 Nie-0"<<endl;
    cin>>dodac;
    if(head==nullptr)
    {
        head=new ksiazka;
        tail=head;
        head->ID=1;
        head->tytul=tytul;
        head->autor=autor;
        head->rok=rok;
        head->gatunek=gatunek;
    }
    else
    {
        tail->nast=new ksiazka;
        tail->nast->ID=tail->ID+1;
        tail=tail->nast;
        tail->tytul=tytul;
        tail->autor=autor;
        tail->rok=rok;
        tail->gatunek=gatunek;
    }
}
void Lista_ksiazki::pokazksiazki()
{
    ksiazka* tmp = head;
    while(tmp!=nullptr)
    {
    tmp->wypisz();
    tmp=tmp->nast;
    }
    
}
void Lista_ksiazki::usunksiazke()
{
    ksiazka* tmp= head;
    int ID;
    cout<<"Podaj ID:"<<endl;
    cin>>ID;
    if(ID==1)
    {tmp=tmp->nast;
        delete head;
        head=tmp;
        while(tmp!=nullptr)
        { tmp->ID--;
            tmp=tmp->nast;
        }
        return;
        
    }
        
        else{
    while(tmp!=nullptr)
    {
        if(tmp->nast->ID==ID)
        {
            ksiazka* tmp2=tmp->nast->nast;
            delete tmp->nast;
            tmp->nast=tmp2;
            while(tmp2!=nullptr)
            { tmp2->ID--;
                tmp2=tmp2->nast;
            }
            return;
        }
        tmp=tmp->nast;
    }
    cout << "Bledne ID"<< endl;
}
}

void Lista_ksiazki::szukajtytul()
{
    string tytulks;
    cin.ignore();
    getline(cin,tytulks);
    ksiazka* tmp= head;
    while(tmp!=nullptr)
    {if(tytulks==tmp->tytul)
    {
        tmp->wypisz();
    }
        tmp=tmp->nast;
    }
    
}
void Lista_ksiazki::szukajautor()
{
    string autorks;
    cin.ignore();
    getline(cin,autorks);
    ksiazka* tmp= head;
    while(tmp!=nullptr)
    {if(autorks==tmp->autor)
    {
        tmp->wypisz();
    }
        tmp=tmp->nast;
    }
    
}
void Lista_ksiazki::szukajrok()
{
    int rokks;
    cin>>rokks;
    ksiazka* tmp= head;
    while(tmp!=nullptr)
    {if(rokks==tmp->rok)
    {
        tmp->wypisz();
    }
        tmp=tmp->nast;
    }
    
}
void Lista_ksiazki::szukajgatunek()
{
    string gatunekks;
    cin.ignore();
    getline(cin,gatunekks);
    ksiazka* tmp= head;
    while(tmp!=nullptr)
    {if(gatunekks==tmp->gatunek)
    {
        tmp->wypisz();
    }
        tmp=tmp->nast;
    }
    
}




void szukajksiazke(Lista_ksiazki lk)
{
    int szukaj;
    cout<<"SZUKANIE KSIAZKI"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"1.Szukaj po tytule"<<endl;
    cout<<"2.Szukaj po autorze"<<endl;
    cout<<"3.Szukaj po roku wydania"<<endl;
    cout<<"4.Szukaj po gatunku"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"Wybor:";
    cin>>szukaj;
    
    
    switch(szukaj)
    {
        case 1: lk.szukajtytul();   break;
        case 2: lk.szukajautor();   break;
        case 3: lk.szukajrok();     break;
        case 4: lk.szukajgatunek(); break;
            
        default:
            cout<<"Pomylka";
            break;
            
            
    }
    
}
struct uzytkownik{
        int ID;
        string imie;
        string nazwisko;
        //int TAB[limit];
        uzytkownik* nast;
        uzytkownik(): ID(0), imie(""), nazwisko(""), /*TAB(0), */ nast(nullptr) {}
   
        void wypisz()
        {
            cout<<"ID:"<<ID<<endl;
            cout<<"Imie i nazwisko:"<<imie<<" "<<nazwisko<<endl;
        }
    
    };
    
struct Lista_uzytkownicy
    {
        uzytkownik* head;
        uzytkownik* tail;
        Lista_uzytkownicy(): head(nullptr), tail(nullptr) {}
        void dodajuzytkownika();
        void pokazuzytkownikow();
        void usunuzytkownika();
        void szukajimie();
        void szukajnazwisko();
    };
    
void Lista_uzytkownicy::dodajuzytkownika()
    {
        string imie;
        string nazwisko;
        bool dodac;
        cout<<"Imie:"<<endl;
        cin.ignore();
        getline(cin,imie);
        cout<<"Nazwisko:"<<endl;
        cin.ignore();
        getline(cin,nazwisko);
        cout<<"Dodac nastepnego uzytkownika? Tak-1 Nie-0"<<endl;
        cin>>dodac;
        if(head==nullptr)
        {
            head=new uzytkownik;
            tail=head;
            head->ID=1;
            head->imie=imie;
            head->nazwisko=nazwisko;
            
        }
        else
        {
            tail->nast=new uzytkownik;
            tail->nast->ID=tail->ID+1;
            tail=tail->nast;
            tail->imie=imie;
            tail->nazwisko=nazwisko;
        }
    }
    
void Lista_uzytkownicy::pokazuzytkownikow()
    {
        uzytkownik* tmp=head;
        while(tmp!=nullptr)
        {
            tmp->wypisz();
            tmp=tmp->nast;
        }
    }

void Lista_uzytkownicy::usunuzytkownika()
    {
        uzytkownik* tmp=head;
        int ID;
        cout<<"Podaj ID:"<<endl;
        cin>>ID;
        if(ID==1)
        {tmp=tmp->nast;
            delete head;
            while(tmp!=nullptr)
            {
                tmp->ID--;
                tmp=tmp-> nast;
            }
            return;
        }
        else{
            while(tmp!=nullptr)
            {
                if(tmp->nast->ID==ID)
            {
                uzytkownik* tmp2=tmp->nast->nast;
                delete tmp->nast;
                tmp->nast=tmp2;
                while(tmp2!=nullptr)
                { tmp2->ID--;
                    tmp2=tmp2->nast;
                }
                return;
            }
                tmp=tmp->nast;
        }
        cout<<"Bledne ID"<<endl;
        }
}

void Lista_uzytkownicy::szukajimie()
{
    string imieuz;
    cin.ignore();
    getline(cin,imieuz);
    uzytkownik* tmp=head;
    while(tmp!=nullptr)
    {if(imieuz==tmp->imie)
        tmp->wypisz();
        
        tmp=tmp->nast;
        }
}
void Lista_uzytkownicy::szukajnazwisko()
{
    string nazwiskouz;
    cin.ignore();
    getline(cin,nazwiskouz);
    uzytkownik* tmp=head;
    while(tmp!=nullptr)
    {if(nazwiskouz==tmp->nazwisko)
        tmp->wypisz();
        
        tmp=tmp->nast;
    }
}

void szukajuzytkownika(Lista_uzytkownicy lu)
{
    int szukaj;
    cout<<"SZUKANIE UZYTKOWNIKA"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"1.Szukaj po imieniu"<<endl;
    cout<<"2.Szukaj po nazwisku"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"Wybor:"<<endl;
    cin>>szukaj;
    
    switch(szukaj)
    {
        case 1: lu.szukajimie(); break;
        case 2: lu.szukajnazwisko(); break;
            
        default:
            cout<<"Pomylka";
            break;
    }
}
/*

void wypozyczksiazke()
{
}

void oddajksiazke()
{
}

void wyjscie ()
{
    
}
*/
int main()
{
    int wybor;
    Lista_ksiazki lk;
    Lista_uzytkownicy lu;
    
    do
    {
        
        cout<< "MENU GLOWNE:"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"1. Pokaz ksiazki"<<endl;
        cout<<"2. Dodaj ksiazke"<<endl;
        cout<<"3. Usun ksiazke"<<endl;
        cout<<"4. Wypozycz ksiazke"<<endl;
        cout<<"5. Szukaj ksiazke"<<endl;
        cout<<"6. Oddaj ksiazke"<<endl;
        cout<<"7. Pokaz uzytkownikow"<<endl;
        cout<<"8. Dodaj uzytkownika"<<endl;
        cout<<"9. Usun uzytkownika"<<endl;
        cout<<"10. Szukaj uzytkownika"<<endl;
        cout<<"11.Wyjscie"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Wybor:";
        cin>> wybor;
        
            switch (wybor)
        {
            case 1: lk.pokazksiazki(); break;
            case 2: lk.dodajksiazke(); break;
            case 3: lk.usunksiazke(); break;
            //case 4: wypozyczksiazke(); break;
            case 5: szukajksiazke(lk); break;
           // case 6: oddajksiazke(); break;
            case 7: lu.pokazuzytkownikow(); break;
            case 8: lu.dodajuzytkownika(); break;
            case 9: lu.usunuzytkownika(); break;
            case 10: szukajuzytkownika(lu); break;
           // case 11: wyjscie(); break;
              
            default:
                cout<<"Pomylka";
                break;
        }
    }
    while(wybor!=11);
    return 0;
}
