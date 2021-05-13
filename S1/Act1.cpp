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


void GeneraFactura(int cont, Factura factura[], Vendedor vendedor, Inventario inventario,int Cant){
    Factura newF;
    newF.NoFactura = "F"+GETDATE();
    newF.VendedorF = vendedor;
    newF.InventarioF = inventario;
    newF.Cantidad = Cant;
    newF.Total = Cant*newF.InventarioF.Precio;
    factura[cont] = newF;
}

int main(){
    system("cls");


    Vendedor vendedores[2];
    Inventario inventarios[3];
    Factura facturas[2];

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
    
    int cont = 0;
    GeneraFactura(cont, facturas,vendedores[1],inventarios[2],14);

    for(int i=0;i<cont+1;i++){
        Factura current = facturas[i];
        cout<<"=Factura #"<<current.NoFactura<<endl;
        cout<<"\tVendedor: "<<current.VendedorF.Nombre<<" ("<<current.VendedorF.Cve_Vendedor<<")"<<endl;
        cout<<"\tArticulo: "<<current.InventarioF.Descripcion<<" ("<<current.InventarioF.Cve_Articulo<<")"<<endl;
        cout<<"\tCantidad: "<<current.Cantidad<<endl;
        cout<<"\tTotal:    $"<<current.Total<<endl;
    }
    
    return 0;
}