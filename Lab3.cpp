// sabado, 6 de mayo de 2017
// Laboratorio III - Programacion III
// Jose Carlos Rojas Herrera - 11541234

#include <iostream>

using namespace std;

void initMatriz(char**, int, int); // matriz, filas, columnas
void imprimirMatriz(char**, int, int); // matriz, filas, columnas
// void liberarMatriz(char**, int, int); // matriz, filas, columnas
bool revisarJ1(char**, int, int); // matriz, x, y
bool revisarJ2(char**, int, int); // matriz, x, y

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
	
	bool J1 = false;
	bool J2 = false;
	// Empieza el juego
	while(J1 == false && J2 == false)
	{
		int x_J1;
        	cout << "Jugador 1, escoja una columna [0-6] para dejar caer su pieza: ";
        	cin >> x_J1;
		
		int y_J1;
        	for(int i = filas - 1; i >= 0; i--)
        	{
                	if(matriz[i][x_J1] == ' ')
                	{
				y_J1 = i;
                        	matriz[i][x_J1] = '*';
                        	break;
                	}
        	}
		
		imprimirMatriz(matriz, filas, columnas);
		J1 = revisarJ1(matriz, y_J1, x_J1);
		
		int x_J2;
		cout << "Jugador 2, escoja una columna [0-6] para dejar caer su pieza: ";
		cin >> x_J2;
		
		int y_J2;
		for(int i = filas - 1; i >= 0; i--)
		{
			if(matriz[i][x_J2] == ' ')
			{
				y_J2 = i;
				matriz[i][x_J2] = '&';
				break;
			}
		}
		
		imprimirMatriz(matriz, filas, columnas);
		J2 = revisarJ2(matriz, y_J2, x_J2);
	}
	
	if(J1)
		cout << "Ha ganado el Jugador 1" << endl;
	else if(J2)
		cout << "Ha ganado el Jugador 2" << endl;
	
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

bool revisarJ1(char** matriz, int y, int x) // x es para columnas e y es para filas
{
	// Revisa horizontalmente, hacia la izquierda
	int cont = 1;
	if(x - 1 >= 0)
	{
		if(matriz[y][x - 1] == '*')
		{
			cont++;
			if(x - 2 >= 0)
			{
				if(matriz[y][x - 2] == '*')
				{
					cont++;
					if(x - 3 >= 0)
					{
						if(matriz[y][x - 3] == '*')
						{
							cont++;
							return true;
						}
					}
				}
			}
		}
	}
	// Revisa horizontalmente, hacia la derecha
	if(x + 1 <= 6)
	{
		if(matriz[y][x + 1] == '*')
		{
			cont++;
			if(x + 2 <= 6)
			{
				if(matriz[y][x + 2] == '*')
				{
					cont++;
					if(x + 3 <= 6)
					{
						if(matriz[y][x + 3] == '*')
						{
							cont++;
							return true;
						}
					}
				}
			}
		}
	}
	// Revisa verticalmente, hacia abajo
	if(y + 1 <= 5)
	{
		if(matriz[y + 1][x] == '*')
		{
			cont++;
			if(y + 2 <= 5)
			{
				if(matriz[y + 2][x] == '*')
				{
					cont++;
					if(y + 3 <= 5)
					{
						if(matriz[y + 3][x] == '*')
						{
							cont++;
							return true;
						}
					}
				}
			}
		}
	}
	// Revisa verticalmente, hacia arriba
	if(y - 1 >= 0)
	{
		if(matriz[y - 1][x] == '*')
		{
			cont++;
			if(y - 2 >= 0)
			{
				if(matriz[y - 2][x] == '*')
				{
					cont++;
					if(y - 3 >= 0)
					{
						if(matriz[y - 3][x] == '*')
						{
							cont++;
							return true;
						}
					}
				}
			}
		}
	}
	// Revisa diagonalmente, de izquierda a derecha
        if(y - 1 >= 0 && x + 1 <= 6)
        {
                if(matriz[y - 1][x + 1] == '*')
                {
                        cont++;
                        if(y - 2 >= 0 && x + 2 <= 6)
                        {
                                if(matriz[y - 2][x + 2] == '*')
                                {
                                        cont++;
                                        if(y - 3 >= 0 && x + 3 <= 6)
                                        {
                                                if(matriz[y - 3][x + 3] == '*')
                                                {
                                                        cont++;
                                                        return true;
                                                }
                                        }
                                }
                        }
                }
        }
	// Revisa diagonalmente, de derecha a izquierda
        if(y + 1 <= 5 && x - 1 >= 0)
        {
                if(matriz[y + 1][x - 1] == '*')
                {
                        cont++;
                        if(y + 2 <= 5 && x - 2 >= 0)
                        {
                                if(matriz[y + 2][x - 2] == '*')
                                {
                                        cont++;
                                        if(y + 3 <= 5 && x - 3 >= 0)
                                        {
                                                if(matriz[y + 3][x - 3] == '*')
                                                {
                                                        cont++;
                                                        return true;
                                                }
                                        }
                                }
                        }
                }
        }
	
	// cout << cont << endl;
	
	if(cont >= 4)
		return true;
	else
		return false;
}

