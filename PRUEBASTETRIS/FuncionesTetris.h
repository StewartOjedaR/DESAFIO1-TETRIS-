#ifndef FUNCIONESTETRIS_H
#define FUNCIONESTETRIS_H
#include<iostream>
using namespace std;
/*Crea un arreglo de char (8bits) dinamico en el heap deltamaño que ingrese el usuario*/
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
/*Muestra en pantalla los bits que contenga en arreglo anteriormente creado*/

void MostrarTablero(int Ancho, int Alto, unsigned char *tablero,short *Puntuacion){//pido alto, ancho y la direccion del arregli
int contador=0;//contador
int cont2=0;
for (int i=0; i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){//bucle para los elementos
  for (int j=(sizeof(unsigned char)*8)-1; j>=0;j--){//bucle para los 'bits'
    contador++;//actualizador de contador para saltar
      if (((tablero[i]>>j)&1)==1){//le aplico AND 1 en el bit en la posicion j del elemento i y si es ==1 entonces ese bit esta true e imprime parte de la figura
       cout<<'['<<']';//reemplazo de bit 1 a parte de la figura a mostrar en consola
      cont2++;
      }
     else{
      cout<<'.'<<' ';//reemplazo de el bit en 0 por un .
     cont2++;
    }
    if (contador%Ancho==0){//cada ancho de sea multiplo de contador entonces imprimira el salto
  cout<<endl;
  }
  }
}
cout<<"ACCIONES:[A]Izq  [D]Der  [B]Bajar  [W]Rotar [Q]Salir";
cout<<"\nPuntuacion: "<<*Puntuacion<<"00\n";
}


unsigned short Figuras(unsigned short numero){
unsigned short Tetros[7]={0x0f00,0x0660,0x0072,0x0036,0x0063,0x0226,0x0223};
return Tetros[numero];
}


/*Rota la figura en el un arreglo anteriormente creado, usando punteros puedo cambiar las figuras
previamente creadas con un tipo de dato de 16bits, en este caso, unsigned short(unsigned para utilizar todos los bits)*/

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


/*Imprime una figura 4*4, originalmente se creo con el animo de para mostras la siguiente figura*/
void ImpFig(unsigned short &pFiguras){
int conta=0;
for (int i=15;i>=0;i--){
conta++;
   if ((pFiguras>>i)&1){
cout<<"[]";
}else{cout<<" .";}
if (conta==4){cout<<endl;conta=0;}
}
}

/* Mascara de bits hecha de arreglos como el tablero original salvo que esto es para aplicarle operadores
a nivel bit con el animo de manipular la el juego, tiene diferencias a la hora de respuesta,
mientras una me crea un tablero con sus 'paredes',esta me crea un arreglo completamente en blanco*/
unsigned char *MascaraTablero(int Ancho,  int  Alto){
int valores=(Ancho*Alto)/(sizeof(unsigned char)*8);//Mi arreglo es de tipo unsigned char (8bits), y necesito saber cuanto bits tendra mi tablero, aqui se cuantos 'char' de 8 bits necesto para completar mi tablero
unsigned char* Tablero=new unsigned char[valores]; //Un arreglo dinamico pues el tablero varia dependiendo del jugador
int contador=0;//contador para 'saltos' de  lineas que ubicaran 1 en cada principio y final de linea eso ara una pared para mas adelante las colisiones
for (int i =0 ; i<valores ; i++){//recorro cada elemento de mi arreglo
    for (int j=(sizeof(unsigned char)*8)-1; j>=0;j--){//'recorro' las 'posiciones' de los bits
       contador++;
        if (contador==1 || contador%Ancho==0 ||(contador-1)%Ancho==0){//asigno un bit en 1 cada final y principio de linea dependiendo del ancha
          Tablero[i]=Tablero[i]& ~(1ULL << j);//al elemento en la posicion i de mi arreglo corro 1bit j veces para asignarlo a esa posicion
        }
        else {
           Tablero[i]=Tablero[i]& ~(1ULL << j);//pone cero en mi tablero
        }
    }
}
return Tablero;
}


/*Inserta la figura en el tablero*/
void InsertFig(unsigned short *pFigura,int Alto, int Ancho, int PosInicial,unsigned char*pTablero,unsigned char*pMaskTablero){
int BitFigura=(sizeof(unsigned short)*8)-1;
int cont=0;
for (int bit=0; bit<Alto*Ancho;bit++){
    if (PosInicial<=bit&PosInicial+(4*Ancho)>=bit){   
        for(BitFigura; BitFigura>=0;){cont++;
            if ((*pFigura>>BitFigura)&1){
              pTablero[(bit)/8]=pTablero[(bit)/8]|(1ULL<<(8-((bit)%8))-1);
              pMaskTablero[(bit)/8]=pMaskTablero[(bit)/8]|(1ULL<<(8-((bit)%8))-1);
            }
            if (cont%4==0){bit=(bit+Ancho)-4;}
              BitFigura--;break;
        }
    }
if (bit>1+(PosInicial+(4*Ancho))){break;}
}

}

