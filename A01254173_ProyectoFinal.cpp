#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include <sstream>
using namespace std;

//Santiago Ramírez Enríquez
//A01254173
//TC1033.1
//2/12/2021

class Comida
{
private:
    string nombre;
    int salud;
    bool revivir;
    string descripcion;

public:
    void setComida(string n, int s, bool r, string d)
    {
        nombre = n;
        salud = s;
        revivir = r;
        descripcion = d;
    }
    string getNombre()
    {
        return nombre;
    }
    int getSalud()
    {
        return salud;
    }
    bool getRevivir()
    {
        return revivir;
    }
    string getDescripcion()
    {
        return descripcion;
    }
};

//Clase pokemon

class Pokemon
{
private:
    string nombre;
    string tipo;
    int vidas;
    int vidaMAX;
    int fuerzaBruta;
    string descripcion;
    string frasePelea;
    string fraseComer;
    bool desmayado = false;

public:
    void set_Nombre(string n)
    {
        nombre = n;
    }
    void set_Tipo(string t)
    {
        tipo = t;
    }
    void set_Vidas(int v)
    {
        vidas = v;
        vidaMAX = v;
    }
    void set_FuerzaBruta(int fb)
    {
        fuerzaBruta = fb;
    }
    void set_Descripcion(string d)
    {
        descripcion = d;
    }
    void set_FrasePelea(string fp)
    {
        frasePelea = fp;
    }
    void set_FraseComer(string fc)
    {
        fraseComer = fc;
    }
    void set_Desmayado(bool d)
    {
        desmayado = d;
    }

    //get

    string get_Nombre()
    {
        return nombre;
    }
    string get_Tipo()
    {
        return tipo;
    }
    int get_vidas()
    {
        return vidas;
    }
    int get_vidaMAX()
    {
        return vidaMAX;
    }
    int get_fuerzaBruta()
    {
        return fuerzaBruta;
    }
    string get_Descripcion()
    {
        return descripcion;
    }
    string get_FrasePelea()
    {
        return frasePelea;
    }
    string get_FraseComer()
    {
        return fraseComer;
    }
    bool get_Desmayado()
    {
        return desmayado;
    }

    //OTRAS FUNCIONES

    void recibirAtaque(int a)
    {
        vidas -= a;
        if (vidas < 0)
            vidas = 0;
    }

    void atacarA(Pokemon &rival, string textoTurno, string textoGolpe)
    {
        cout << ">>>>>>>>>[" << textoTurno << nombre << "]<<<<<<<<<" << endl;
        int ataque = (rand() % fuerzaBruta)+1; //Usar esto para implentar tipos
        rival.recibirAtaque(ataque);
        cout << "[" << nombre << textoGolpe << ataque << " puntos de ataque a " << rival.get_Nombre() << "!!!]" << endl;
    }

    void Comer(Comida c)
    {
        if (c.getRevivir())
        {
            if (desmayado)
            {
                vidas = c.getSalud();
                if (vidas > vidaMAX)
                    vidas = vidaMAX;
                cout << nombre << " se comio un(a) " << c.getNombre() << endl;
                cout << "Sus puntos de salud ahora son " << vidas << " de " << vidaMAX << endl;
                cout << endl
                     << nombre << ": " << fraseComer << endl;
                desmayado = false;
            }
            else
            {
                cout << "No le puedes dar un revivir a un pokemon si no esta desmayado!" << endl;
            }
        }
        else
        {
            vidas += c.getSalud();
            if (vidas > vidaMAX)
                vidas = vidaMAX;
            cout << nombre << " se comio un(a) " << c.getNombre() << endl;
            cout << "Sus puntos de salud ahora son " << vidas << " de " << vidaMAX << endl;
            cout << endl
                 << nombre << ": " << fraseComer << endl;
        }
    }
    //CLASE DE POKEMON
};

//Funciones de utilidad

void ShowPokemon(Pokemon arrP[], int elementos)
{
    for (int i; i < elementos; i++)
    {
        cout << endl;
        cout << arrP[i].get_Nombre() << endl;
        cout << arrP[i].get_Tipo() << endl;
        cout << arrP[i].get_Descripcion() << endl;
        cout << arrP[i].get_vidas() << endl;
        cout << arrP[i].get_fuerzaBruta() << endl;
        cout << arrP[i].get_FrasePelea() << endl;
        cout << arrP[i].get_FraseComer() << endl;
        cout << endl;
    }
}

string RandString(string s1, string s2, string s3)
{ //Selecciona de 3 strings al azar para no hacerlo repetitivo
    switch (rand() % 3)
    {
    case 0:
        return s1;
        break;
    case 1:
        return s2;
        break;
    case 2:
        return s3;
        break;
    default:
        return "Prevencion de error";
        break;
    }
}

void Enter()
{
    system("pause");
}

void listarPokemon(Pokemon arrP[], int elementos)
{ //Muestra la seleccion para no tener que copiar y pegar el ciclo for
    for (int i = 0; i < elementos; i++)
    {
        cout << i + 1 << ".[" << arrP[i].get_Nombre() << "]" << endl;
    }
}