bool revisarJ2(char** matriz, int y, int x)
{
	// Revisa horizontalmente, hacia la izquierda
        int cont = 1;
        if(x - 1 >= 0)
        {
                if(matriz[y][x - 1] == '&')
                {
                        cont++;
                        if(x - 2 >= 0)
                        {
                                if(matriz[y][x - 2] == '&')
                                {
                                        cont++;
                                        if(x - 3 >= 0)
                                        {
                                                if(matriz[y][x - 3] == '&')
                                                {
                                                        cont++;
                                                        return true;
                                                }
                                        }
                                }
                        }
                }
        }
	// Revisa horizontalmente, hacia la derecha
        if(x + 1 <= 6)
        {
                if(matriz[y][x + 1] == '&')
                {
                        cont++;
                        if(x + 2 <= 6)
                        {
                                if(matriz[y][x + 2] == '&')
                                {
                                        cont++;
                                        if(x + 3 <= 6)
                                        {
                                                if(matriz[y][x + 3] == '&')
                                                {
                                                        cont++;
                                                        return true;
                                                }
                                        }
                                }
                        }
                }
        }
	// Revisa verticalmente, hacia abajo
        if(y + 1 <= 5)
        {
                if(matriz[y + 1][x] == '&')
                {
                        cont++;
                        if(y + 2 <= 5)
                        {
                                if(matriz[y + 2][x] == '&')
                                {
                                        cont++;
                                        if(y + 3 <= 5)
                                        {
                                                if(matriz[y + 3][x] == '&')
                                                {
                                                        cont++;
                                                        return true;
                                                }
                                        }
                                }
                        }
                }
        }
	// Revisa verticalmente, hacia arriba
        if(y - 1 >= 0)
        {
                if(matriz[y - 1][x] == '&')
                {
                        cont++;
                        if(y - 2 >= 0)
                        {
                                if(matriz[y - 2][x] == '&')
                                {
                                        cont++;
                                        if(y - 3 >= 0)
                                        {
                                                if(matriz[y - 3][x] == '&')
                                                {
                                                        cont++;
                                                        return true;
                                                }
                                        }
                                }
                        }
                }
        }
	// Revisa diagonalmente, de izquierda a derecha
	if(y - 1 >= 0 && x + 1 <= 6)
	{
		if(matriz[y - 1][x + 1] == '&')
		{
			cont++;
			if(y - 2 >= 0 && x + 2 <= 6)
			{
				if(matriz[y - 2][x + 2] == '&')
				{
					cont++;
					if(y - 3 >= 0 && x + 3 <= 6)
					{
						if(matriz[y - 3][x + 3] == '&')
						{
							cont++;
							return true;
						}
					}
				}
			}
		}
	}
	// Revisa diagonalmente, de derecha a izquierda
	if(y + 1 <= 5 && x - 1 >= 0)
	{
		if(matriz[y + 1][x - 1] == '&')
		{
			cont++;
			if(y + 2 <= 5 && x - 2 >= 0)
			{
				if(matriz[y + 2][x - 2] == '&')
				{
					cont++;
					if(y + 3 <= 5 && x - 3 >= 0)
					{
						if(matriz[y + 3][x - 3] == '&')
						{
							cont++;
							return true;
						}
					}
				}
			}
		}
	}
	
	if(cont >= 4)
                return true;
        else
                return false;
}