/*A falta de tiempo cree "funciones de control rapido", para manipular el tablero y 
las fichas, son pequeñas pero cumplen su pequeña funcion*/
/*Borra la figura para dejar paso a la siguiente, algo como actualizador de fotogramas que baja el indice de la 
posicion original */
void BorrarBajarFig(unsigned short*pFigura,int Alto, int Ancho,
unsigned char*pTablero,unsigned char*MaskTablero,int *pPosInicial){

for (int i=0;i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){
   pTablero[i]= pTablero[i]^MaskTablero[i];
}
for (int i=0;i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){
MaskTablero[i]=MaskTablero[i]^MaskTablero[i];
}*pPosInicial+=Ancho;
}
/*Borra y desplaza la posicion original para moverla a la izquierda*/
void BorrarMovIzqFig(unsigned short*pFigura,int Alto, int Ancho,
unsigned char*pTablero,unsigned char*MaskTablero,int *pPosInicial){

for (int i=0;i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){
   pTablero[i]= pTablero[i]^MaskTablero[i];
}
for (int i=0;i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){
MaskTablero[i]=MaskTablero[i]^MaskTablero[i];
}*pPosInicial-=1;
}

/*Borra y deplaza a la derecha*/
void BorrarMovDerFig(unsigned short*pFigura,int Alto, int Ancho,
unsigned char*pTablero,unsigned char*MaskTablero,int *pPosInicial){

for (int i=0;i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){
   pTablero[i]= pTablero[i]^MaskTablero[i];
}
for (int i=0;i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){
MaskTablero[i]=MaskTablero[i]^MaskTablero[i];
}*pPosInicial+=1;
}
/*borra la figura del rablero y de la mascara,util para actualizar
*/
void BorrarFigTablero(unsigned short*pFigura,int Alto, int Ancho,
unsigned char*pTablero,unsigned char*MaskTablero){

for (int i=0;i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){
   pTablero[i]= pTablero[i]^MaskTablero[i];
}
//for (int i=0;i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){
//MaskTablero[i]=MaskTablero[i]^MaskTablero[i];
//}
}



void BorrarFigYMask(unsigned short*pFigura,int Alto, int Ancho,
unsigned char*pTablero,unsigned char*MaskTablero){

for (int i=0;i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){
   pTablero[i]= pTablero[i]^MaskTablero[i];
}
for (int i=0;i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){
MaskTablero[i]=MaskTablero[i]^MaskTablero[i];
}
}


/*inserta figura en la mascara para despues verificar colisiones*/
void InsertFigMaskIzq(unsigned short*pFigura,int Alto, int Ancho, int PosInicial,unsigned char*pMaskTablero){
int BitFigura=(sizeof(unsigned short)*8)-1;
PosInicial-=1;
int cont=0;
for (int bit=0; bit<Alto*Ancho;bit++){
    if (PosInicial<=bit&PosInicial+(4*Ancho)>=bit){   
        for(BitFigura; BitFigura>=0;){cont++;
            if ((*pFigura>>BitFigura)&1){
              pMaskTablero[(bit)/8]=pMaskTablero[(bit)/8]|(1ULL<<(8-((bit)%8))-1);
            }
            if (cont%4==0){bit=(bit+Ancho)-4;}
              BitFigura--;break;
        }
    }
if (bit>1+(PosInicial+(4*Ancho))){break;}
}

}
/*inserta figura en la mascara para despues verificar colisiones*/
void InsertFigMaskDer(unsigned short*pFigura,int Alto, int Ancho, int PosInicial,unsigned char*pMaskTablero){
int BitFigura=(sizeof(unsigned short)*8)-1;
PosInicial+=1;
int cont=0;
for (int bit=0; bit<Alto*Ancho;bit++){
    if (PosInicial<=bit&PosInicial+(4*Ancho)>=bit){   
        for(BitFigura; BitFigura>=0;){cont++;
            if ((*pFigura>>BitFigura)&1){
              pMaskTablero[(bit)/8]=pMaskTablero[(bit)/8]|(1ULL<<(8-((bit)%8))-1);
            }
            if (cont%4==0){bit=(bit+Ancho)-4;}
              BitFigura--;break;
        }
    }
if (bit>1+(PosInicial+(4*Ancho))){break;}
}

}

