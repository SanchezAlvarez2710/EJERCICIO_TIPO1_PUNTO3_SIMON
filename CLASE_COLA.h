
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class nodo{
	private:
		int dato;
		nodo *liga;
	public:
		nodo(){
			liga = NULL;
			dato = 0;
		}
		int GetDato(){
			return dato;
		}
		void SetDato(int d){
			dato = d;
		}
		nodo *GetLiga(){
			return liga;
		}
		void SetLiga(nodo *l){
			liga = l;
		}
		~nodo(){
		}
		friend class COLA;
};
class COLA{
	
	private:
		int Limite;
		int Tope;
		nodo *Punta;
	public:
		COLA(int n){
			Limite = n;
			Tope = 0;
			Punta = NULL;
		}
		void Encolar(int d){
			nodo *p = Punta;
			nodo *x = new nodo();
			x->SetDato(d);
			if(ColaLlena() == false){
	    		if (Punta == NULL){
	    			Punta = x;	    			
				}
				else{
					while (p->GetLiga() != NULL){
						p = p->GetLiga();
					}
					p->SetLiga(x);				
				}
				Tope++;
			}
		}
		int Desencolar(){
			int r = 0;
			nodo *p;
			if(ColaVacia() == false){
				p = Punta;
				r = p->GetDato();
				p = p->GetLiga();
				Punta = p;
				Tope--;
			}
			return r;
		}			
		bool ColaVacia(){
			if(Tope < 1){
				return true;
			}
			return false;
		}
		bool ColaLlena(){
			if(Tope == Limite){
				return true;
			}
			return false;
		}	
		void MostrarCola(){
			nodo *p = Punta;
			COLA Aux(Limite);
			cout << "\t| ";
			while(p != NULL){
				Aux.Encolar(p->GetDato());
				cout << p->GetDato() << " | ";
				p = p->GetLiga();
				Punta = p;
			}
			//LlenarCola(Aux);
		}
		/*void LlenarCola(COLA A){
			int r = 0;
			while(A.ColaVacia() == false){
				r = A.Desencolar();
				Encolar(r);
			}
		}*/
		~COLA(){
		}
};
