#include "FuncionesTetris.h"
#include <iostream>

using namespace std; 

int main(){
int Ancho=48;
int Alto=24;
unsigned char *tablero=CrearTablero(Ancho,Alto);
MostrarTablero(Ancho , Alto , tablero);

delete[] tablero;//libero memoria 
return 0;
}