//===========================================PELEA================================================================

void Pelea(Pokemon arrP[], int elementos)
{
    int p1 = 1;
    int p2 = 1;
    while (p1 != 0)
    { //Selecciona al 1er pokemon
        system("CLS");
        cout << "===========!Pelea!==========" << endl;
        cout << "Selecciona al primer Pokemon para pelear:" << endl;
        listarPokemon(arrP, elementos);
        cout << "0.[Cancelar la pelea]" << endl;
        cin >> p1;
        if ((p1 >= 1 && p1 <= elementos))
        {
            if (arrP[p1 - 1].get_Desmayado())
            {
                cout << "Este pokemon esta desmayado.";
                cout << "Para poder usarlo darle un revivir.";
                Enter();
            }
            else
            {
                cout << "Seleccionaste a:[" << arrP[p1 - 1].get_Nombre() << "]!!!!!!!" << endl;
                cout << arrP[p1 - 1].get_Nombre() << ":" << arrP[p1 - 1].get_FrasePelea() << endl;
                Enter();
                break;
            }
        }
    }

    while (p1 != 0 && p2 != 0)
    { //Selecciona al 2do pokemon
        system("CLS");
        cout << "===========!Pelea!==========" << endl;
        cout << "Selecciona al segundo Pokemon para pelear:" << endl;
        listarPokemon(arrP, elementos);
        cout << "0.[Cancelar la pelea]" << endl;
        cin >> p2;
        if ((p2 >= 1 && p2 <= elementos))
        {
            if (arrP[p2 - 1].get_Desmayado())
            {
                cout << "Este pokemon esta desmayado." << endl;
                cout << "Para poder usarlo darle un revivir." << endl;
                Enter();
            }
            else if (p1 == p2)
            {
                cout << "No puedes elegir 2 veces al mismo pokemon" << endl;
                ;
                Enter();
            }
            else
            {
                cout << "Seleccionaste a:[" << arrP[p2 - 1].get_Nombre() << "]!!!!!!!" << endl;
                cout << arrP[p2 - 1].get_Nombre() << ":" << arrP[p2 - 1].get_FrasePelea() << endl;
                Enter();
                break;
            }
        }
    }

    p1 -= 1; //Para llamar a las clases mas facil se le resta 1
    p2 -= 1;

    if (p1 != -1 && p2 != -1)
    {
        //COMIENZA EL COMBATE ===========================
        system("CLS");
        cout << "====!!!!Comienza el combate!!!!====" << endl;
        cout << "--------!!!!!!!!!!!!!!!!!!!--------" << endl;
        cout << "[" << arrP[p1].get_Nombre() << "] VS [" << arrP[p2].get_Nombre() << "]" << endl;
        cout << "--------!!!!!!!!!!!!!!!!!!!--------" << endl;
        Enter();

        //Combate
        int turno = 1;
        while (arrP[p1].get_vidas() > 0 && arrP[p2].get_vidas() > 0)
        {
            system("CLS");
            string textoTurno = RandString("Turno de ", "Ahora toca ", "Sigue ");
            string textoGolpe = RandString(" ataca y hace ", " golpea y consigue darle ", " le da ");
            if (turno % 2 != 0)
            {
                arrP[p1].atacarA(arrP[p2], textoTurno, textoGolpe);
            }
            else
            {
                arrP[p2].atacarA(arrP[p1], textoTurno, textoGolpe);
            }
            cout << "Vida de " << arrP[p1].get_Nombre() << ": " << arrP[p1].get_vidas() << endl;
            cout << "Vida de " << arrP[p2].get_Nombre() << ": " << arrP[p2].get_vidas() << endl;
            Enter();
            turno++;
        }

        //Finalizar Combate
        system("CLS");
        if (arrP[p1].get_vidas() > arrP[p2].get_vidas())
        {
            arrP[p2].set_Desmayado(true);
            cout << "![[[" << arrP[p2].get_Nombre() << " se ha desmayado]]]!" << endl;
            cout << "!!!!!![Gana " << arrP[p1].get_Nombre() << "]!!!!!!" << endl;
            Enter();
        }
        else
        {
            arrP[p1].set_Desmayado(true);
            cout << "![[[" << arrP[p1].get_Nombre() << " se ha desmayado]]]!" << endl;
            cout << "!!!!!![Gana " << arrP[p2].get_Nombre() << "]!!!!!!" << endl;
            Enter();
        }
    }
}

//=================================================STATS============================================================

