#include <iostream>
#include <cstdlib> // generar números aleatorios
#include <ctime>   // "semilla aleatoria"


using namespace std;

int main() {
    // no sirve :v std::locale::global(std::locale("en_US.UTF-8"));

    // "semilla aleatoria para los números aleatorios"
    srand(time(0));

    //  número secreto entre 1 y 100
    int numeroSecreto = rand() % 100 + 1;

    int intento;
    // PONER NIVELES DE DIFICULTAD- N.INTENTOS
    int intentosRestantes = 7;

    cout << "Bienvenido al juego de adivinar el número!\n";
    cout << "Tienes 7 intentos para adivinar el número secreto.\n";

    while (intentosRestantes > 0) {
        cout << "Ingresa tu intento: ";
        cin >> intento;

        if (intento == numeroSecreto) {
            cout << "¡Felicidades! Adivinaste el número secreto!\n";
            break;
        } else if (intento < numeroSecreto) {
            cout << "El número secreto es mayor que " << intento << ".\n";
        } else {
            cout << "El número secreto es menor que " << intento << ".\n";
        }

        cout << "Intentos restantes: " << --intentosRestantes << endl;
    }

    if (intentosRestantes == 0) {
        cout << "Lo siento, has agotado tus intentos. El número secreto era: " << numeroSecreto << endl;
    }

    return 0;
}