// sabado, 6 de mayo de 2017
// Laboratorio III - Programacion III
// Jose Carlos Rojas Herrera - 11541234

#include <iostream>

using namespace std;

void initMatriz(char**, int, int); // matriz, filas, columnas
void imprimirMatriz(char**, int, int); // matriz, filas, columnas
// void liberarMatriz(char**, int, int); // matriz, filas, columnas

int main()
{
	int filas = 6;
	int columnas = 7;
	
	// Crea la matriz
	char** matriz = new char*[filas];
	for(int j = 0; j < columnas; j++)
		matriz[j] = new char[columnas];
	
	initMatriz(matriz, filas, columnas);
	imprimirMatriz(matriz, filas, columnas);
	
	// Empieza el juego
	int J1;
	cout << "Jugador 1, escoja una columna [0-6] para dejar caer su pieza: ";
	cin >> J1;
	
	for(int x = filas - 1; x >= 0; x--)
	{
		if(matriz[x][J1] == ' ')
		{
			matriz[x][J1] = '*';
			break;
		}
	}
	
	imprimirMatriz(matriz, filas, columnas);
	
	// Libera la matriz
	for(int i = 0; i < filas; i++)
	{
		delete[] matriz[i];
		matriz[i] = NULL;
	}
	delete[] matriz;
	
	return 0;
}

void initMatriz(char** matriz, int filas, int columnas)
{
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
			matriz[i][j] = ' ';
	}
}

void imprimirMatriz(char** matriz, int filas, int columnas)
{
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
			cout << "[" << matriz[i][j] << "]";
		cout << endl;
	}
}

/* void liberarMatriz(char** matriz, int filas, int columnas)
{
	for(int i = 0; i < filas; i++)
	{
		delete[] matriz[i];
		matriz[i] = NULL;
	}
	delete[] matriz;
} */
