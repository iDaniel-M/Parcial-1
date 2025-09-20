#include <iostream>

// Definir la estructura de una nota (Grade)
struct Grade {
    int studentId;
    float grade;
};

// Función para leer las coordenadas de varias notas
void leerNotas(Grade notas[], int n)
{
    char respuesta;

    // Validar hasta que el usuario escriba 's' o 'n'
    do {
        std::cout << "¿Desea ingresar las notas manualmente? (s/n): ";
        std::cin >> respuesta;

        if (respuesta != 's' && respuesta != 'n') {
            std::cout << "Error: la respuesta debe ser 's' o 'n'.\n";
        }

    }

    if (respuesta == 's')
    {
        // Leer los datos de cada estudiante por separado
        for (int i = 0; i < n; i++)
        {
            std::cout << "\nEstudiante " << i + 1 << ":\n";

            std::cout << "Ingrese el ID del estudiante: ";
            std::cin >> notas[i].studentId;

            std::cout << "Ingrese la nota del estudiante (0.0 - 5.0): ";
            std::cin >> notas[i].grade;

            // Validar rango de la nota
            while (notas[i].grade < 0.0 || notas[i].grade > 5.0)
            {
                std::cout << "Error: la nota debe estar entre 0.0 y 5.0. Intente de nuevo: ";
                std::cin >> notas[i].grade;
            }
        }
    }
    else // respuesta == 'n'
    {
        // Usar valores predeterminados
        std::cout << "Usando valores predeterminados...\n";
        if (n >= 4) {
            notas[0] = {1010, 3.0};
            notas[1] = {1020, 4.0};
            notas[2] = {1030, 2.5};
            notas[3] = {2056, 5.0};
        }
    }
}

// Función para calcular el promedio y obtener la nota más alta
double calcularPromedio(Grade notas[], int n, int &indiceNotaMasAlta)
{
    double suma = 0.0;
    indiceNotaMasAlta = 0;

    for (int i = 0; i < n; i++)
    {
        suma += notas[i].grade;
        if (notas[i].grade > notas[indiceNotaMasAlta].grade)
        {
            indiceNotaMasAlta = i;
        }
    }

    return suma / n;
}

// Función para mostrar los resultados
void mostrarResultado(Grade notas[], int indiceNotaMasAlta, double promedio)
{
    std::cout << "\nEl promedio de las notas es: " << promedio << std::endl;
    std::cout << "El id del estudiante con mejor calificación es: "
              << notas[indiceNotaMasAlta].studentId
              << ", con una nota de " << notas[indiceNotaMasAlta].grade
              << std::endl;
}

int main()
{
    int n;

    std::cout << "Ingrese la cantidad de notas (mínimo 2): ";
    std::cin >> n;

    if (n < 2)
    {
        std::cout << "Error: debe ingresar al menos 2 notas." << std::endl;
        return 1;
    }

    Grade *notas = new Grade[n]; // Arreglo dinámico

    leerNotas(notas, n);

    int indiceNotaMasAlta;
    double promedio = calcularPromedio(notas, n, indiceNotaMasAlta);

    mostrarResultado(notas, indiceNotaMasAlta, promedio);

    delete[] notas; // Liberar memoria
    return 0;
}
