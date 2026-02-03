#include <iostream>
#include <string>
#include <stdio.h>

#define FILAS 7
#define COLUMNAS 6

using namespace std;

// --- PARTE 1: GESTIÓN DE MEMORIA (Fernando) ---
string** crearMatriz() {
    string** matriz = new string * [FILAS];
    for (int hora = 0; hora < FILAS; hora++) {
        matriz[hora] = new string[COLUMNAS];
    }
    return matriz;
}

void inicializar(string** matriz) {
    for (int hora = 0; hora < FILAS; hora++) {
        for (int dia = 0; dia < COLUMNAS; dia++) {
            matriz[hora][dia] = "---";
        }
    }
}

void liberarMemoria(string** matriz) {
    for (int hora = 0; hora < FILAS; hora++) {
        delete[] matriz[hora];
    }
    delete[] matriz;
}

// --- PARTE 2: REGISTRO (XAVI) ---
string* buscarEspacio(string** matriz, int fila, int columna) {
    return &matriz[fila][columna];
}

void registrarCurso(string** matriz) {
    int fila, columna;
    string nombre;
    cout << "\n--- Registrar Curso ---" << endl;
    cout << "Ingrese bloque horario (0.8:00/1.9:00/.../6.2:00): "; cin >> fila;
    cout << "Ingrese dia (0.Lunes/1.Martes/.../5.Sabado): "; cin >> columna;

    if (fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS) {
        cout << "Nombre del curso: ";
        cin.ignore();
        getline(cin, nombre);

        string* celda = buscarEspacio(matriz, fila, columna);
        *celda = nombre;
        cout << "Curso registrado con exito!" << endl;
    }
    else {
        cout << "Error: Indices fuera de rango." << endl;
    }
}

// --- PARTE 3: REPORTES (Kevin) ---
void MostrarHorarioCompleto(string** Horario, int HorasTotales, int DiasTotales) {
    string DiasSemana[6] = { "Lunes","Martes","Miercoles","Jueves","Viernes","Sabado" };

    cout << "\n\t==================== Horario Completo ====================\n";
    cout << "\tHora\tLunes\tMartes\tMierc.\tJueves\tViern.\tSabado\n";
    cout << "\t----------------------------------------------------------\n";

    for (int hora = 0; hora < HorasTotales; hora++) {
        cout << "\t" << (hora + 8) << ":00\t";
        for (int dia = 0; dia < DiasTotales; dia++) {
            cout << Horario[hora][dia] << "\t";
        }
        cout << "\n";
    }
    cout << "\t==========================================================\n";
}

void MostrarDia(string** Horario, int Horas, int Dias) {
    int Dia;
    string DiasSemana[6] = { "Lunes","Martes","Miercoles","Jueves","Viernes","Sabado" };

    do {
        cout << "\n\tIngrese dia (1=Lunes ... " << Dias << "=Sabado): ";
        cin >> Dia;

        if (Dia < 1 || Dia > Dias) {
            cout << "\tDia invalido, porfabor vuelva a ingresar el numero dentro del rango.\n";
        }
    } while (Dia < 1 || Dia > Dias);

    cout << "\n\tClases de " << DiasSemana[Dia - 1] << ":\n";
    for (int hora = 0; hora < Horas; hora++) {
        cout << "\t" << (hora + 8) << ":00 - " << Horario[hora][Dia - 1] << "\n";
    }
}

// --- PARTE 4: PROCESAMIENTO (Haylie) ---
void contar_horas(string** matriz, int filas, int columnas) {
    string buscar;
    int contador = 0;

    cout << "\nDe que curso quieres contar las horas?: ";
    cin.ignore();
    getline(cin, buscar);

    for (int hora = 0; hora < filas; hora++) {
        for (int dia = 0; dia < columnas; dia++) {
            if (matriz[hora][dia] == buscar) {
                contador++;
            }
        }
    }
    cout << "Resultado: " << buscar << " tiene " << contador << " hora(s)." << endl;
}

int main() {
    string** horarioPrincipal = crearMatriz();
    inicializar(horarioPrincipal);

    int opcion;
    do {
        cout << "\n\t=======================================\n";
        cout << "      \t\tSISTEMA CHRONO CLASS     \n";
        cout << "\t========================================\n";
        cout << "\t |1. Registrar curso                  |\n ";
        cout << "\t |2. Mostrar horario completo         |\n";
        cout << "\t |3. Mostrar clases de un dia         |\n";
        cout << "\t |4. Contar horas de un curso         |\n";
        cout << "\t |5. Salir                            |\n";
        cout << "\t---------------------------------------\n";
        cout << "\tElija una opcion (1-5): ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            registrarCurso(horarioPrincipal);
            break;
        case 2:
            MostrarHorarioCompleto(horarioPrincipal, FILAS, COLUMNAS);
            break;
        case 3:
            MostrarDia(horarioPrincipal, FILAS, COLUMNAS);
            break;
        case 4:
            contar_horas(horarioPrincipal, FILAS, COLUMNAS);
            break;
        case 5:
            cout << "Saliendo...";
            break;
        default:
            cout << "\n\tOpcion no valida. porfabor volver a ingresar" << endl;
            break;
        }

    } while (opcion != 5);

    liberarMemoria(horarioPrincipal);
    return 0;
}