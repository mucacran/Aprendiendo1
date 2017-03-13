/* ABB.h contiene la declaracion de la plantilla de clase ABB.
	Operaciones basicas:
		Constructor:	construye un ABB vacio
		vacio:			comprueba si  un ABB es vacio
		buscar:			busca un elemento en un ABB
		insertar:		inserta un valor en un ABB
		eliminar:		elimina un valor de un ABB
		inorden:			recorrido en inorden de un ABB
							--	produce como s al ida l o s  valores
		dibujar:			produce en la salida una representacion grafica de
							un ABB

	Operaciones auxiliares  privadas:
		buscar2:			usada por eliminar
		inordenAux:		usada por inorden
		dibujarAux:		usada por dibujar

	Otras operaciones descritas en los  ejercicios: 
		destructor
		constructor de copia
		operador de asignacion
		recorridos en preorden, postorden y por niveles
		buscar el nivel

		Nota: la ejecucion termina si  no hay memoria disponible para un
		nuevo nodo del ABB
----------------------------------------------------------------------*/

#include <iostream>

#ifndef ARBOL_BINARIO_DE_BUSQUEDA
#define ARBOL_BINARIO_DE_BUSQUEDA

template <typename TipoDato>
class ABB 
{
public:
	/*****  Metodos *****/
	//—  Consultar en las  figuras 12.1-12.6 la documentacion
	ABB();	// contruye un objeto vacio
	/*--------------------------------------------------------------------------
		Aqui va una informacion q no encontre
		Aqui va una informacion q no encontre
		Aqui va una informacion q no encontre
	---------------------------------------------------------------------------*/	

	bool vacio() const;	// comprueba si el SBB esta vacio
	/*--------------------------------------------------------------------------
		Aqui va una informacion q no encontre
		Aqui va una informacion q no encontre
		Aqui va una informacion q no encontre
		Aqui va una informacion q no encontre
	---------------------------------------------------------------------------*/

	bool buscar(const TipoDato &elemento) const;	// 
	/*--------------------------------------------------------------------------
		Aqui va una informacion q no encontre
		Aqui va una informacion q no encontre
		Aqui va una informacion q no encontre
		Aqui va una informacion q no encontre
	---------------------------------------------------------------------------*/
	
	void insertar(const TipoDato &elemento);
	/* --------------------------------------------------------------------------
		Inserta elemento en el ABB.

		Precondicion:	Ninguna.
		Postcondicion: Se ha modificado el ABB insertando elemento en el 
							lugar adecuado.
	----------------------------------------------------------------------------*/
	
	void eliminar(const TipoDato & elemento);
	/*----------------------------------------------------------------------------
		Elimina elemento del ABB.
	
		Precondicion:		Ninguna.
		Postcondicion: 	Se ha modificado el ABB eliminando elemento ( s i  
								aparece); se mantiene la propiedad de ser ABB.
		Nota: 				eliminar usa la funcion auxiliar  buscar2() para localizar el 
		nodo que contiene a elemento y a su padre.
	-----------------------------------------------------------------------------*/

	void inorden(ostream & sal )  const;
	/*------------------------------------------------------------------------
		Recorrido en inorden de un ABB.

		Precondicion: 	El ostream sal esta abierto.
		Postcondicion: El ABB se ha recorrido en inorden y los  valores de 
							los  nodos se han escrito en sal.
		Nota: inorden usa la funcion auxiliar  privada inordenAux(). 
	---------------------------------------------------------------------------*/

	void dibujar(ostream & sal )  const;
	/* ------------------------------------------------------------------------
		Dibuja un ABB.

		Precondicion: 	El ostream sal  esta abierto.
		Postcondicion: Se produce la representacion grafica del ABB en 
							salida(sal).
		Nota: 	dibujar() usa la funcion auxiliar  privada dibujarAux(). 
	-----------------------------------------------------------------------------*/
private:
	/***** ciaSedeios nodos *****/  
	class NodoBin
	{
	public:
		TipoDato dato;
		NodoBin *izq;
		NodoBin *der;
		// Constructores de NodoBin
		// Por defecto —  dato toma el valor por defecto del TipoDato; 
		// ambos enlaces son nulos.
		NodoBin(): izq(0 ), der(0){}
	
		
		// Valor explicito -- a dato se le asigna elemento;
		// ambos enlaces son nulos.
		NodoBin(TipoDato elemento): dato(elemento), izq(0 ), der(0){}
	};// fin de la declaracion de la clase NodoBin

	


