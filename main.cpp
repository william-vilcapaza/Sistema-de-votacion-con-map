#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Función que imprime los resultados de la votación
void imprimirResultados(unordered_map < string, int>& votos)
{
    cout << "Resultados de la votacion: " << endl;

    // Iterar a través de los elementos de la tabla hash y mostrar el nombre de la opción y el número de votos
    for (auto it = votos.begin(); it != votos.end(); ++it) {
        cout << it->first << ": " << it->second << " votos" << endl;
    }

    cout << endl;
}

int main()
{
    cout << "-----Bienvenido al sistema de votacion en linea------" << endl;

    // Crear una tabla hash para almacenar las opciones y los votos correspondientes
    unordered_map < string, int> votos;

    // Mostrar las opciones de votación disponibles
    cout << "OPCIONES DE VOTACION:" << endl;
    cout << "1. UNIDOS PERU" << endl;
    cout << "2. TODOS JUNTOS" << endl;
    cout << "3. APOYO TOTAL" << endl;
    cout << "4. VOTO NULO" << endl;

    while (true) {
        // Mostrar el menú de votación
        cout << endl;
        cout << "Seleccione una opcion de votacion (1-4) o escriba 'r' para imprimir los resultados:" << endl;
        cout << endl;
        // Leer la opción de votación ingresada por el usuario
        string opcion;
        cin >> opcion;

        // Si el usuario ingresó "r", imprimir los resultados y volver a mostrar el menú de votación
        if (opcion == "r") {
            imprimirResultados(votos);
            continue;
        }

        // Convertir la opción a un número entero
        int opcion_num = stoi(opcion);

        // Verificar que la opción sea válida
        if (opcion_num < 1 || opcion_num > 4) {
            cout << "Opcion invalida Intente de nuevo." << endl;
            continue;
        }

        // Obtener el nombre de la opción correspondiente
        string opcion_nombre;
        switch (opcion_num) {
            case 1:
                opcion_nombre = "UNIDOS PERU";
                break;
            case 2:
                opcion_nombre = "TODOS JUNTOS";
                break;
            case 3:
                opcion_nombre = "APOYO TOTAL";
                break;
            case 4:
                opcion_nombre = "VOTO NULO";
                break;
        }

        // Incrementar el número de votos para la opción seleccionada
        votos[opcion_nombre]++;

        // Mostrar un mensaje de confirmación al usuario
        cout << "Voto registrado para " << opcion_nombre << "." << endl;
    }

    return 0;
}
