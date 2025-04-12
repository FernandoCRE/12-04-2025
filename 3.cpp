#include <iostream>
using namespace std;

// funcion para imprimir la matriz
void imprimir(int* a, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            int valor = *(a + i * columnas + j);
            if (valor == 0)
                cout << "   "; // 0 espacio vacio
            else
                cout << valor << "  ";
        }
        cout << endl;
    }
}

// funcion para intercambiar valores
void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}  
    };

    int* ptr = &matriz[0][0]; // puntero al inicio
    int fila = 2;  // pos actual del 0
    int col = 2;   // pos actual del 0

    char tecla;
    cout << "usa w (arriba), a (izquierda), s (abajo), d (derecha). q para salir.\n\n";

    // while
    while (true) {
        imprimir(ptr, 3, 3);  // mostramos la matriz
        cout << "\ntu movimiento: ";
        cin >> tecla;

        if (tecla == 'q') break;  

        if (tecla == 'w' && fila > 0) {
            intercambiar(ptr + fila * 3 + col, ptr + (fila - 1) * 3 + col);
            fila--;
        }
        else if (tecla == 's' && fila < 2) {
            intercambiar(ptr + fila * 3 + col, ptr + (fila + 1) * 3 + col);
            fila++;
        }
        else if (tecla == 'a' && col > 0) {
            intercambiar(ptr + fila * 3 + col, ptr + fila * 3 + (col - 1));
            col--;
        }
        else if (tecla == 'd' && col < 2) {
            intercambiar(ptr + fila * 3 + col, ptr + fila * 3 + (col + 1));
            col++;
        }

        cout << "\n";

        
    }

    return 0;
}