	typedef NodoBin * PuntNodoBin;

	/*****  Metodos privados *****/
	void buscar2(	const TipoDato & elemento, bool & encontrado,
						PuntNodoBin & puntPos, PuntNodoBin & padre	) const;
	/* ---------------------------------------------------------------------------------------------------------
		Localiza un nodo que contiene elemento y a su padre.

		Precondicion:		Ninguna.
		Postcondicion:		puntPos apunta al nodo que contiene elemento o bien 
		es nulo si no se encuentra, y padre apunta a su padre
	--------------------------------------------------------------------------------*/

	void inordenAux(	ostream & sal ,  PuntNodoBin subRaiz) const;
	/*-------------------------------------------------------------------------------------------
		Funcion auxiliar  para el recorrido en inorden.

		Precondicion: 	El ostream sal  esta abierto; subRaiz apunta a un
							subarbol de este ABB.
		Postcondicion: Se ha escrito en s a l  el contenido del subarbol con
		raiz apuntada por subRaiz.
	--------------------------------------------------------------------------------------------- */
	
	
	void dibujarAux(ostream & sal ,  int desp, PuntNodoBin subRaiz) const;	//puede ser q aqui
	/* ------------------------------------------------------------------------------------------
		Funcion auxiliar  para dibujar.

		Precondicion: 	El ostream sal  esta abierto; subRaiz apunta a un
		subarbol de este ABB.
		Postcondicion: Se ha producido en sal la representacion grafica
		del subarbol con raiz apuntada por subRaiz, desplazada desp 
		espacios.
	----------------------------------------------------------------------------------------------*/

	/****  Atributos *****/
	PuntNodoBin miRaiz;
}; // fin de la declaracion de la plantilla de clase 

//--- Definicion del constructor —  Copiar de la figura 12.1
template <typename TipoDato> 
inline  ABB<TipoDato>::ABB(): miRaiz(0){}




//--- Definicion de vacio() —  Copiar de la figura 12.1
template <typename TipoDato>
inline  bool ABB <TipoDato>:: vacio() const
{ return miRaiz == 0; }

//--- Definicion de buscar() — Copiar de la figura 12.4
template <typename TipoDato>
bool ABB<TipoDato>::buscar(const TipoDato &elemento) const
{
	PuntNodoBin puntPos = miRaiz;
	bool encontrado = false;
	while (!encontrado && puntPos != 0)
	{
		if  (elemento < puntPos -> dato)			//	II descender al izquierdo
			puntPos = puntPos -> izq;
		else if (puntPos -> dato < elemento)	// descender al derecho
			puntPos = puntPos->der;
		else												// elemento encontrado
		encontrado = true;
	}
	return encontrado;
}

//--- Definicion de insertar () —  Copiar de la figura 12.5 
template <typename TipoDato>
inline  void ABB<TipoDato>::insertar(const TipoDato & elemento)
{
	PuntNodoBin
		puntPos = miRaiz, 		// puntero de busqueda
		padre = 0; 					// puntero al padre del nodo actual
	bool encontrado = false; 	// indica si  elemento ya esta en el ABB
	while (!encontrado && puntPos != 0)
	{
		padre = puntPos;
		if  (elemento < puntPos->dato)		// descender hacia la izquierda
				puntPos = puntPos->izq;
		else if (puntPos->dato < elemento)	// descender hacia la derecha 
				puntPos = puntPos->der;
		else				// elemento encontrado
			encontrado = true;
	}
	if (!encontrado)
	{ 																	// construir un nodo conteniendo a elemento
		puntPos = new ABB<TipoDato>::NodoBin(elemento);
		if (padre == 0) 											// arbol vacio
			miRaiz = puntPos;
		else if  (elemento < padre->dato )					// insertar a la izquierda del padre
			padre->izq = puntPos;
		else															// insertar a la derecha del padre 	
			padre->der = puntPos;
	}
	else
		cout << " El elemento ya esta en el arbol\n";
}

