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
    unsigned char *pTableroPermanente=CrearTablero(Ancho,Alto);
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

        case 'a':
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

        case 's':
            if (PosInicial+Ancho>(Ancho*Alto)-(Ancho*4)){
                BorrarMaskFig(pFigura,Ancho,Alto,pMaskTablero);
                InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                *pColision=0;
                *pColision=0;BorrarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero);
                InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                *pPosInicial=5;*pFigura=+1;
                if(*pFigura>8){*pFigura=0;}
                break;
            }
            MostrarTablero(Ancho,Alto,pTablero,pPuntuacion);
            BorrarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero);
            InsertFigMaskAbajo(pFigura,Alto,Ancho,PosInicial,pMaskTablero,pFijar,pColision);
            if (*pFijar==true){
                *pColision=false;BorrarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero);
                InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
                *pPosInicial=5;*pFigura=+1;if(*pFigura>8){*pFigura=0;}

            }

            BorrarMaskFig(pFigura,Alto,Ancho,pMaskTablero);
            BorrarBajarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);

            InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
            break;

        case 'w':
            BorrarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero);
            RotarFigura(PosicionFicha,pFigura,pGrados);
            InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
            break;

        case 'd':
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
            InsertFigMaskAbajo(pFigura,Alto,Ancho,PosInicial,pMaskTablero,pFijar,pColision);
            if (Colision(Alto,Ancho,pTablero,pMaskTablero,pColision)){*pColision=0;
            }
            BorrarBajarFig(pFigura,Alto,Ancho,pTablero,pMaskTablero,pPosInicial);

            InsertFig(pFigura,Alto,Ancho,PosInicial,pTablero,pMaskTablero);
            break;
        }
    }while (SalirDelJuego==true);
    delete[] pTablero,pMaskTablero;//libero memoria
    return 0;
}
