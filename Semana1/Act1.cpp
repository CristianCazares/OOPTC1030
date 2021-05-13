#include <iostream>
#include <stdlib.h> //Limpiar pantalla
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

class Vendedor{
    public:
        string Cve_Vendedor;
        string Nombre;

};

class Inventario {
    public:
        string Cve_Articulo;
        string Descripcion;
        double Precio;
};

class Factura{
    public:
        string NoFactura;
        Vendedor VendedorF;
        Inventario InventarioF;
        int Cantidad;
        int Total;
};


string GETDATE(){
    char out[14];
    time_t t=time(NULL);
    strftime(out, sizeof(out), "%Y%m%d%H%S", localtime(&t));
    Sleep(2000);  // pauses for 2 seconds
    return out;
}



Vendedor vendedores[10];
int lenInventarios = 10;
Inventario inventarios[10];
Factura facturas[100];
int cont = 0;

void GenerarFactura();
void menu();
void nuevoVendedor();
void nuevoArticulo();
void imprimirSistema();
void pause();

int main(){
    system("cls");
    
    menu();

    return 0;
}

void menu(){
    cout<<"==SISTEMA DE FACTURAS=="<<endl;
    cout<<"\t1. Ingresar vendedor"<<endl;
    cout<<"\t2. Ingresar articulo"<<endl;
    cout<<"\t3. Imprimir vendedores y articulos"<<endl;
    cout<<"\t0. Salir"<<endl;
    int op;
    cout<<"Ingrese numero de seleccion: ";cin>>op;
    switch (op)
    {
        case 1:
            nuevoVendedor();
            break;
        case 2:
            nuevoArticulo();
            break;
        case 3:
            imprimirSistema();
            break;       
        case 0:
            exit(1);
            break;         
        default:
            cout<<"\n\nFavor de ingresar un numero disponible (1-3)";
            break;
    }
}



int iv = 0;
int lenVendedores = sizeof(vendedores)/sizeof(*vendedores);
void nuevoVendedor(){
    system("cls");
    cout<<"==Crear nuevo Vendedor";
    cout<<"\nEspacios disponibles: "<<lenVendedores-iv<<"/"<<lenVendedores<<endl;
    
    Vendedor nuevo;
    
    string clave;
    cout<<"\n\tIngrese clave de vendedor:";
    cin>>clave;

    string nombre;
    cout<<"\n\tIngrese primer nombre: ";
    cin>>nombre;
    string apellido;
    cout<<"\n\tIngrese primer apellido: ";
    cin>>apellido;
    string nombreCompleto = nombre + " " + apellido;

    vendedores[iv].Cve_Vendedor = clave;
    vendedores[iv].Nombre = nombreCompleto;
    cout<<"Vendedor " << vendedores[iv].Nombre <<" agregado a sistema.\n\n";
    iv++;
    system("PAUSE");
    main();
}

int ii = 0;
int lenInventarios = sizeof(inventarios)/sizeof(*inventarios);
void nuevoArticulo(){
    system("cls");
    cout<<"==Crear nuevo Articulo";
    cout<<"\nEspacios disponibles: "<<lenInventarios-ii<<"/"<<lenInventarios<<endl;
}

void imprimirSistema(){
    system("cls");
    cout<<"==Imprimir Sistema"<<endl;
    cout<<"\n=Vendedores: "<<endl;
    for (int i = 0; i < iv; i++)
    {
        cout<<"\tVendedor "<<i+1<<".\n";
        cout<<"\t-Clave: "<<vendedores[i].Cve_Vendedor<<endl;
        cout<<"\t-Nombre: "<<vendedores[i].Nombre<<"\n\n";
    }
    
}

void GeneraFactura(int cont, Factura factura[], Vendedor vendedor, Inventario inventario,int Cant){
    Factura newF;
    newF.NoFactura = "F"+GETDATE();
    newF.VendedorF = vendedor;
    newF.InventarioF = inventario;
    newF.Cantidad = Cant;
    newF.Total = Cant*newF.InventarioF.Precio;
    factura[cont] = newF;
}

/*void load(){
    Vendedor aux;
    aux = {"V152","Jeremias Springfield"};
    vendedores[0] = aux;
    aux = {"V342","Jose Luis Crespo"};
    vendedores[1] = aux;


    Inventario auxI;
    auxI = {"i500","Tornillo sin fin",2.01};
    inventarios[0] = auxI;
    auxI = {"i100","Tornillo con fin",2.23};
    inventarios[1] = auxI;
    auxI = {"i231","Tornillo buen fin",421.23};
    inventarios[2] = auxI;
    
    GeneraFactura(cont, facturas,vendedores[1],inventarios[2],14);
}*/