//--- Definicion de eliminar() —  Copiar de la figura 12.6
template <typename TipoDato>
void ABB<TipoDato>::eliminar(const TipoDato & elemento)
{
	bool encontrado;	// señala si se ha encontrado elemento
	PuntNodoBin
		x,						// apunta al nodo a eliminar
		padre;				// " " padre de x y sucx
	buscar2(elemento, encontrado, x, padre);

	if (!encontrado)
	{
		cout <<  " El  elemento no esta en el ABB\n";
		return;
	}
	//else
	if  (x->izq != 0 && x->der != 0)
	{ // el nodo tiene 2 hijos
		// Encontrar el sucesor en inorden de x y su padre 
		PuntNodoBin sucx = x->der;
		padre = x;
		while (sucx->izq != 0) // descender al izquierdo
		{
			padre = sucx;
			sucx = sucx->izq;
		}

		// Mover el contenido de sucx a x y cambiar x para que apunte
		// al sucesor, el cual sera eliminado. 
		x->dato = sucx->dato;
		x = sucx;
	} // fin del caso con dos hijos
	
	// Caso en el que el nodo tiene 0 o 1 hijo
	PuntNodoBin 
	subarbol = x->izq;				// puntero a un subarbol de x
	if (subarbol == 0) 
		subarbol = x->der;
	if (padre == 0)					// raiz a eliminar
		miRaiz = subarbol;
	else if  (padre->izq == x)		// hijo izquierdo del padre
		padre->izq = subarbol;
	else									// hijo derecho del padre
		padre->der = subarbol;
	delete x;
}

//--- Definicion de inorden() — Copiar de la figura 12.2
template <typename TipoDato>
inline void ABB<TipoDato>::inorden(ostream & sal )  const
{
	inordenAux(sal, miRaiz);
}

//--- Definicion dedibujar() — Copiar de la figura 12.3
template <typename TipoDato>
inline void ABB<TipoDato>::dibujar(ostream & sal ) const
{ dibujarAux(sal, 0, miRaiz);}

//--- Definicion de buscar2() — Copiar de la figura 12.5
template <typename TipoDato> 
void ABB<TipoDato>::buscar2	(const TipoDato & elemento, bool & encontrado,
										PuntNodoBin & puntPos,
										PuntNodoBin & padre) const
{
	puntPos = miRaiz;
	padre = 0;
	encontrado = false;
	while (!encontrado && puntPos != 0)
	{
		if (elemento < puntPos->dato) // descender al izquierdo
		{
			padre = puntPos;
			puntPos = puntPos->izq;
		}
		else if  (puntPos->dato < elemento) // descender al derecho
		{
			padre = puntPos;
			puntPos = puntPos->der;
		}
		else // elemento encontrado
		encontrado = true;
	}
}

//--- Definicion de inordenAux() —  Copiar de la figura 12.2
template <typename TipoDato>
void ABB<TipoDato>::inordenAux	(ostream & sal ,
											ABB<TipoDato>::PuntNodoBin subRaiz) const
{
	if  (subRaiz != 0)
	{
		inordenAux(sal, subRaiz -> izq);		// operacion I
		sal <<  subRaiz -> dato <<  " ";		// operacion V 
		inordenAux(sal, subRaiz -> der);		// operacion D
	}
}

//--- Definicion de dibujarAux() —  Copiar de la figura 12.3
#include <iomanip>

template <typename TipoDato>
void ABB<TipoDato>::dibujarAux(	ostream & sal, int desp,
											PuntNodoBin subRaiz) const
{
	if  (subRaiz != 0)
	{
		dibujarAux(sal, desp + 8, subRaiz -> der);
		sal <<  setw(desp) <<  " " <<  subRaiz -> dato <<  endl;
		dibujarAux(sal, desp + 8, subRaiz->izq);
	}
}

#endif
