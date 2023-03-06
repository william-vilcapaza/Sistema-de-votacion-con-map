#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Funci�n que imprime los resultados de la votaci�n
void imprimirResultados(unordered_map < string, int>& votos)
{
    cout << "Resultados de la votacion: " << endl;

    // Iterar a trav�s de los elementos de la tabla hash y mostrar el nombre de la opci�n y el n�mero de votos
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

    // Mostrar las opciones de votaci�n disponibles
    cout << "OPCIONES DE VOTACION:" << endl;
    cout << "1. UNIDOS PERU" << endl;
    cout << "2. TODOS JUNTOS" << endl;
    cout << "3. APOYO TOTAL" << endl;
    cout << "4. VOTO NULO" << endl;

    while (true) {
        // Mostrar el men� de votaci�n
        cout << endl;
        cout << "Seleccione una opcion de votacion (1-4) o escriba 'r' para imprimir los resultados:" << endl;
        cout << endl;
        // Leer la opci�n de votaci�n ingresada por el usuario
        string opcion;
        cin >> opcion;

        // Si el usuario ingres� "r", imprimir los resultados y volver a mostrar el men� de votaci�n
        if (opcion == "r") {
            imprimirResultados(votos);
            continue;
        }

        // Convertir la opci�n a un n�mero entero
        int opcion_num = stoi(opcion);

        // Verificar que la opci�n sea v�lida
        if (opcion_num < 1 || opcion_num > 4) {
            cout << "Opcion invalida Intente de nuevo." << endl;
            continue;
        }

        // Obtener el nombre de la opci�n correspondiente
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

        // Incrementar el n�mero de votos para la opci�n seleccionada
        votos[opcion_nombre]++;

        // Mostrar un mensaje de confirmaci�n al usuario
        cout << "Voto registrado para " << opcion_nombre << "." << endl;
    }

    return 0;
}
