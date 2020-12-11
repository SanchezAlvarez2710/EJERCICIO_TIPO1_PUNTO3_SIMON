
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class NODO{
	private:
		int dato;
		NODO *li, *ld;
	public:
		NODO(){
			li = NULL;
			ld = NULL;
		}
		~NODO(){}
		int GetDato(){
			return dato;
		}
		void SetDato(int d){
			dato = d;
		}
		NODO *GetLi(){
			return li;
		}
		NODO *GetLd(){
			return ld;
		}	
		void SetLi(NODO *ligaizq){
			li = ligaizq;
		}	
		void SetLd(NODO *ligader){
			ld = ligader;
		}		
		friend class LISTA;
};
class LISTA{
	
	NODO *punta;
	public:
		LISTA(){
			punta = NULL;
		}
		LISTA *insertarFinal(int d){
    		NODO *x = new NODO(), *p = punta;
    		x->SetDato(d);
    		if (punta == NULL){
    			punta = x;
			}
			else{
				while (p->GetLd() != NULL){
					p = p->GetLd();
				}
				p->SetLd(x);
			}
		}
		LISTA *MostrarLista(){
			NODO *q = punta;
			cout << "\t";
			while(q != NULL){
				cout << " ==> " << q->GetDato(); 
				q = q->GetLd();
			}
		}
		LISTA *Ordenar(){
			int aux = 0, opcion;
			if (((punta != NULL) && (punta->GetLd() != NULL))){
				NODO *q = punta, *p = NULL;
				do{
					system("cls");
					cout << "\n ==> COMO DESEA ORDENAR LA LISTA?\n-------------------------------------------------\n     (1) ORDEN ASCENDENTE\n     (2) ORDEN DESCENDENTE\n     (3) SALIR\n-------------------------------------------------\n ==> ESOCJA UNA OPCION: ";
					cin >> opcion;
					if(opcion == 1){
						while(q->GetLd() != NULL){
							p = q->GetLd();
							while(p != NULL){
								if(q->GetDato() > p->GetDato()){
									aux = q->GetDato();
									q->SetDato(p->GetDato());
									p->SetDato(aux);
								}
								p = p->GetLd();
							}
							q = q->GetLd();
						}
					}
					else if(opcion == 2){
						while(q->GetLd() != NULL){
							p = q->GetLd();
							while(p != NULL){
								if(p->GetDato() > q->GetDato()){
									aux = q->GetDato();
									q->SetDato(p->GetDato());
									p->SetDato(aux);
								}
								p = p->GetLd();
							}
							q = q->GetLd();
						}
					}
					else if(opcion != 3){
						system("cls");
						cout << "\a\n\tERROR. INGRESE UNA OPCION CORRECTA!";
						getch();
					}
				}while((opcion < 1) && (opcion > 3));
			}
			else{
				system("cls");
				cout << "\a\n\tNO HAY AUN UNA LISTA O SOLO HAY UN DATO\n\tPOR LO TANTO NO SE PUEDE ORDENAR";
				getch();
			}
		}			
		~LISTA(){
		}
};