void InsertFigMask(unsigned short*pFigura,int Alto, int Ancho, int PosInicial,unsigned char*pMaskTablero){
int BitFigura=(sizeof(unsigned short)*8)-1;
int cont=0;
for (int bit=0; bit<Alto*Ancho;bit++){
    if (PosInicial<=bit&PosInicial+(4*Ancho)>=bit){   
        for(BitFigura; BitFigura>=0;){cont++;
            if ((*pFigura>>BitFigura)&1){
              pMaskTablero[(bit)/8]=pMaskTablero[(bit)/8]|(1ULL<<(8-((bit)%8))-1);
            }
            if (cont%4==0){bit=(bit+Ancho)-4;}
              BitFigura--;break;
        }
    }
if (bit>1+(PosInicial+(4*Ancho))){break;}
}

}



/*Se utiliza para colisiones(funcional pero no se usa), preferi otra funcion que verifique bit a bit las colisiones*/

bool ColisionLateralIzq(int Alto, int Ancho,unsigned char* pTablero, unsigned char* pMaskTablero, bool* pColision) {
*pColision = false;
char ContadorBits=0;
int ContadorBytes=0;
unsigned char MaskByte=0x0000;
int total_bytes = (Ancho * Alto) / (sizeof(unsigned char) * 8);
for (int i = 0; i < total_bytes; i++) {
    if (pMaskTablero[i]==0b00000000||pTablero[i]==0b00000000){
        ContadorBytes++; if (ContadorBytes==Ancho/8){ContadorBytes=0;};continue;
    }
    for (int j=7;j>=0;j--){
        if (pMaskTablero[i]&1<<j){
                MaskByte|=1<<j;
                if (ContadorBytes==0){
                    MaskByte=(MaskByte|0b10000000);
Bin1(MaskByte);cout<<' ';Bin1(pTablero[i]);cout<<'\n';;break;
                }
                if (ContadorBytes==(Ancho/8)){
                 MaskByte=(MaskByte|0b00000001);ContadorBytes=0;
Bin1(MaskByte);cout<<' ';Bin1(pTablero[i]);cout<<'\n';break;
                }
        }
    }
Bin1(MaskByte);cout<<'x';Bin1(pTablero[i]);cout<<'\n';
if((MaskByte^pTablero[i])==0){
    if (MaskByte==0b10000000 &&pTablero[i]==0b10000000){
    *pColision=true; return *pColision; break;
    } 
    *pColision=true; return *pColision;
}

if (*pColision==true){break;}
}
   return *pColision;
}

/*Originalmente para recuperar una mascara previamente borrada*/

void RecuperarMaskFig(unsigned short*pFigura,int Alto, int Ancho, int PosInicial,unsigned char*pMaskTablero){
int BitFigura=(sizeof(unsigned short)*8)-1;
int cont=0;
for (int bit=0; bit<Alto*Ancho;bit++){
    if (PosInicial<=bit&PosInicial+(4*Ancho)>=bit){   
        for(BitFigura; BitFigura>=0;){cont++;
            if ((*pFigura>>BitFigura)&1){
              pMaskTablero[(bit)/8]=pMaskTablero[(bit)/8]|(1ULL<<(8-((bit)%8))-1);
            }
            if (cont%4==0){bit=(bit+Ancho)-4;}
              BitFigura--;break;
        }
    }
if (bit>1+(PosInicial+(4*Ancho))){break;}
}

}

/*inseta la figura de la mascara abajo para checar colisiones*/
void InsertFigMaskAbajo(unsigned short*pFigura,int Alto, int Ancho, int PosInicial,unsigned char*pMaskTablero){
int BitFigura=(sizeof(unsigned short)*8)-1;
int cont=0;
PosInicial+=Ancho;
for (int bit=0; bit<Alto*Ancho;bit++){
    if (PosInicial<=bit&PosInicial+(4*Ancho)>=bit){   
        for(BitFigura; BitFigura>=0;){cont++;
            if ((*pFigura>>BitFigura)&1){
              pMaskTablero[(bit)/8]=pMaskTablero[(bit)/8]|(1ULL<<(8-((bit)%8))-1);
            }
            if (cont%4==0){bit=(bit+Ancho)-4;}
              BitFigura--;break;
        }
    }
if (bit>1+(PosInicial+(4*Ancho))){break;}
}
}
/*Borra la mascara y lo deja en blanco*/

void BorrarMaskFig(unsigned short*pFigura,int Alto, int Ancho,
unsigned char*MaskTablero){
for (int i=0;i<(Ancho*Alto)/(sizeof(unsigned char)*8);i++){
MaskTablero[i]=MaskTablero[i]^MaskTablero[i];
}
}

