#include <iostream>
#include <windows.h>

// Función para mover el cursor en la consola a la posición (x, y)
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Clase que representa un cuadrado
class Cuadrado {
private:
    // Representación del cuadrado
    char shape[2][3] = {
        {'*', '*', '*'},
        {'*', '*', '*'}
    };

    // Coordenadas (x, y) del cuadrado en la consola
    int x, y;

public:
    // Constructor que inicializa las coordenadas del cuadrado
    Cuadrado(int startX, int startY) : x(startX), y(startY) {}

    // Método para dibujar el cuadrado en la consola
    void imprimirCuadrado() const {
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 3; col++) {
                gotoxy(x + col, y + row);
                std::cout << shape[row][col];
            }
        }
    }

    // Método para mover el cuadrado, cambiando sus coordenadas
    void mover(int deltaX, int deltaY) {
        x += deltaX;
        y += deltaY;
    }

    // Métodos para obtener las coordenadas actuales del cuadrado
    int getX() const { return x; }
    int getY() const { return y; }
};

// Clase principal del juego
class Game {
private:
    Cuadrado cuadrado;         // Objeto del jugador (el cuadrado)
    bool terminarPrograma;            // Indica si el juego está en ejecución

    // Método para procesar la entrada del usuario
    void processInput() {
        char direction = getchar();
        switch (direction) {
        case 'a':               // Mover el cuadrado a la izquierda
            cuadrado.mover(-1, 0);
            break;
        case 'w':               // Mover el cuadrado hacia arriba
            cuadrado.mover(0, -1);
            break;
        case 's':               // Mover el cuadrado hacia abajo
            cuadrado.mover(0, 1);
            break;
        case 'd':               // Mover el cuadrado a la derecha
            cuadrado.mover(1, 0);
            break;
        case 'e':               // Salir del juego
            terminarPrograma = false;
            break;
        }
    }

    // Método para renderizar/dibujar el juego en la consola
    void render() const {
        system("cls");  // Limpia la consola
        cuadrado.imprimirCuadrado();  // Dibuja el cuadrado en su nueva posición
    }

public:
    // Constructor que inicializa el juego
    Game() : cuadrado(56, 13), terminarPrograma(true) {}

    // Método principal del juego que ejecuta el bucle del juego
    void run() { //Gameloop
        while (terminarPrograma) {
            processInput();  // Procesar y Actualizar la entrada del usuario
            render();        // Dibujar el juego en la consola
        }
    }
};

// Función principal que inicia el juego
int main() {
    Game game;  // Crea una instancia del juego
    game.run(); // Inicia el bucle principal del juego
    return 0;
}
