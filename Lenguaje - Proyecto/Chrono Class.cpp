// Lenguaje - Proyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>

#define MAX_FILAS_HORAS 7
#define MAX_COLUMNAS_DIAS 6

using namespace std;

// --- PARTE 1: GESTIÓN DE MEMORIA ---
string** crearMatriz() {
    string** matrizHorario = new string * [MAX_FILAS_HORAS];
    for (int filaContador = 0; filaContador < MAX_FILAS_HORAS; filaContador++) {
        matrizHorario[filaContador] = new string[MAX_COLUMNAS_DIAS];
    }
    return matrizHorario;
}

void inicializar(string** matrizHorario) {
    for (int indiceFila = 0; indiceFila < MAX_FILAS_HORAS; indiceFila++) {
        for (int indiceColumna = 0; indiceColumna < MAX_COLUMNAS_DIAS; indiceColumna++) {
            matrizHorario[indiceFila][indiceColumna] = "---";
        }
    }
}

void liberarMemoria(string** matrizHorario) {
    for (int bloqueHorario = 0; bloqueHorario < MAX_FILAS_HORAS; bloqueHorario++) {
        delete[] matrizHorario[bloqueHorario];
    }
    delete[] matrizHorario;
}

// --- PARTE 2: REGISTRO (XAVI) ---
string* buscarEspacio(string** matrizHorario, int filaSeleccionada, int columnaSeleccionada) {
    return &matrizHorario[filaSeleccionada][columnaSeleccionada];
}

void registrarCurso(string** matrizHorario) {
    int filaIngresada, columnaIngresada;
    string nombreDelCurso;
    cout << "\n--- Registrar Curso ---\n";
    cout << "Ingrese Bloque Horario (0-6): "; cin >> filaIngresada;
    cout << "Ingrese Dia (0-5): "; cin >> columnaIngresada;

    if (filaIngresada >= 0 && filaIngresada < MAX_FILAS_HORAS &&
        columnaIngresada >= 0 && columnaIngresada < MAX_COLUMNAS_DIAS) {

        cout << "Nombre del curso: ";
        cin.ignore();
        getline(cin, nombreDelCurso);

        string* celdaDestino = buscarEspacio(matrizHorario, filaIngresada, columnaIngresada);
        *celdaDestino = nombreDelCurso;
        cout << "¡Curso registrado con exito!\n";
    }
    else {
        cout << "Error: Indices fuera de rango.\n";
    }
}

// --- PARTE 3: REPORTES (KEVIN) ---
void MostrarHorarioCompleto(string** Horario, int HorasTotales, int DiasTotales) {
    string DiasSemana[6] = { "Lunes","Martes","Miercoles","Jueves","Viernes","Sabado" };
    int anchoColumna = 10;

    cout << "\n\t=======================================Horario Completo====================================================\n";
    cout << "\tHora\t";

    for (int dias = 0; dias < DiasTotales; dias++) {
        string nombreDia = DiasSemana[dias];
        int espacios = anchoColumna - nombreDia.length();
        cout << nombreDia;
        for (int espacio = 0; espacio < espacios; espacio++) cout << " ";
        cout << "\t";
    }
    cout << "\n\t-------------------------------------------------------------------------------------------------------";
    cout << "\n";

    for (int fila = 0; fila < HorasTotales; fila++) {
        cout << "\t" << (fila + 8) << ":00\t";

        for (int columna = 0; columna < DiasTotales; columna++) {
            string curso = Horario[fila][columna];
            int espaciosCurso = anchoColumna - curso.length();

            cout << curso;
            for (int espacio = 0; espacio < espaciosCurso; espacio++) cout << " ";
            cout << "\t";
        }
        cout << "\n";
    }
    cout << "\n\t===========================================================================================================\n";
}

// --- PARTE 4: PROCESAMIENTO (HAYLIE) ---
void contar_horas(string** matrizHorario) {
    string cursoABuscar;
    int totalBloquesEncontrados = 0;
    cout << "\n¿De que curso quieres contar las horas?: ";
    cin.ignore();
    getline(cin, cursoABuscar);

    for (int filaBusqueda = 0; filaBusqueda < MAX_FILAS_HORAS; filaBusqueda++) {
        for (int columnaBusqueda = 0; columnaBusqueda < MAX_COLUMNAS_DIAS; columnaBusqueda++) {
            if (matrizHorario[filaBusqueda][columnaBusqueda] == cursoABuscar) {
                totalBloquesEncontrados++;
            }
        }
    }
    cout << "Resultado: " << cursoABuscar << " tiene " << totalBloquesEncontrados << " horas." << endl;
}

int main() {
    string** horarioAcademico = crearMatriz();
    inicializar(horarioAcademico);

    int opcionSeleccionada;
    do {
        cout << "\n>>> SISTEMA CHRONO CLASS <<<\n";
        cout << "1. Registrar Curso\n2. Ver Horario Completo\n3. Contar Horas\n4. Salir\nOpcion: ";
        cin >> opcionSeleccionada;

        switch (opcionSeleccionada) {
        case 1: registrarCurso(horarioAcademico); break;
        case 2: MostrarHorarioCompleto(horarioAcademico, MAX_FILAS_HORAS, MAX_COLUMNAS_DIAS); break;
        case 3: contar_horas(horarioAcademico); break;
        case 4: cout << "Saliendo y liberando memoria..."; break;
        }
    } while (opcionSeleccionada != 4);

    liberarMemoria(horarioAcademico);
    return 0;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