/*Funcion que no se usara aunque funciona */
bool ColisionLateralDer(int Alto, int Ancho,unsigned char* pTablero, unsigned char* pMaskTablero, bool* pColision) {
*pColision = false;
char ContadorBits=0;
int ContadorBytes=0;
unsigned char MaskByte=0x0000;
int total_bytes = (Ancho * Alto) / (sizeof(unsigned char) * 8);
for (int i = 0; i < total_bytes; i++) {
    if (pMaskTablero[i]==0b00000000||pTablero[i]==0b00000000){
        ContadorBytes++; if (ContadorBytes==Ancho/8){ContadorBytes=0;};continue;
    }
    for (int j=0;j<=7;j++){
        if ((pMaskTablero[i]&1<<j)){if (MaskByte=!0){break;}
                MaskByte=0b00000000;
                MaskByte|=1<<j;
                if (ContadorBytes==0){
                    MaskByte=(MaskByte|0b00000000);
                }
                if (ContadorBytes==(Ancho/8)){
                 MaskByte=(MaskByte|0b00000000);ContadorBytes=0;
                }
            
        }

    }
if((MaskByte&pTablero[i])!=0){
    if (((MaskByte&1<<0)) || ((pMaskTablero[i]&1<<0))){
    *pColision=true; return *pColision; break;
    } 
    *pColision=true; return *pColision;
}

if (*pColision==true){break;}
}
   return *pColision;
}

/*Compara bit a bit el arreglo , si algun bit coincide ¡Colision!*/
bool Colision(int Alto, int Ancho,unsigned char* pTablero, unsigned char* pMaskTablero){
bool MaskBitFig; bool MaskBitTab;
            for (int j=0;j<((Ancho*Alto)/(sizeof(char)*8))-1;j++){//total de bytes empezando desde el la posicion 0

                  for (int bit=0;bit<=7;bit++){//recorro cada bit del byte
                   MaskBitFig=pMaskTablero[j]&1<<bit;//guardo el bit de la mascara
                   
                   MaskBitTab=pTablero[j]&1<<bit;//guardo el bit del tablero
                      if (MaskBitFig&&MaskBitTab){ 
                           return bool(1);}//si ambos son true,entoces colicion
                  }
        }
return  bool(0);}

bool Limite(int Alto, int Ancho,unsigned char *pMaskTablero){
bool MaskBitFig; bool MaskBitTab;
MaskBitTab=Ancho/sizeof(char)*8;
int ok=((Ancho*Alto)/(sizeof(char)*8))-1, n=(((Ancho*Alto)/(sizeof(char)*8))-1)-(Ancho)/(sizeof(char)*8);
for (int i=((Ancho*Alto)/(sizeof(char)*8))-1; i>(((Ancho*Alto)/(sizeof(char)*8))-1)-(Ancho)/(sizeof(char)*8);i--){
    for (int bit=7;bit>=0;bit--){
        if (pMaskTablero[i]&1<<bit){
         Bin1(pMaskTablero[i]);
            return true;
}
}
}
return false;
}



bool BorrarLinea(int Alto, int Ancho, unsigned char* pMaskTablero){
bool MaskBitFig; bool MaskBitTab;
        for (int i=(((Ancho*Alto)/(sizeof(char)*8))-((((Ancho/sizeof(char)*8))))-1); i<Alto*Ancho;i++){//Empiezo en la "ultima linea" osea los ultimos bytes que hacen una linea,
           
            for (int bit=0;bit<=7;bit++){
                if ((pMaskTablero[i]&1<<bit)){//a 0000 0001<<bit:(si bit=3):0000 0100 y junto pMaskTablero[i]= 0000 0100 y aplico AND eso seria true y seguiria a la siguiente accion
                   return true;
                }
            }
        }
return false;}







void Mensaje(){
cout<<"\tTETRIS by Stewart Ojeda\t\nPara iniciar ingresa el tamano del tablero \t";
cout<<"\nEl tamano del tablero es 8:1 (1Unidad=8Bloques)";
cout<<"\nIngrese la altura: ";
}



bool FilaCompleta(unsigned char* pTableroCopia,int Ancho, int Alto){
char MascaraBits=0b11111111;
int ContadorBytes=0;
int cont=0;
for (int i=0;i<(Ancho*Alto)/(sizeof(char)*8);i++){
    cont++;
    if (cont=Ancho/8){
        ContadorBytes=0;
        cont=0;
    }
    if (pTableroCopia[i]&MascaraBits){
      ContadorBytes++;
      if (ContadorBytes=Ancho/8){return true;}
    }  
}
return false;
}



void EliminarFila(){


}






void *CopiarTablero(int Ancho,int Alto,unsigned char*pTablero,unsigned char*pTableroCopia){
for (int i = 0; i < (Ancho*Alto)/8; i++){
   pTableroCopia[i]=pTableroCopia[i]|pTablero[i];
}
return 0;
}


#endif // FUNCIONESTETRIS_H

