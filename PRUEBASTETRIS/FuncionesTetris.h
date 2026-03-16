#ifndef FUNCIONESTETRIS_H
#define FUNCIONESTETRIS_H
#include<iostream>
using namespace std;
unsigned char *CrearTablero(int Ancho,  int  Alto){
int valores=(Ancho*Alto)/(sizeof(unsigned char)*8);//Mi arreglo es de tipo unsigned char (8bits), y necesito saber cuanto bits tendra mi tablero, aqui se cuantos 'char' de 8 bits necesto para completar mi tablero
unsigned char* Tablero=new unsigned char[valores]; //Un arreglo dinamico pues el tablero varia dependiendo del jugador
int contador=0;//contador para 'saltos' de  lineas que ubicaran 1 en cada principio y final de linea eso ara una pared para mas adelante las colisiones
for (int i =0 ; i<valores ; i++){//recorro cada elemento de mi arreglo
    for (int j=0; j<(sizeof(unsigned char)*8);j++){//'recorro' las 'posiciones' de los bits
       contador++;
        if (contador==1 || contador%Ancho==0 ||(contador-1)%Ancho==0){//asigno un bit en 1 cada final y principio de linea dependiendo del ancha
          Tablero[i]=Tablero[i]|(1ULL<<j);//al elemento en la posicion i de mi arreglo corro 1bit j veces para asignarlo a esa posicion
        }
        else {
           Tablero[i]=Tablero[i]& ~(1ULL << j);//pone cero en mi tablero
        }
    }
}
return Tablero;
}

void MostrarTablero(int Ancho, int Alto, unsigned char *tablero){//pido alto, ancho y la direccion del arregli
int contador=0;//contador
for (int i=0; i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){//bucle para los elementos
  for (int j=0; j<sizeof(unsigned char)*8;j++){//bucle para los 'bits'
    contador++;//actualizador de contador para saltar
      if (((tablero[i]>>j)&1)==1){//le aplico AND 1 en el bit en la posicion j del elemento i y si es ==1 entonces ese bit esta true e imprime parte de la figura
       cout<<"[]";//reemplazo de bit 1 a parte de la figura a mostrar en consola
      }
     else{
      cout<<". ";//reemplazo de el bit en 0 por un .
    }
    if (contador%Ancho==0){//cada ancho de sea multiplo de contador entonces imprimira el salto
  cout<<endl;
  }
  }
}}
#endif // FUNCIONESTETRIS_H

