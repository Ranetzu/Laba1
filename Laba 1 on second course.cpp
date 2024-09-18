#include <iostream>
#include <string>;

using namespace std;

class System {
private:
    int NumSHES; //Номер ЖЭС
    int NumHuman; //Количество людей, проживающих в районе
    int Oplata; //Стоимость оплаты
    int NumOplHuman; // Количество оплативших жителей
    int NumTerr; //Номер Района

public:
    System(int ns, int nh, int o, int noh, int terr);

    int GetNumSHES() const;
    int GetNumHuman() const;
    int GetOplata() const;
    int GetNumOplHuman() const;
    int GetNumTerr() const;
    int GetSumDolg() const;

    void AddNumShes(int f) {

        NumSHES = f;

    }
    void AddNumHuman(int c) {

        NumHuman = c;

    }
    void AddOplata(int l) {

        Oplata = l;

    }
    void AddNumOplHuman(int m) {

        NumOplHuman = m;

    }
    void AddNumTerr(int t) {

        NumTerr = t;

    }
};

System::System(int ns, int nh, int o, int noh, int terr) {

    if (ns < 0 or nh < 0 or o < 0 or noh < 0) {

        throw std::out_of_range("You Dead!");

    }

    NumSHES = ns;
    NumHuman = nh;
    Oplata = o;
    NumOplHuman = noh;
    NumTerr = terr;
}

int System::GetNumSHES() const {

    return NumSHES;

}
int System::GetNumHuman() const {

    return NumHuman;

}
int System::GetOplata() const {

    return Oplata;

}
int System::GetNumOplHuman() const {

    return NumOplHuman;

}
int System::GetNumTerr() const {

    return NumTerr;

}
int System::GetSumDolg() const {

    int Dolg = NumHuman * Oplata - NumOplHuman * Oplata;
    return Dolg;

}


int main()
{
    srand(time(0));
    System s(0, 0, 0, 0, 0);
    while (int k = 1) {
        cout << "Enter 1 for getting info about Shes or any button for exit." << endl;
        cin >> k;
        if (k != 1) {
            return 0;
        }
            cout << "Enter 0 for info about NumSHES, 1 for info about NumHuman, 2 for info about Oplata, 3 for info about NumOplHuman," << endl;
            cout << "4 for redact info about NumShes, 5 for redact info about NumHuman, 6 for redact info about Oplata," << endl;
            cout << "7 for redact NumOplHuman, 8 for info about NumTerr, 9 for redact info about NumTerr, 10 for info about GetSumDolg." << endl;
            int l;
            cin >> l;
            if (l == 0) {
                cout << s.GetNumSHES() << endl;
            }
            else if (l == 1) {
                cout << s.GetNumHuman() << endl;
            }
            else if (l == 2) {
                cout << s.GetOplata() << endl;
            }
            else if (l == 3) {
                cout << s.GetNumOplHuman() << endl;
            }
            else if (l == 4) {
                cout << "add new number:";
                unsigned int num;
                cin >> num;
                if (!cin.fail()) {
                    cout << "Unknown number. Please, try again.";
                    cin >> num;
                }
                s.AddNumShes(num);
                cout << s.GetNumSHES() << endl;
            }
            else if (l == 5) {
                cout << "add new number:";
                unsigned int num;
                cin >> num;
                if (cin.fail()) {
                    cout << "Unknown number. Please, try again.";
                    cin >> num;
                }
                s.AddNumHuman(num);
                cout << s.GetNumHuman() << endl;
            }
            else if (l == 6) {
                cout << "add new number:";
                unsigned int num;
                cin >> num;
                if (cin.fail()) {
                    cout << "Unknown number. Please, try again.";
                    cin >> num;
                }
                s.AddOplata(num);
                cout << s.GetOplata() << endl;
            }
            else if (l == 7) {
                cout << "add new number:";
                unsigned int num;
                cin >> num;
                if (cin.fail()) {
                    cout << "Unknown number. Please, try again.";
                    cin >> num;
                }
                else if (s.GetNumOplHuman() > s.GetNumHuman()) {

                    cout << "Can't be." << endl;


                }
                else {
                    s.AddNumOplHuman(num);
                    cout << s.GetNumOplHuman() << endl;
                }
            }
            else if (l == 8) {
                cout << s.GetNumTerr() << endl;
            }
            else if (l == 9) {
                cout << "add new number:";
                unsigned int num;
                cin >> num;
                if (cin.fail()) {
                    cout << "Unknown number. Please, try again.";
                    cin >> num;
                }
                s.AddNumTerr(num);
                cout << s.GetNumTerr() << endl;
            }
            else if (l == 10) {

                cout << s.GetSumDolg() << endl;

            }
    }

    return 0;
}

