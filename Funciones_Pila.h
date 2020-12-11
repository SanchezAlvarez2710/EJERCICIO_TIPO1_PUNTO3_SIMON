
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CLASE_PILAS.h"
#include "CLASE_LISTAS.h"
#include "CLASE_COLA.h"

using namespace std;

void CASOS_HOME(int, PILA &, PILA &, LISTA *&);
void CREACION_PILAS(PILA &, PILA &);
void CREACION_LISTA_COLA(PILA &,PILA &, LISTA *&);
void ORDENAR_LISTA(LISTA *&);

int HOME(int opcion, PILA &A, PILA &B, LISTA *&L1){
	
	system("cls");
	cout << "\n\t\tTIPO 1 // PUNTO3\n" << endl;
	cout << "\t1. INGRESAR DATO A LAS PILAS" << endl;
	cout << "\t2. GENERAR LISTA DOBLE ENLAZADA Y COLA CON (A Y B)" << endl;
	cout << "\t3. ORDENAR LA LISTA DOBLE GENERADA" << endl;
	cout << "\t4. SALIR DEL PROGRAMA" << endl;
	cout << "\t----------------------------------------------------------" << endl;
	cout << "\tESCOJA UNA OPCION: ";
	cin >> opcion;
	CASOS_HOME(opcion, A, B, L1);
	return opcion;
}

void CASOS_HOME(int op, PILA &A, PILA &B, LISTA *&L1){
	switch(op){
		case 1:
			CREACION_PILAS(A,B);
		break;
		case 2:
			CREACION_LISTA_COLA(A,B,L1);
		break;
		case 3:
			ORDENAR_LISTA(L1);
		break;
		default:
			if(op != 4){
				system("cls");
				cout << "\tERROR. INGRESE UNA OPCION CORRECTA!\n\t" << endl;
				system("pause");
			}
		break;				
	}
}

void CREACION_PILAS(PILA &A, PILA &B){
	
	system("cls");
	while(A.PilaLlena() == false){
		int d = 0;
		cout << "\n\tINGRESE DATO QUE SE APILA EN A: ";
		cin >> d;
		A.Apilar(d);
	}
	cout << "\n\t------------------------------------------------------" << endl;
	cout << "\tPILA A" << endl;
	A.Mostrar_Pila();
	system("cls");
	while(B.PilaLlena() == false){
		int s = 0;
		cout << "\n\tINGRESE DATO QUE SE APILA EN B: ";
		cin >> s;
		B.Apilar(s);
	}		
	cout << "\n\t------------------------------------------------------" << endl;
	cout << "\tPILA B" << endl;
	B.Mostrar_Pila();		
}

void CREACION_LISTA_COLA(PILA &A, PILA &B, LISTA *&L1){
	
	int r = 0, suma = 0;
	suma = A.SumarLimites(B);
	COLA *C1 = new COLA(suma);
	cout << "\n\t" << suma;
	while((A.PilaVacia() == false) || (B.PilaVacia() == false)){
		if((A.PilaVacia() == false) && (B.PilaVacia() == true)){
			r = A.Desapilar();
			L1->insertarFinal(r);
			C1->Encolar(r);
		}
		else if((B.PilaVacia() == false) && (A.PilaVacia() == true)){
			r = B.Desapilar();
			L1->insertarFinal(r);
			C1->Encolar(r);
		}
		else{
			r = A.Desapilar();
			L1->insertarFinal(r);
			C1->Encolar(r);				
			r = B.Desapilar();
			L1->insertarFinal(r);
			C1->Encolar(r);					
		}
	}
	cout << "\n\tMOSTRANDO LISTA..." << endl;
	L1->MostrarLista();
	cout << "\n\t-------------------------------------------";
	cout << "\n\tMOSTRANDO COLA..." << endl;
	C1->MostrarCola();
	cout << "\n\t";
	system("pause");
}
void ORDENAR_LISTA(LISTA *&L1){
	L1->Ordenar();
	L1->MostrarLista();
	cout << "\n\t";
	system("pause");
}
