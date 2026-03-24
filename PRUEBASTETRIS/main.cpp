#include "FuncionesTetris.h"
#include <iostream>
using namespace std;
int Ancho=24, Alto=24; char Entrada; short Grado=0,Puntuacion=0;bool colision=false;
bool*pColision=&colision;bool Fijar=false;bool*pFijar=&Fijar;
int PosInicial=5; int *pPosInicial=&PosInicial; short *pGrados=&Grado; short*pPuntuacion=&Puntuacion;
 
int main(){
unsigned short PosicionFicha=5;
unsigned short *pPosicionFicha=&PosicionFicha;
unsigned short Figura=Figuras(PosicionFicha);unsigned short *pFigura=&Figura;
    Mensaje();
    cin>>Alto;
    cout<<"Ingrese el ancho: ";cin>>Ancho;
    unsigned char *pTablero=CrearTablero(Ancho,Alto);//Creo tablero
    unsigned char *pTableroCopia=CrearTablero(Ancho,Alto);//creo copia
    unsigned char *pMaskTablero=MascaraTablero(Ancho,Alto);//un tablero en blanco para usar de mascara
    MostrarTablero(Ancho,Alto,pTablero,pPuntuacion);
    cout<<"\nPRESIONE CUALQUIER TECLA PARA INICIAR";
    bool SalirDelJuego;//bandera de salida
    cin>>Entrada;
    SalirDelJuego=true;//cambia si quieren salir
    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);//inserto la figura en el 
    InsertFig(pFigura,Alto,Ancho,PosInicial,pTableroCopia,pMaskTablero);
    do
    {   system("cls");
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
                InsertFigMask(pFigura,Alto,Ancho,PosInicial,pTableroCopia);
                if (FilaCompleta(pTableroCopia,Ancho,Alto)){
                    EliminarFila(pTableroCopia,Ancho,Alto);
                    BorrarFigYMask(pFigura,Alto,Ancho,pTablero, pMaskTablero);
                    *pPosicionFicha+=2; 
                    if (*pPosicionFicha>=7){
                        *pPosicionFicha-=7;
                    }
                    Figura=Figuras(PosicionFicha);
                    PosInicial=5;
                    *pGrados=0;
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);                                     
                         break;
                    }
                BorrarFigTablero(pFigura,Alto,Ancho,pTableroCopia,pMaskTablero);
                if (Limite(Alto,Ancho,pMaskTablero)){//
                    BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                    BorrarFigYMask(pFigura,Alto,Ancho,pTablero, pMaskTablero);
                    *pPosicionFicha+=1;
                    if (*pPosicionFicha>=7){
                        *pPosicionFicha=0;}
                    ;
                    PosInicial=5;
                    Figura=Figuras(PosicionFicha);
                    *pGrados=0;
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
                    *pGrados=0;
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                        break;
                }
                BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
                BorrarBajarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);
                *pGrados=0;
                InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                     break;

        case 'w':

            BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
            *pGrados=(*pGrados+90)%360;
            RotarFigura(*pPosicionFicha,pFigura,pGrados);
            InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
            if (Colision(Alto,Ancho,pTablero,pMaskTablero)){
                
                
                }
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
                InsertFigMask(pFigura,Alto,Ancho,PosInicial,pTableroCopia);
                if (FilaCompleta(pTableroCopia,Ancho,Alto)){
                    EliminarFila(pTableroCopia,Ancho,Alto);
                    BorrarFigYMask(pFigura,Alto,Ancho,pTablero, pMaskTablero);
                    *pPosicionFicha+=2; 
                    if (*pPosicionFicha>=7){
                        *pPosicionFicha-=7;
                    }
                    Figura=Figuras(PosicionFicha);
                    PosInicial=5;
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);                                     
                         break;
                    }
                BorrarFigTablero(pFigura,Alto,Ancho,pTableroCopia,pMaskTablero);
                if (Limite(Alto,Ancho,pMaskTablero)){//
                    BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
                    InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                    CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                    BorrarFigYMask(pFigura,Alto,Ancho,pTablero, pMaskTablero);
                    *pPosicionFicha+=1;
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
                        break;
                }
                BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
                BorrarBajarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);
                InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
                     break;



            BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
            BorrarBajarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);
            InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
            CopiarTablero(Ancho,Alto,pTablero,pTableroCopia);
            break;
        }
    }while (SalirDelJuego);
    delete[] pTablero,pMaskTablero,pTableroCopia;//libero memoria
    return 0;
}
