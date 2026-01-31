// Lenguaje - Proyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    std::cout << "Hello World!\n";
}
//Parte 2 hecho por Xavi 
string* buscarEspacio(string** matriz, int f, int c) { //Se guarda el contenido de la variable "nombre" en la dirección de memoria que apunta el puntero
    return &matriz[f][c]; //Al tener la dirección (string*), puedes modificar el contenido de esa celda directamente desde otra parte del programa.
}

void registrarCurso(string** matriz) {
    int fila, columna;
    string nombre;

    cout << "\n--- Registrar Curso ---" << endl;
    cout << "Ingrese bloque horario (0-6): "; cin >> fila;
    cout << "Ingrese dia (0-5): "; cin >> columna;

    if (fila >= 0 && fila < 7 && columna >= 0 && columna < 6) {
        cout << "Nombre del curso (una sola palabra): ";
        cin >> nombre;
        string* ptrCelda = buscarEspacio(matriz, fila, columna); //obtenemos la direccion de la matriz usando punteros :V
        *ptrCelda = nombre; //hacemos que "nombre" se transforme a una matriz para guardar informacion de manera mas eficaz y manipulable pez
        cout << "¡Curso registrado con exito!" << endl;
    }
    else {
        cout << "Error: Indices fuera de rango." << endl;
    }
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
