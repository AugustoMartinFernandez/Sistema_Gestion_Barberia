#include <iostream>
using namespace std;
#include "MenuBarberos.h"
#include "Logo.h"
#include "MenuManager.h"
#include "facha.h"


#include "Barbero.h"
#include "BarberoArchivo.h"
#include "ArchivoConfiguracion.h"


void MenuBarbero::InterfazMenuBarbero ()const{
 int opcion;


   do {
        system("cls");
        LogoConstante ();
rlutil::setColor(rlutil::YELLOW);
rlutil::locate(27, 18); cout<< " E s t a s  e n:  M e n u-B a r b e r o s";
rlutil::setColor(rlutil::BLUE);
 rlutil::locate(27, 19);   cout<< "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
 rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 20);    cout<< "บ                                                    บ";
rlutil::setColor(rlutil::RED);
rlutil::locate(27, 21);    cout<< "บ                                                    บ";
rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 22);    cout<< "บ                                                    บ";
 rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 23);    cout<< "บ                                                    บ";
rlutil::setColor(rlutil::RED);
rlutil::locate(27, 24);    cout<< "บ                                                    บ";
rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 25);    cout<< "บ                                                    บ";
rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 26);    cout<< "บ                                                    บ";
rlutil::setColor(rlutil::RED);
rlutil::locate(27, 27);   cout<<  "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";

 rlutil::setColor(rlutil::YELLOW);
rlutil::locate(32, 20);
rlutil::locate(32, 22);
rlutil::locate(32, 24);
//rlutil::locate(32, 26);
 rlutil::locate(32, 20);    cout<<"1- จSos un Barbero nuevo? "<<endl;
  rlutil::locate(32, 22);   cout<<"2- Editar Informacion de Barbero. "<<endl;
  rlutil::locate(32, 24);   cout<<"3- Lista de Barberos. "<<endl;
    //  cout<<"4-  "<<endl;

     rlutil::setColor(rlutil::WHITE);
 rlutil::locate(32, 29);cout<< " Opcion 0 (cero) Para Salir Del Programa..."<<endl;
 rlutil::setColor(rlutil::RED);  rlutil::locate(32, 30); cout<< "Eleccion: #  ";
  rlutil::setColor(rlutil::BLUE);cin>>opcion;
                                   cin.ignore();

switch (opcion){
 case 1:   {   BarberoNuevo();
          break;     }

  case 2: {   EditarInformacion();
           break;   }

  case 3:  {   ListarBarberos();
                break;       }

  case 0: {
            MenuManager volver;
            volver.MenuPrincipal ();
            break;
          }


 default: system ("cls");
     cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
    cout<<" 0 (cero) para volver al menu principal."<<endl;
    cout<<endl<<endl;  system ("pause");
     system ("cls");
}

} while ( opcion != 0);

}





void MenuBarbero::BarberoNuevo()const{
     cout << endl << "--- ALTA DE NUEVO BARBERO ---" << endl;
            Barbero barb;
            cin.ignore();
            barb.cargar();

            ArchivoConfiguracion config;
            int nuevoId = config.getProximoIdBarbero();
            barb.setId(nuevoId);

            BarberoArchivo reg;

            if(reg.cargarBarbero(barb))
            {
                cout << "\n[EXITO] Barbero guardado correctamente con el ID: " << nuevoId << endl;
            }
            else
            {
                cout << "\n[ERROR] No se pudo guardar el barbero en el disco." << endl;
            }
}


void MenuBarbero::EditarInformacion()const{

    int buscarId,pos,cantidad;
            BarberoArchivo reg;
            Barbero barb;

            bool hayBarberoActivo = false;
            cantidad = reg.cantidadRegistros();

            if(cantidad == 0)
            {
                cout << "No hay barberos en el archivo a modificar." <<endl;
                cout << "Por favor, dirijase a la opcion 1 del menu para dar de alta un nuevo barbero." << endl;
            }
            else
            {
                for(int i=0; i<cantidad; i++)
                {
                    Barbero escaneo = reg.leer(i);
                    if(escaneo.getActivo() == true)
                    {
                        hayBarberoActivo = true;
                        break;
                    }
                }
                if(hayBarberoActivo == false)
                {
                    cout << "No hay barberos activos en el sistema para modificar." << endl;
                }
                else
                {
                    cout << "--- MODIFICAR BARBEROS ---" <<endl;
                    cout << "Ingrese el ID del barbero a modificar: "<<endl;
                    cin >> buscarId;

                    while(buscarId <= 0)
                    {
                        cout << "ID Invalido. Intente nuevamente: ";
                        cin >> buscarId;
                    }

                    pos = reg.buscar(buscarId);
                    if(pos >= 0)
                    {
                        barb = reg.leer(pos);
                        if(barb.getActivo()==true)
                        {
                            cout<< "Ficha actual del barbero:" << endl;
                            barb.mostrar();
                            cout<< "Ingrese los nuevos datos:" << endl;
                            cin.ignore();
                            barb.cargar();
                            barb.setId(buscarId);
                            if(reg.modificarBarbero(barb, pos))
                            {
                                cout << "\nBarbero modificado correctamente." << endl;
                            }
                            else
                            {
                                cout << "\nNo se pudo guardar la modificacion en el archivo." << endl;
                            }
                        }
                        else
                        {
                            cout << "\nNo se puede modificar un barbero  dado de baja" <<endl;
                        }
                    }
                    else
                    {
                        cout << "\nEl ID ingresado no existe en el archivo." << endl;
                    }
                }
            }
system("pause");
}
//void MenuBarbero::BorrarInformacion()const{

//}

void MenuBarbero::ListarBarberos ()const {

cout << endl << "--- LISTADO DE BARBEROS ---" << endl;
            BarberoArchivo reg;
            int total = reg.cantidadRegistros();
            bool hayBarberosActivos = false; // ESTA ES NUESTRA BANDERA

            if(total > 0)
            {
                for(int i = 0; i < total; i++)
                {
                    Barbero leidos = reg.leer(i);

                    // Solo mostramos si estแ activo
                    if(leidos.getActivo() == true)
                    {
                        leidos.mostrar();
                        cout << endl << "-------------------------" << endl << endl;
                        hayBarberosActivos = true; // Si encontramos uno, la bandera cambia
                    }
                }

                // Al terminar el ciclo, si la bandera nunca cambio, avisamos
                if(hayBarberosActivos == false)
                {
                    cout << "No hay barberos activos registrados." << endl;
                }
            }
            else
            {
                cout << "El archivo de barberos esta vacio." << endl;
            }

system("pause");
}
