#include <iostream>
#include <omp.h>
#include <cstdlib>

#ifdef _WIN32
#define LIMPIAR "cls"
#else
#define LIMPIAR "clear"
#endif

using namespace std;

int array[50];
int tam;
int hilo;
int suma;

//prototipos
void llenarArreglo();
void sumarArreglo();
void mostrarArreglo();
void reiniciar();

//main
int main(){
  int opc;

//#pragma omp parallel for shared(contenido)
  
 do{ 
  cout<<"introduzca el tamanio del arreglo (de entre 10 a 50): ";
  cin>>tam;
 }while(tam<10 || tam>50);
  
  system(LIMPIAR);
  do{
    cout<<"Elija una opción:"<<endl;
    cout<<"0.- Salir\n1.- llenar arreglo\n2.- Sumar arreglo\n"<<
      "3.- Mostrar arreglo\n4.- Reiniciar arreglo"<<endl;
    cin>>opc;
    switch(opc){
      
      case 0:
        cout<<"fin"<<endl;
        break;
      case 1:
        llenarArreglo();
        break;
      case 2:
        sumarArreglo();
        break;
      case 3:
        mostrarArreglo();
        break;
      case 4:
        reiniciar();
        break;

      default:
     
        cout<<"opcion inexistente..."<<endl;
        break;
    }
  
  }while(opc);

  
  return 0;
}

//definición de funciones

void llenarArreglo() {
  
 system(LIMPIAR);
 int num; 

#pragma omp parallel shared (hilo, array, num)
 {
  #pragma omp for schedule(dynamic, 2)
  for (int i=0 ;i<tam;i++){ 

   hilo = omp_get_thread_num(); 
   num = 20 +rand()%(41-20);

    array[i] = num;

  }

}
  cout<<"Arreglo lleno!";

  cin.get();

}


void sumarArreglo(){
  system(LIMPIAR);
  
#pragma omp parallel shared (array)
  {

  #pragma omp for schedule(dynamic, 2)
  for(int i=0; i<tam;i++){
    
    suma +=  array[i];
  
  }
  }
  cout<<"La suma de los elementos del arreglo es: "<<suma<<endl;
  
  cin.get();
}

void mostrarArreglo(){

  system(LIMPIAR);

#pragma omp parallel shared (hilo, array)
  {

  #pragma omp for schedule(dynamic, 2)
  for(int i=0; i<tam; i++){
    
    printf("posicion %d: %d, nucleo: %d \n",i,array[i],omp_get_thread_num()); 
  
  }

  }

  cin.get();
  
}


void reiniciar(){

  system(LIMPIAR);
  
  for(int i = 0; i<tam; i++){
    
    array[i]=0;
  
  }
  cout<<"arreglo reiniciado!"; 
  cin.get();
}
