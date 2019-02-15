#include "baseexamen1.h"
// definicion de matricez de CNN
float matriz_s1 [60][5];  // datos validos
float matriz_s2[60][5];  // datos validos
float matriz_s3 [60][5];  // datos validos
float matriz_d [90][5]; // datos de desecho
int col=0; // variable de recorrido de col
int fil;  // variable de recorrido de filas
int col_s=0; // variable para matriz s
int fil_s=0;// variable para matriz s
float promedio1,promedio2,promedio3; // variable de promedio 
float sumatoria1=0;
float sumatoria2=0;
float sumatoria3=0;
int etiqueta1=1;
int etiqueta2=1;
int etiqueta3=1;
int i1=0;
int i2=0;
int i3=0;
float dis1;
float dis2;
float dis3;
float distotal;
float dist_mayor=2000;
float label1;
float label2;
float label3;
int ver=1000;
int cont1, cont2,cont3;
int sumaCont;
int a,b,c;

void setup(){
  Serial.begin(9600);
  
for (int f = 0; f < 75; f++) {
      if(matriz[f][4]==1){
        cont1++;
     
        }
      if(matriz[f][4]==2){
        cont2++;       

        }
    if(matriz[f][4]==3){
        cont3++;
        }
   }
   sumaCont= cont1+cont2+cont3;
a=cont1;
b=cont2;
c=cont3;
delay(200);
  
  for(;etiqueta1<4;etiqueta1++){
      for(;col<4;col++){
        for(fil=i1;fil<a*etiqueta1;fil++){
          sumatoria1=sumatoria1+matriz[fil][col];  
        }
     for(;col<4;col++){
        for(fil=i1;fil<b*etiqueta2;fil++){
          sumatoria2=sumatoria2+matriz[fil][col];  
        }
     for(;col<4;col++){
        for(fil=i2;fil<c*etiqueta3;fil++){
          sumatoria3=sumatoria3+matriz[fil][col];  
        }
      promedio1=sumatoria1/a;
      promedio2=sumatoria2/b;
      promedio3=sumatoria3/c;
      
      matriz_s1[etiqueta1-1][col]=promedio1; // almacenar promedios en matriz S
        matriz_s2[etiqueta2-1][col]=promedio2; // almacenar promedios en matriz S
          matriz_s3[etiqueta3-1][col]=promedio3; // almacenar promedios en matriz S
      //Serial.println(promedio);
      sumatoria1=0;     
      sumatoria2=0;     
      sumatoria3=0;
      fil=0;  
    }
    col=0;
    i1=a*etiqueta1;  
    i2=b*etiqueta2; 
    i3=c*etiqueta3;  
 }}} 

 col=0;
 fil=0;
 for(;fil<3;fil++){
  matriz_s1[fil][4]=fil+1;
  matriz_s2[fil][4]=fil+1;
  matriz_s3[fil][4]=fil+1;
  } //lenar etiquetas por matriz
  for(;col<4;col++){
      Serial.print(matriz_s1[fil][col]);
      Serial.print(',');
      }
      Serial.println(' ');
      col=0;
}


void loop(){
 for(;fil<sumaCont;fil++){//muevo fila
    for(;fil_s<3;fil_s++){ //muevo fila otra matriz
      for(;col_s<4;col_s++){
        dis1 = dis1 + pow(matriz[fil][col_s]-matriz_s1[fil_s][col_s],2); //distancia entre 2 puntos
       dis2 = dis2 + pow(matriz[fil][col_s]-matriz_s2[fil_s][col_s],2);
       dis3 = dis3 + pow(matriz[fil][col_s]-matriz_s3[fil_s][col_s],2);
        }
        distotal=sqrt(dis1); //raiz
        distotal=sqrt(dis2); //raiz
         distotal=sqrt(dis3); //raiz
         
         
        if(distotal<dist_mayor){
          dist_mayor=distotal;
          labell=matriz_s1[fil_s][4]; //guardado de etiqueta
          label2=matriz_s2[fil_s][4];
          label3=matriz_s3[fil_s][4];
     //Serial.println(label);
          }//endif
                  dis=0;
                  col_s=0;
      }//endfor fil_s
  fil_s=0;
  dist_mayor=2000;
      
    if(label1==matriz[fil][4]){
      Serial.print(fil);
       Serial.print(':');
      Serial.println('D');
      }
    else{
      Serial.print(fil);
       Serial.print(':');
      Serial.println('S');
      }

          if(label2==matriz[fil][4]){
      Serial.print(fil);
       Serial.print(':');
      Serial.println('D');
      }
    else{
      Serial.print(fil);
       Serial.print(':');
      Serial.println('S');
      }

          if(label3==matriz[fil][4]){
      Serial.print(fil);
       Serial.print(':');
      Serial.println('D');
      }
    else{
      Serial.print(fil);
       Serial.print(':');
      Serial.println('S');
      }

  }
  }

  void contar(){
    for (int f = 0; f < 75; f++) {
      if(matriz[f][4]==1){
        cont1++;
     
        }
      if(matriz[f][4]==2){
        cont2++;       

        }
    if(matriz[f][4]==3){
        cont3++;
        }
   }
   sumaCont= cont1+cont2+cont3;
a=cont1;
b=cont2;
c=cont3;
    }

