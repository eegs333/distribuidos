#include <stdio.h>
#include <math.h>
#include "gfxModified.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <vector>

using namespace std;

//Resolución de la pantalla
#define ANCHURA 900
#define ALTURA 300
#define x1 57
#define x2 115
#define x3 50


void pintaNumeros(int n, int s);
void borraNumeros(int s);

int main(int argc, char *argv[])
{
	 
     int coor=0;
     gfx_open(ANCHURA, ALTURA, "Reloj Digital");
     gfx_color(255,0,0);
     gfx_rectangle(10,10,880,280);
     gfx_color(0,255,0);
     /*gfx_rectangle(50,80,70,100);
     gfx_rectangle(130,80,70,100);
     gfx_rectangle(210,80,70,100);
     gfx_rectangle(290,80,70,100);
     gfx_rectangle(370,80,70,100);
     gfx_rectangle(450,80,70,100);
     gfx_rectangle(530,80,70,100);
     gfx_rectangle(610,80,70,100);
     gfx_rectangle(690,80,70,100);
     gfx_rectangle(770,80,70,100);*/
     gfx_color(0,0,255);
     gfx_fill_rectangle(238,95,20,20);
     gfx_fill_rectangle(238,145,20,20);
     gfx_fill_rectangle(478,95,20,20);
     gfx_fill_rectangle(478,145,20,20);
     gfx_fill_rectangle(718,95,20,20);
     gfx_fill_rectangle(718,145,20,20);
     gfx_flush();
     
     while(1){
        string num;
        cout<<"Ingresa número: ";
        cin>>num;
        char n;
        int numero;
        for(int i=0; i<sizeof(num);i++){
            n=num[i];
            numero = n-'0';
            /*cout<<numero<<"*";
            cout<<num[i]<<",";*/
            pintaNumeros(numero, coor);
            coor+=80;
        } 
       /*sizeof(nume)
       static_cast<int>(nume); 
        pintaNumeros(numero, 0);
        pintaNumeros(numero, 80);
        pintaNumeros(numero, 240);
        pintaNumeros(numero, 320);        
        pintaNumeros(numero, 480);
        pintaNumeros(numero, 560);
        pintaNumeros(numero, 720);
        numero=0;*/
        //borraNumeros();
        gfx_flush();

    }
     //borraNumeros();
     sleep(1000) ;   
    
    return(0);
}

void pintaNumeros(int n, int s){
    int num=n, suma =s;    
    borraNumeros(suma);
     gfx_color(0,0,255);  
    if(num==0){
        gfx_fill_rectangle(x1+suma,80,56,5);
        gfx_fill_rectangle(x2+suma,85,5,40);
        gfx_fill_rectangle(x2+suma,135,5,40);
        gfx_fill_rectangle(x1+suma,175,56,5);
        gfx_fill_rectangle(x3+suma,85,5,40);
        gfx_fill_rectangle(x3+suma,136,5,40);
    }else if(num ==1){
        gfx_fill_rectangle(x2+suma,85,5,40);
        gfx_fill_rectangle(x2+suma,135,5,40);  
    }else if(num ==2){
        gfx_fill_rectangle(x1+suma,80,56,5);
        gfx_fill_rectangle(x2+suma,85,5,40);
        gfx_fill_rectangle(x1+suma,175,56,5);
        gfx_fill_rectangle(x3+suma,136,5,40);
        gfx_fill_rectangle(x1+suma,128,56,5);        
    }else if(num ==3){
        gfx_fill_rectangle(x1+suma,80,56,5);
        gfx_fill_rectangle(x2+suma,85,5,40);
        gfx_fill_rectangle(x1+suma,175,56,5);
        gfx_fill_rectangle(x2+suma,135,5,40);
        gfx_fill_rectangle(x1+suma,128,56,5); 
    }else if(num ==4){
        gfx_fill_rectangle(x2+suma,85,5,40);
        gfx_fill_rectangle(x2+suma,135,5,40);
        gfx_fill_rectangle(x1+suma,128,56,5);
        gfx_fill_rectangle(x3+suma,85,5,40); 
    }else if(num ==5){
        gfx_fill_rectangle(x1+suma,80,56,5);
        gfx_fill_rectangle(x3+suma,85,5,40);
        gfx_fill_rectangle(x1+suma,128,56,5);
        gfx_fill_rectangle(x2+suma,135,5,40); 
        gfx_fill_rectangle(x1+suma,175,56,5);
    }else if(num ==6){
        gfx_fill_rectangle(x1+suma,80,56,5);
        gfx_fill_rectangle(x3+suma,85,5,40);
        gfx_fill_rectangle(x1+suma,128,56,5);
        gfx_fill_rectangle(x2+suma,135,5,40); 
        gfx_fill_rectangle(x1+suma,175,56,5); 
        gfx_fill_rectangle(x3+suma,136,5,40);
    }else if(num ==7){
        gfx_fill_rectangle(x1+suma,80,56,5);
        gfx_fill_rectangle(x2+suma,85,5,40);
        gfx_fill_rectangle(x2+suma,135,5,40);
        gfx_fill_rectangle(x1+suma,128,56,5);
    }else if(num ==8){        
        gfx_fill_rectangle(x1+suma,80,56,5);
        gfx_fill_rectangle(x2+suma,85,5,40);
        gfx_fill_rectangle(x2+suma,135,5,40);
        gfx_fill_rectangle(x1+suma,175,56,5);
        gfx_fill_rectangle(x3+suma,85,5,40);
        gfx_fill_rectangle(x3+suma,136,5,40);
        gfx_fill_rectangle(x1+suma,128,56,5);
    }else if(num ==9){
        gfx_fill_rectangle(x1+suma,80,56,5);
        gfx_fill_rectangle(x2+suma,85,5,40);
        gfx_fill_rectangle(x2+suma,135,5,40);
        gfx_fill_rectangle(x1+suma,175,56,5);
        gfx_fill_rectangle(x3+suma,85,5,40);
        gfx_fill_rectangle(x1+suma,128,56,5); 
    }
}

void borraNumeros(int s){
    int sum=s;
    gfx_color(0,0,0);
    gfx_fill_rectangle(x1+sum,80,56,5);
    gfx_fill_rectangle(x2+sum,85,5,40);
    gfx_fill_rectangle(x2+sum,135,5,40);
    gfx_fill_rectangle(x1+sum,175,56,5);
    gfx_fill_rectangle(x3+sum,85,5,40);
    gfx_fill_rectangle(x3+sum,136,5,40);
    gfx_fill_rectangle(x1+sum,128,56,5);
}