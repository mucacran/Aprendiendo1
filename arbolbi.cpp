/*------- treetester.cpp -----------------------------------------------------------------------------------Programa

para comprobar la p l a n t i l l a  de clase ABB. 
------------------------------------------------------------------------------------------------------------------ */

#include <iostream>
using namespace std;
#include "ABB.h"

int main()
{
	// Comprobacion del constructor y de vacio()
	ABB<int> ABBent; // comprueba el constructor de la clase
	cout <<  "Construccion de un ABB vacio\n";
	cout <<  "El  ABB " <<  (ABBent.vacio() ?  "es" : "no es") << " vacio\n " ;
	
	// Comprobacion de inorden
	cout << "Recorrido en inorden de un ABB: \n";
	ABBent.inorden(cout);
	
	// Comprobacion de i n sertar
	cout <<  "\nAhora insertamos varios enteros en el ABB."
				"\nProbamos con elementos que no estan en el arbol y con otros que si  estan:\n";
	int numero;
	for (;;)
	{
		cout <<  "Elemento a insertar (-999 para terminar): ";
		cin >>  numero;
		if  (numero == -999) break;
		ABBent.insertar(numero);
	}
	ABBent.dibujar(cout);
	
	cout <<  " El ABB " <<  (ABBent.vacio() ?  "es" : "no es") << " vacio\n ";
	cout <<  "Recorrido en inorden del ABB: \n";
	ABBent.inorden(cout);
	
	cout <<  endl;
	
	// Comprobacion de buscar()
	cout <<  "\n\nAhora comprobamos la operacion buscar( ) . "
				"\nProbamos con elementos que estan en el arbol y con otros que no:\n";
	for (;;)
	{
		cout <<  "Elemento a buscar (-999 para terminar): ";
		cin >>  numero;
		if  (numero == -999) break;
		cout 	<<  (ABBent.buscar(numero) ?  "Encontrado" : "No encontrado") 
				<<  endl;
	}

	// Comprobacion de eliminar()
	cout <<  "\nAhora comprobamos la operacion eliminar()."
				"\nProbamos con elementos que estan en el arbol y con otros que no:\n";
	for (;;)
	{
		cout <<  "Elemento a eliminar (-999 para terminar): ";
		cin >>  numero;
		if  (numero == -999) break;
		ABBent.eliminar(numero);
		ABBent.dibujar(cout);
	}
	cout <<  "\nRecorrido en inorden del ABB: \n";
	ABBent.inorden(cout);
	cout <<  endl;
}
