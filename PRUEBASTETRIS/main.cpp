#include "FuncionesTetris.h"
#include <iostream>

using namespace std;
int Ancho, Alto; char Entrada; short Grado=0,Puntuacion=0;bool colision=false;
bool*pColision=&colision;bool Fijar=false;bool*pFijar=&Fijar;
int PosInicial=5; int *pPosInicial=&PosInicial; short *pGrados=&Grado; short*pPuntuacion=&Puntuacion;
unsigned short PosicionFicha=0; unsigned short Figura=Figuras(PosicionFicha);unsigned short *pFigura=&Figura; unsigned short *pPosicionFicha=&Figura;
int main(){
   Mensaje();
   cin>>Alto;
   cout<<"Ingrese el ancho: ";cin>>Ancho;
   unsigned char *pTablero=CrearTablero(Ancho,Alto);
   unsigned char *pMaskTablero=MascaraTablero(Ancho,Alto);
   MostrarTablero(Ancho,Alto,pTablero,pPuntuacion);
   cout<<"\nPRESIONE CUALQUIER TECLA PARA INICIAR";
   bool SalirDelJuego;
   cin>>Entrada;
   SalirDelJuego=true;
   InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
do
{
   MostrarTablero(Ancho,Alto,pTablero,pPuntuacion);
   cin>>Entrada;
   switch (Entrada){
    
case 'A'|'a':
       BorrarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero);
       InsertFigMaskIzq(pFigura,Alto,Ancho,PosInicial,pMaskTablero);
       cout<<ColisionLateralIzq(Alto,Ancho,pTablero,pMaskTablero,pColision);cout<<endl;
        if (ColisionLateralIzq(Alto,Ancho,pTablero,pMaskTablero,pColision)){
           BorrarMaskFig(pFigura,Ancho,Alto,pMaskTablero);
           InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);*pColision=false;
           break;
        }
        BorrarMaskFig(pFigura,Ancho,Alto,pMaskTablero);
        InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
        BorrarMovIzqFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);
        InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
        break;

    case 's'|'S':
        MostrarTablero(Ancho,Alto,pTablero,pPuntuacion);
        BorrarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero);
MostrarTablero(Ancho,Alto,pTablero,pPuntuacion);
        InsertFigMaskAbajo(pFigura,Alto,Ancho,PosInicial,pMaskTablero,pFijar,pColision,pTablero);
           if (*pFijar==true){
            pColision=false;BorrarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero);
            InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
            *pPosInicial=5;*pFigura=+1;if(*pFigura>8){*pFigura=0;}
            
            }



MostrarTablero(Ancho,Alto,pTablero,pPuntuacion);
cout<<Colision(Alto,Ancho,pTablero,pMaskTablero,pColision);
        if (Colision(Alto,Ancho,pTablero,pMaskTablero,pColision))
        BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
        BorrarBajarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);
        
        InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
        break;
    
    case 'W'|'w':
        BorrarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero);
        RotarFigura(PosicionFicha,pFigura,pGrados);
        InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
         break;

    case 'D'|'d':
        BorrarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero);
        InsertFigMaskDer(pFigura,Alto,Ancho,PosInicial,pMaskTablero);
           if (  Colision(Alto,Ancho,pTablero,pMaskTablero,pColision)){
                BorrarMaskFig(pFigura,Ancho,Alto,pMaskTablero);
                InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                *pColision=false;
            break;
        }
        BorrarMovDerFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);
        InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
        break;

    case 'Q'|'q': SalirDelJuego=false;
        break;
   
    default:
        BorrarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero);
        InsertFigMaskAbajo(pFigura,Alto,Ancho,PosInicial,pMaskTablero,pFijar,pColision,pTablero);
        if (Colision(Alto,Ancho,pTablero,pMaskTablero,pColision)){;pColision=false;
}
        BorrarBajarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);
        
        InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
        break;
    }
}while (SalirDelJuego==true);
delete[] pTablero,pMaskTablero;//libero memoria
return 0;
}