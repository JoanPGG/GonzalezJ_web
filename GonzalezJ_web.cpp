#include <iostream>
#include <string>

using namespace std;

class SessioUsuari
{
private:
    string nomUsuari;
    int tempsLimitSegons;
    bool activa;

    void tancarSessio()
    {
        activa = false;
    }

public:
    SessioUsuari()
        : nomUsuari("convidat"), tempsLimitSegons(300), activa(true)
    {
    }

    explicit SessioUsuari(string nom)
        : nomUsuari(nom), tempsLimitSegons(600), activa(true)
    {
    }

    SessioUsuari(string nom, int temps)
        : nomUsuari(nom), tempsLimitSegons(temps <= 0 ? 60 : temps), activa(true)
    {
    }

    string getNomUsuari() const
    {
        return nomUsuari;
    }

    bool isActiva() const
    {
        return activa;
    }

    void ampliarTemps(int segons)
    {
        if (segons > 0)
        {
            tempsLimitSegons += segons;
        }
    }

    ~SessioUsuari()
    {
        if (activa)
        {
            tancarSessio();

            cout << "[AUDITORIA] La sessio de "
                << nomUsuari
                << " s'ha tancat automaticament."
                << endl;
        }
    }
};

int main()
{
    {
        SessioUsuari sessio("Xavi", 300);

        cout << "Usuari: " << sessio.getNomUsuari() << endl;

        if (sessio.isActiva())
        {
            cout << "Sessio activa" << endl;
        }

        sessio.ampliarTemps(100);
    }

    cout << "Fi del programa" << endl;

    return 0;
}