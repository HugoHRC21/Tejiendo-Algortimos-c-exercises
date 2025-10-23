#include <iostream>

class ArregloND {
private:
    int* datos;
    int* dimensiones;
    int totalElementos;
    int nDimensiones;

    int calcularIndice(const int* indices) const {
        int indice = 0;
        int multiplicador = 1;
        for (int i = nDimensiones - 1; i >= 0; --i) {
            indice += indices[i] * multiplicador;
            multiplicador *= dimensiones[i];
        }
        return indice;
    }

public:
    // Constructor
    ArregloND(int n, int* dims) : nDimensiones(n) {
        dimensiones = new int[nDimensiones];
        totalElementos = 1;

        for (int i = 0; i < nDimensiones; ++i) {
            dimensiones[i] = dims[i];
            totalElementos *= dims[i];
        }

        datos = new int[totalElementos]();
    }

    // Destructor
    ~ArregloND() {
        delete[] datos;
        delete[] dimensiones;
    }

    // Acceso a elementos
    int& operator[](const int* indices) {
        return datos[calcularIndice(indices)];
    }

    // Mostrar elementos
    void mostrar() const {
        for (int i = 0; i < totalElementos; ++i) {
            std::cout << datos[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int dimensiones[] = {2, 3, 4}; // Definición de dimensiones
    ArregloND arreglo(3, dimensiones); // Crear arreglo 2x3x4

    int indices[] = {0, 1, 2};
    arreglo[indices] = 5; // Asignar valor
    arreglo.mostrar(); // Mostrar datos

    return 0;
}