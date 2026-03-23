#include "FuncionesTetris.h"
#include <iostream>
unsigned short Tetros[7]={0x0f00,0x0660,0x0072,0x0036,0x0063,0x0226,0x0223};
using namespace std;
int Ancho=24, Alto=24; char Entrada; short Grado=0,Puntuacion=0;bool colision=false;
bool*pColision=&colision;bool Fijar=false;bool*pFijar=&Fijar;
int PosInicial=5; int *pPosInicial=&PosInicial; short *pGrados=&Grado; short*pPuntuacion=&Puntuacion;
 
int main(){
unsigned short PosicionFicha=2;
unsigned short *pPosicionFicha=&PosicionFicha;
unsigned short Figura=Figuras(PosicionFicha);unsigned short *pFigura=&Figura;
    Mensaje();
 //   cin>>Alto;
   // cout<<"Ingrese el ancho: ";cin>>Ancho;
    unsigned char *pTablero=CrearTablero(Ancho,Alto);
    unsigned char *pTableroCopia=CrearTablero(Ancho,Alto);
    unsigned char *pMaskTablero=MascaraTablero(Ancho,Alto);
    MostrarTablero(Ancho,Alto,pTablero,pPuntuacion);
    cout<<"\nPRESIONE CUALQUIER TECLA PARA INICIAR";
    bool SalirDelJuego;
    cin>>Entrada;
    SalirDelJuego=true;
    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
    InsertFig(pFigura,Alto,Ancho,PosInicial,pTableroCopia,pMaskTablero);
MostrarTablero(Ancho,Alto,pMaskTablero,pPuntuacion);
 MostrarTablero(Ancho,Alto,pTableroCopia,pPuntuacion);
 MostrarTablero(Ancho,Alto,pTablero,pPuntuacion);
    do
    {
        MostrarTablero(Ancho,Alto,pTableroCopia,pPuntuacion);
        BorrarFigTablero(pFigura,Alto,Ancho,pTablero,pMaskTablero);
        BorrarFigTablero(pFigura,Alto,Ancho,pTableroCopia,pMaskTablero);
        cin>>Entrada;

        switch (Entrada){

        case 'a':
            InsertFigMaskIzq(pFigura,Alto,Ancho,PosInicial,pMaskTablero);
            if (Colision(Alto,Ancho,pTableroCopia,pMaskTablero)){
                BorrarMaskFig(pFigura,Ancho,Alto,pMaskTablero);
                InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                break;
            }
            BorrarMaskFig(pFigura,Ancho,Alto,pMaskTablero);
            InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
            BorrarMovIzqFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);
            InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
            CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
            break;

        case 's':
                if (Limite(Alto,Ancho,pMaskTablero)){
                    BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                    BorrarFigYMask(pFigura,Alto,Ancho,pTablero, pMaskTablero);
                    *pPosicionFicha+=1;
cout<<PosicionFicha;
                    if (*pPosicionFicha>=7){
                        *pPosicionFicha=0;}
                    ;
                    PosInicial=5;
                    Figura=Figuras(PosicionFicha);
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                        break;
                }
            BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
            InsertFigMaskAbajo(pFigura,Alto,Ancho,PosInicial,pMaskTablero);
            if (Colision(Alto,Ancho,pTableroCopia,pMaskTablero)){
                    BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                    BorrarFigYMask(pFigura,Alto,Ancho,pTablero, pMaskTablero);
                    *pPosicionFicha+=2; 
                    if (*pPosicionFicha>=7){
                        *pPosicionFicha-=7;
                    }
                    Figura=Figuras(PosicionFicha);
                    PosInicial=5;
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);

                    if (FilaCompleta){

cout<<"exito\n";
                    }


                        break;
}

            BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
            BorrarBajarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);
            InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
            CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
            break;

        case 'w':
         //   BorrarFigTablero((pFigura+PosicionFicha),Alto,Ancho,pTableroCopia,pMaskTablero);
            BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
            *pGrados+=90;if (*pGrados>271){*pGrados=0;}
            RotarFigura(*pPosicionFicha,pFigura,pGrados);
            InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
      /*      if (Colision(Alto,Ancho,pTableroCopia,pMaskTablero)){  
                BorrarFigYMask(pFigura,Alto,Ancho,pTablero,pMaskTablero);
               *pGrados-=90;
                RotarFigura(*pPosicionFicha,pFigura,pGrados);
                InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);

            }*/
            CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
            break;

        case 'd':
            InsertFigMaskDer(pFigura,Alto,Ancho,PosInicial,pMaskTablero);
            if (Colision(Alto,Ancho,pTableroCopia,pMaskTablero)){
                BorrarMaskFig(pFigura,Ancho,Alto,pMaskTablero);
                InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                *pColision=false;
                break;
            }
            BorrarMaskFig(pFigura,Ancho,Alto,pMaskTablero);            
            BorrarMovDerFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);
            InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
            CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
            break;

        case 'Q'|'q': SalirDelJuego=false;
            break;

        default:
                  if (Limite(Alto,Ancho,pMaskTablero)){
                    BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                    BorrarFigYMask(pFigura,Alto,Ancho,pTablero, pMaskTablero);
                    *pPosicionFicha+=1; 
                    if (*pPosicionFicha>=7){
                        *pPosicionFicha=0;}
                    PosInicial=5;
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                        break;
                }
            BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
            InsertFigMaskAbajo(pFigura,Alto,Ancho,PosInicial,pMaskTablero);
            if (Colision(Alto,Ancho,pTableroCopia,pMaskTablero)){
                    BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                    BorrarFigYMask(pFigura,Alto,Ancho,pTablero, pMaskTablero);
                    *pPosicionFicha+=2; 
                    if (*pPosicionFicha>=7){
                        *pPosicionFicha-=7;
                    }
                    PosInicial=5;
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);

                    if (FilaCompleta){

cout<<"exito\n";
                    }


                        break;
}

            BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
            BorrarBajarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);
            InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
            CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
            break;
        }
    }while (SalirDelJuego==true);
    delete[] pTablero,pMaskTablero;//libero memoria
    return 0;
}
