#ifndef FUNCIONESTETRIS_H
#define FUNCIONESTETRIS_H
#include<iostream>
using namespace std;
unsigned char *CrearTablero(int Ancho,  int  Alto){
int valores=(Ancho*Alto)/(sizeof(unsigned char)*8);//Mi arreglo es de tipo unsigned char (8bits), y necesito saber cuanto bits tendra mi tablero, aqui se cuantos 'char' de 8 bits necesto para completar mi tablero
unsigned char* Tablero=new unsigned char[valores]; //Un arreglo dinamico pues el tablero varia dependiendo del jugador
int contador=0;//contador para 'saltos' de  lineas que ubicaran 1 en cada principio y final de linea eso ara una pared para mas adelante las colisiones
for (int i =0 ; i<valores ; i++){//recorro cada elemento de mi arreglo
    for (int j=(sizeof(unsigned char)*8)-1; j>=0;j--){//'recorro' las 'posiciones' de los bits
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
int cont2=0;
for (int i=0; i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){//bucle para los elementos
  for (int j=(sizeof(unsigned char)*8)-1; j>=0;j--){//bucle para los 'bits'
    contador++;//actualizador de contador para saltar
      if (((tablero[i]>>j)&1)==1){//le aplico AND 1 en el bit en la posicion j del elemento i y si es ==1 entonces ese bit esta true e imprime parte de la figura
       cout<<cont2<<".";//reemplazo de bit 1 a parte de la figura a mostrar en consola
       cont2++;
      }
     else{
      cout<<cont2<<" ";//reemplazo de el bit en 0 por un .
      cont2++;
    }
    if (contador%Ancho==0){//cada ancho de sea multiplo de contador entonces imprimira el salto
  cout<<endl;
  }
  }
}}


unsigned short Figuras(unsigned short numero){
unsigned short Tetros[7]={0x0f00,0x0660,0x0072,0x0036,0x0063,0x0226,0x0223};
return Tetros[numero];
}



void RotarFigura(unsigned short posicion ,unsigned short *pFiguras, short *Grados){
//0x0f00,0x0660,0x0072,0x0036,0x0063,0x0226,0x0223,
switch (posicion){
    case 0://0x0f00
        switch (*Grados){
           case 0:
                *pFiguras^=0x2d22;//*pFiguras=0x0f00-> 0000 1111 0000 0000
                break;                     //0x22D2-->0010 1101 0010 0010
           case 90:
                *pFiguras^=0x2d22;//*pFiguras=0x0f00-> 0000 1111 0000 0000
                break;
           case 180:
                *pFiguras^=0x2d22;//*pFiguras=0x0f00-> 0000 1111 0000 0000
                break;
           case 270:
                *pFiguras^=0x2d22;//*pFiguras=0x0f00-> 0000 1111 0000 0000
                break;        
            }                                     
    break;
    case 1://0x0660
        switch(*Grados){
            case 0||90||180||270:
                 *pFiguras;
                 break;
        }
    break;
    case 2:
        switch (*Grados){
            case 0://0x0072
                if (*pFiguras==0x0232){//  0000 0010 0011 0010
                 *pFiguras^=0x0240;//XOR 0000 0010 0100 0000
                }                     //   0000 0000 0111 0010

                else{*pFiguras^=0x0210;// 0X0262-> 0000 0010 0110 0010
                }              //   XOR   0X0210-> 0000 0010 0001 0000
            break;//                               0000 0000 0111 0010
            case 90:
                if (*pFiguras==0x0072){
                   *pFiguras^=0x0210; 
                }
                else{*pFiguras^=0x0012;
                }
            break;
            case 180:
                if (*pFiguras==0x0262){//0000 0010 0110 0010
                    *pFiguras^=0x0012;// 0000 0000 0001 0010
                }                     // 0000 0010 0111 0000
                else{*pFiguras^=0x0042;
                }
            break;
            case 270:
                if (*pFiguras==0x0270){
                   *pFiguras^=0x0042; 
                }
                else{*pFiguras^=0x0240;
                }
            break;
        }
    break;//0x0f00,0x0660,0x0072,0x0036,0x0063,0x0226,0x0223,
    case 3://0x0036
        switch(*Grados){
            case 0:
                *pFiguras^=0x0454;
                    break;
            case 90:
                *pFiguras^=0x0454;
                    break;
            case 180:
                *pFiguras^=0x0454;
                    break;
            case 270:
                *pFiguras^=0x0454;
                    break;
        }  
    break;   
    case 4://0x0063///0000 0000 0110 0011
        switch(*Grados){
            case 0:               //0000 0000 0110 0011
                *pFiguras^=0x0151;//0000 0001 0101 0001
                    break;//        0000 0001 0011 0010
            case 90:
                *pFiguras^=0x0151;
                    break;
            case 180:
                *pFiguras^=0x0151;
                    break;
            case 270:
                *pFiguras^=0x0151;
                    break;
        }  
    break;    
    case 5://0x0226//0000 0010 0010 0110
        switch (*Grados){
            case 0://0x0226//00010 0010 0110
                if (*pFiguras==0x0047){//0000 0000 0100 0111
                    *pFiguras^=0x0261; //   0000 0010 0110 0001
                }//                      0000 0010 0010 0110
                else {*pFiguras^=0x0257;//0x0071// 0000 0000 0111 0001
                }//                      0x0261//  0000 0010 0101 0111
            break;
            case 90://0x0047
                if (*pFiguras==0x0226){//0000 0010 0010 0110
                    *pFiguras^=0x0261; //0000 0010 0110 0001
                }
                else{*pFiguras^=0x0365;
                }
            break;
            case 180://0x0322//0000 0011 0010 0010
                if (*pFiguras==0x0047){//0000 0000 0100 0111
                    *pFiguras^=0x0365; //0000 0011 0110 0101
                }
                else{*pFiguras^=0x0353;//0x0071// 0000 0000 0111 0001
                }                      //0x0353// 0000 0011 0101 0011
                                              //  0000 0011 0010 0010
            break;
            case 270://0x0071//0000 0000 0111 0001
                if (*pFiguras==0x0322){//0000 0011 0010 0010
                    *pFiguras^=0x0353; //0000 0011 0101 0011
                }//                      0000 0000 0111 0001
                else{*pFiguras^=0x0257;//0x0226//0000 0010 0010 0110
                }//                    //0x0257  0000 0010 0101 0111
            break;                      ///      0000 0000 0111 0001
        }
    break;
    case 6://0x0223
        switch (*Grados){
            case 0:
                if (*pFiguras==0x0017){
                   *pFiguras^=0x0234; 
                }
                else{*pFiguras^=0x0257;
                }
            break;
            case 90:
                if (*pFiguras==0x0223){
                    *pFiguras^=0x0257; 
                }
                else{*pFiguras^=0x0656;
                }
            break;
            case 180:
                if (*pFiguras==0x0074){
                    *pFiguras^=0x0656; 
                }
                else{*pFiguras^=0x0635;
                }
            break;
            case 270:
                if (*pFiguras==0x0622){
                    *pFiguras^=0x0635; 
                }
                else{*pFiguras^=0x0234;
                }
            break;
        }
    break;
    default:
        break;
}
}

void Bin1(unsigned char a){
for (int i=(sizeof(a)*8)-1;i>=0;i--){
    if ((a>>i)&1==1){
       cout<<'1';
    }else{ 
      cout<<'0';
    } if (i%4==0){cout<<' ';
}}
}

void Bin(unsigned short a){
for (int i=(sizeof(a)*8)-1;i>=0;i--){
    if ((a>>i)&1==1){
       cout<<'1';
    }else{ 
      cout<<'0';
    } if (i%4==0){cout<<' ';
}}
}



void ImpFig(unsigned short *pFiguras){
int conta=0;
for (int i=15;i>=0;i--){
conta++;
   if ((*pFiguras>>i)&1){
cout<<"[]";
}else{cout<<" .";}
if (conta==4){cout<<endl;conta=0;}
}
}

void InsertFig(unsigned short*pFigura,int Alto, int Ancho, int PosInicial,unsigned char*pTablero){
int PosElemento=PosInicial/8;
int BitFigura=sizeof(unsigned short)*8;
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
}
#endif // FUNCIONESTETRIS_H