void Stats(Pokemon arrP[], int elementos)
{
    int seleccion = 1;
    while (seleccion != 0)
    {
        system("CLS");
        cout << "===========Stats==========" << endl;
        cout << "Selecciona un pokemon:" << endl;
        listarPokemon(arrP, elementos);
        cout << "0.[Salir de modo Stats]" << endl;
        cin >> seleccion;
        if ((seleccion >= 1 && seleccion <= elementos))
        {
            system("CLS");
            cout << "==================================================================================================" << endl;
            cout << "Nombre:[" << arrP[seleccion - 1].get_Nombre() << "]" << endl;
            cout << "Status:[";
            if (arrP[seleccion - 1].get_Desmayado())
            {
                cout << "DESMAYADO]";
            }
            else
            {
                cout << "Activo]";
            }
            cout << endl;
            cout << "Puntos de vida:[" << arrP[seleccion - 1].get_vidas() << " de " << arrP[seleccion - 1].get_vidaMAX() << "]" << endl;
            cout << "Puntos de fuerza:[" << arrP[seleccion - 1].get_fuerzaBruta() << "]" << endl;
            cout << "Descripcion del pokemon:\n"
                 << arrP[seleccion - 1].get_Descripcion() << endl;
            cout << "==================================================================================================" << endl;
            Enter();
        }
    }
}

//===========================================================COMER=============================================

void Comer(Pokemon arrP[], Comida arrC[], int elementos, int elementosC)
{
    int seleccion = 1;
    int seleccion2 = 1;
    while (seleccion != 0)
    {
        system("CLS");
        cout << "===========Comer==========" << endl;
        cout << "Selecciona un pokemon:" << endl;
        listarPokemon(arrP, elementos);
        cout << "0.[Salir de modo Comer]" << endl;
        cin >> seleccion;
        if ((seleccion >= 1 && seleccion <= elementos))
        {
            while (seleccion2 != 0)
            {
                system("CLS");
                cout << "============================" << endl;
                cout << "Que le quieres dar de comer?" << endl;
                cout << "============================" << endl;
                for (int c = 0; c < elementosC; c++)
                {
                    cout << c + 1 << ".[" << arrC[c].getNombre() << "] --- " << arrC[c].getDescripcion() << endl;
                }
                cout << "0.[Atras]" << endl;
                cin >> seleccion2;
                if (seleccion2 >= 1 && seleccion2 <= elementosC)
                {
                    system("CLS");
                    arrP[seleccion - 1].Comer(arrC[seleccion2 - 1]);
                    Enter();
                    break;
                }
            }
        }
    }
}

//====================================MAIN===============================================================================================
//=====INICIO
int main()
{
    int elementosArray = 10;
    Pokemon arrPokemon[10];
    Pokemon unPokemon;
    //read
    string strInput;
    string nombre, tipo, vidas, fuerzaBruta, descripcion, frasePelea, fraseComer;
    stringstream ss;

    ifstream inf("17_1_30_Pokemon_Inventario.txt");

    if (!inf)
    {
        cerr << "No se pudo abrir el archivo";
        exit(1);
    }

    int i = 0;

    getline(inf, strInput); //saltate la 1ra linea
    while (inf)
    {
        if (inf.eof())
            break;
        getline(inf, strInput);

        stringstream ss(strInput); //for tokenize
        getline(ss, nombre, ',');
        getline(ss, tipo, ',');
        getline(ss, vidas, ',');
        getline(ss, fuerzaBruta, ',');
        getline(ss, descripcion, ',');
        getline(ss, frasePelea, ',');
        getline(ss, fraseComer, ',');

        unPokemon.set_Nombre(nombre);
        unPokemon.set_Tipo(tipo);
        unPokemon.set_Vidas(stoi(vidas));
        unPokemon.set_FuerzaBruta(stoi(fuerzaBruta));
        unPokemon.set_Descripcion(descripcion);
        unPokemon.set_FrasePelea(frasePelea);
        unPokemon.set_FraseComer(fraseComer);

        arrPokemon[i] = unPokemon;
        i++;
    }
    inf.close();

    //=================CREAR COMIDA==========
    Comida arrComida[3];
    int lenComida = 3;
    arrComida[0].setComida("Manzana", 50, false, "Manzana roja que recupera 50 de salud");
    arrComida[1].setComida("Mora azul", 15, false, "Mora chica que proporciona 15 de salud");
    arrComida[2].setComida("Revivir", 50, true, "Roca dulce que revive a un pokemon desmayado y da 30 de salud");

    //================================MENU PRINCIPAL====================================
    int accion;
    while (true)
    {
        system("CLS");
        cout << "======Pokemon++======" << endl;
        cout << endl;
        cout << "Que quieres hacer?" << endl;
        cout << "1.[Pelea]     2.[Comer]" << endl;
        cout << "3.[Status]    0.[Salir]" << endl;
        cout << endl;
        cin >> accion;

        switch (accion)
        {
        case 1:
            Pelea(arrPokemon, i);
            break;
        case 2:
            Comer(arrPokemon, arrComida, i, lenComida);
            break;
        case 3:
            Stats(arrPokemon, i);
            break;
        case 0:
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}

//|`  \      //
//  ----(c^:)//
//|´  /      //

//Mono a palos oficial. Hecho por Santiago Ramirez Enriquez.
//Sip, usare esto como firma artistica.