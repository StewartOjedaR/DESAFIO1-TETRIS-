#include "FuncionesTetris.h"
#include <iostream>
void InsertFigura(unsigned short* pFigura, unsigned char* pTablero,int Ancho, int Alto,int PosInicial);
void CambiaBit(int);
using namespace std;
int main(){
int Ancho=24;
int Alto=24;
short Grado=90;
short *pGrados=&Grado;
unsigned short posicion=1;
unsigned short Figura=Figuras(posicion);
unsigned short *pFigura=&Figura;
//cout<<*pFigura<<'\n';
//RotarFigura(posicion,pFigura,pGrados);
//cout<<*pFigura<<'\n';
///ImpFig(pFigura);
///Bin(*pFigura);
unsigned char *pTablero=CrearTablero(Ancho,Alto);
//Bin1(pTablero[0]);
//Bin1(pTablero[1]);
//Bin1((pTablero[2]));
MostrarTablero(Ancho , Alto , pTablero);
int PosInicial=10;
int PosElemento=PosInicial/8;
int BitFigura=15;
int cont=0;
for (int bit=0; bit<Alto*Ancho;bit++){
    if (PosInicial<=bit&PosInicial+(4*Ancho)>=bit){
        
        for(BitFigura; BitFigura>=0;){cont++;
           if ((*pFigura>>BitFigura)&1){
               Bin1(pTablero[PosElemento]);
               pTablero[PosElemento]=pTablero[PosElemento]|(1ULL<<bit%8);
               Bin1(pTablero[PosElemento]);
           }
        if (cont%4==0){PosElemento=PosElemento+(((Ancho*Alto)/8)/Alto);bit=(bit+Ancho)-4;}
        BitFigura--;break;
        }

    }
}







MostrarTablero(Ancho , Alto , pTablero);
delete[] pTablero;//libero memoria



return 0;
}

/*void MostrarTablero(int Ancho, int Alto, unsigned char *tablero){//pido alto, ancho y la direccion del arregli
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

*/




void InsertFigura(unsigned short* pFigura,unsigned char* pTablero,int Ancho, int Alto,int PosInicial){
int conta=0;
MostrarTablero(Ancho,Alto,pTablero);
int elemento=PosInicial/8;
cout<<pTablero[elemento];
for (int i=15;i>=0;i--){
conta++;
   if ((*pFigura>>i)&1){
        cout<<pTablero[elemento]<<std::endl;
        pTablero[elemento]=pTablero[elemento]|(1ULL<<conta);
}else{}
if (conta%4==0){cout<<endl;elemento+=3;if (conta%8==0){}}
}
}

