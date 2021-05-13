#include <iostream>
#include <stdlib.h> //Limpiar pantalla
#include <string>
#include <ctime>
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


std::string GETDATE() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%Y%m%d%H%S",timeinfo);
    std::string str(buffer);

    std::cout << str;

    return str;    
};



Vendedor vendedores[10];

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

    Inventario nuevo;
    
    string clave;
    cout<<"\n\tIngrese clave del articulo:";
    cin>>clave;

    string descripcion;
    cout<<"\n\tIngrese descripcion del articulo: ";
    cin>>descripcion;

    double precio;
    cout<<"\n\tIngrese el precio del articulo: ";
    cin>>precio;
    

    inventarios[ii].Cve_Articulo = clave;
    inventarios[ii].Descripcion = descripcion;
    inventarios[ii].Precio = precio;
    cout<<"Articulo " << inventarios[ii].Descripcion <<" agregado a sistema.\n\n";
    ii++;
    system("PAUSE");
    main();
}



void imprimirSistema(){
    system("cls");
    cout<<"==Imprimir Sistema"<<endl;
    cout<<"\n=Vendedores: "<<endl;
    if (iv <= 0) {
        cout<<"\tNo hay vendedores en sistema"<<endl;
    }
    else {
       for (int i = 0; i < iv; i++)
        {
            cout<<"\tVendedor "<<i+1<<".\n";
            cout<<"\t-Clave: "<<vendedores[i].Cve_Vendedor<<endl;
            cout<<"\t-Nombre: "<<vendedores[i].Nombre<<"\n\n";
        } 
    }

    cout<<"\n=Inventario: "<<endl;
    if (ii <= 0) {
        cout<<"\tNo hay Articulos en invetario"<<endl;
    }
    else {
        for (int i = 0; i < ii; i++)
        {
            cout<<"\tArticulo "<<i+1<<".\n";
            cout<<"\t-Clave: "<<inventarios[i].Cve_Articulo<<endl;
            cout<<"\t-Descripcion: "<<inventarios[i].Descripcion<<endl;
            cout<<"\t-Precio: "<<inventarios[i].Precio<<"\n\n";
        }
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
