
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class PILA{
	
	private:
		int Limite;
		int Tope;
		int *VEC;
	public:
		PILA(int n){		//CONSTRUCTOR
			Limite = n-1;
			Tope = -1;
			VEC = new int[n];
		}
		~PILA(){}			//DESTRUCTOR
		void Apilar(int d){
			if (PilaLlena() == false){
				Tope++;
				VEC[Tope] = d;
			}		
		}
		int Desapilar(){
			int d = 0;
			if(PilaVacia() == false){
				d = VEC[Tope];
				Tope--;	
			}
			return d;
		}
		bool PilaLlena(){
			if(Tope == Limite){
				return true;
			}
			return false;
		}
		bool PilaVacia(){
			if(Tope < 0){
				return true;
			}
			return false;
		}
		void LlenarPila(PILA A){
			int r = 0;
			while(A.PilaVacia() == false){
				r = A.Desapilar();
				Apilar(r);
			}
		}
		int SumarLimites(PILA A){
			int sum = 0;
			sum = (Limite + A.Limite) + 2; 
			return sum;
		}
		void Mostrar_Pila(){
			int r = 0;
			cout << "\n\tMOSTRANDO PILA...\n" << endl;
			PILA Aux(Limite+1);
			while(PilaVacia() == false){
				r = Desapilar();
				cout << "\t| " << r << " |" << endl;
				Aux.Apilar(r);	
			}
			getch();
			LlenarPila(Aux);
		}
};

