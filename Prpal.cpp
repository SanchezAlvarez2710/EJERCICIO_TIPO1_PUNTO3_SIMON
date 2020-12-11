	
//SIMON SANCHEZ ALVAREZ
//CC 1000204474
//POLITECNICO JIC

/*Usando los conocimientos sobre estructuras dinámicas listas, pilas y colas, escriba un programa
que permita al usuario seleccionar entre las siguientes opciones: a) ingresar datos numéricos en
una pila A, b) ingresar datos numéricos en una pila B, c) generar una lista doblemente enlazada
con los datos contenidos en ambas estructuras y al tiempo generar una cola simplemente
enlazada, sacando de cada pila de manera intercalada los datos, las pilas deberán quedar vacías
d) Ordenar la lista.*/

#include "Funciones_Pila.h"

int main(){
	int op = 0;
	LISTA *L1 = new LISTA();
	int Tam_A = 0, Tam_B = 0;
	cout << "\tINGRESE EL TAMANO DE LA PILA A: ";
	cin >> Tam_A;
	cout << "\n\tINGRESE EL TAMANO DE LA PILA B: ";
	cin >> Tam_B;	
	PILA A(Tam_A);	//CREACION DEL OBJETO PILA A
	PILA B(Tam_B);	//CREACION DEL OBJETO PILA B
	do{
		op = HOME(op, A, B, L1);
	}while(op != 4);
	
	return 0;
}	

