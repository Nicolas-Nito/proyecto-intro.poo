#include <iostream>
#include <vector>
#include "Empleado.h"
#include "Restaurante.h"

// Función para cargar los empleados desde un CSV
void loadCSV(Restaurante& restaurante){
    restaurante.agregarEmpleado(Empleado("Juan", Rol::COCINERO, {1, 2, 3, 4, 5, 6, 7}, {true, true, true, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Jose", Rol::COCINERO, {8, 9, 10, 11, 12, 13, 14}, {true, true, true, false, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Rosa", Rol::PASTELERO, {15, 16, 17, 18, 19, 20, 21}, {true, true, true, true, false, true, true}));
    restaurante.agregarEmpleado(Empleado("Pepe", Rol::MESERO, {22, 23, 24, 25, 26, 27, 28}, {true, false, true, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Rodrigo", Rol::MANAGER, {29, 30, 31}, {false, true, true, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Joana", Rol::MANAGER, {1, 2, 3, 4, 5, 6, 7}, {true, true, false, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Ana", Rol::COCINERO, {8, 9, 10, 11, 12, 13, 14}, {true, true, true, true, false, true, true}));
    restaurante.agregarEmpleado(Empleado("Luis", Rol::PASTELERO, {15, 16, 17, 18, 19, 20, 21}, {true, true, true, false, true, true, false}));
    restaurante.agregarEmpleado(Empleado("Maria", Rol::MESERO, {22, 23, 24, 25, 26, 27, 28}, {true, true, false, true, true, false, true}));
    restaurante.agregarEmpleado(Empleado("Pedro", Rol::COCINERO, {29, 30, 31}, {true, true, true, true, true, false, true}));

    restaurante.agregarEmpleado(Empleado("Carlos", Rol::MESERO, {1, 2, 3, 4, 5, 6, 7}, {true, true, true, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Laura", Rol::COCINERO, {8, 9, 10, 11, 12, 13, 14}, {true, true, true, false, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Sofia", Rol::PASTELERO, {15, 16, 17, 18, 19, 20, 21}, {true, true, true, true, false, true, true}));
    restaurante.agregarEmpleado(Empleado("Miguel", Rol::MESERO, {22, 23, 24, 25, 26, 27, 28}, {true, false, true, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Isabel", Rol::MANAGER, {29, 30, 31}, {false, true, true, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Jorge", Rol::MANAGER, {1, 2, 3, 4, 5, 6, 7}, {true, true, false, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Elena", Rol::COCINERO, {8, 9, 10, 11, 12, 13, 14}, {true, true, true, true, false, true, true}));
    restaurante.agregarEmpleado(Empleado("Andres", Rol::PASTELERO, {15, 16, 17, 18, 19, 20, 21}, {true, true, true, false, true, true, false}));
    restaurante.agregarEmpleado(Empleado("Gabriela", Rol::MESERO, {22, 23, 24, 25, 26, 27, 28}, {true, true, false, true, true, false, true}));
    restaurante.agregarEmpleado(Empleado("Fernando", Rol::COCINERO, {29, 30, 31}, {true, true, true, true, true, false, true}));

    restaurante.agregarEmpleado(Empleado("Lucia", Rol::PASTELERO, {1, 2, 3, 4, 5, 6, 7}, {true, true, true, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Diego", Rol::MESERO, {8, 9, 10, 11, 12, 13, 14}, {true, true, true, false, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Paula", Rol::COCINERO, {15, 16, 17, 18, 19, 20, 21}, {true, true, true, true, false, true, true}));
    restaurante.agregarEmpleado(Empleado("Alberto", Rol::MESERO, {22, 23, 24, 25, 26, 27, 28}, {true, false, true, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Claudia", Rol::MANAGER, {29, 30, 31}, {false, true, true, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Raul", Rol::MANAGER, {1, 2, 3, 4, 5, 6, 7}, {true, true, false, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Nuria", Rol::COCINERO, {8, 9, 10, 11, 12, 13, 14}, {true, true, true, true, false, true, true}));
    restaurante.agregarEmpleado(Empleado("Victor", Rol::PASTELERO, {15, 16, 17, 18, 19, 20, 21}, {true, true, true, false, true, true, false}));
    restaurante.agregarEmpleado(Empleado("Raquel", Rol::MESERO, {22, 23, 24, 25, 26, 27, 28}, {true, true, false, true, true, false, true}));
    restaurante.agregarEmpleado(Empleado("Manuel", Rol::COCINERO, {29, 30, 31}, {true, true, true, true, true, false, true}));

    restaurante.agregarEmpleado(Empleado("Eva", Rol::MESERO, {1, 2, 3, 4, 5, 6, 7}, {true, true, true, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Hector", Rol::COCINERO, {8, 9, 10, 11, 12, 13, 14}, {true, true, true, false, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Patricia", Rol::PASTELERO, {15, 16, 17, 18, 19, 20, 21}, {true, true, true, true, false, true, true}));
    restaurante.agregarEmpleado(Empleado("Francisco", Rol::MESERO, {22, 23, 24, 25, 26, 27, 28}, {true, false, true, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Gloria", Rol::MANAGER, {29, 30, 31}, {false, true, true, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Eduardo", Rol::MANAGER, {1, 2, 3, 4, 5, 6, 7}, {true, true, false, true, true, true, true}));
    restaurante.agregarEmpleado(Empleado("Alicia", Rol::COCINERO, {8, 9, 10, 11, 12, 13, 14}, {true, true, true, true, false, true, true}));
    restaurante.agregarEmpleado(Empleado("Julio", Rol::PASTELERO, {15, 16, 17, 18, 19, 20, 21}, {true, true, true, false, true, true, false}));
    restaurante.agregarEmpleado(Empleado("Sara", Rol::MESERO, {22, 23, 24, 25, 26, 27, 28}, {true, true, false, true, true, false, true}));
    restaurante.agregarEmpleado(Empleado("Marcos", Rol::COCINERO, {29, 30, 31}, {true, true, true, true, true, false, true}));
    restaurante.agregarEmpleado(Empleado("Marcos2", Rol::PASTELERO, {29, 30, 31}, {true, true, true, true, true, false, true}));
    restaurante.agregarEmpleado(Empleado("Marcos3", Rol::PASTELERO, {29, 30, 31}, {true, true, true, true, true, false, true}));
    restaurante.agregarEmpleado(Empleado("Marcos4", Rol::PASTELERO, {29, 30, 31}, {true, true, true, true, true, false, true}));
    restaurante.agregarEmpleado(Empleado("Marcos5", Rol::PASTELERO, {29, 30, 31}, {true, true, true, true, true, false, true}));

    /* Empleado e1 = Empleado("Jose", Rol::COCINERO, {8, 9, 10, 11, 12, 13, 14}, {true, true, true, false, true, true, true});
    std::cout << e1.toString() << "\n";

    int n = 1;
    //std::vector<int> v = {1,2,3,4,5};
    std::vector<int> v = e1.getDiasVacaciones();
    std::find(e1.getDiasVacaciones().begin(), e1.getDiasVacaciones().end(), n) == std::end(e1.getDiasVacaciones())
            ? std::cout << "v does not contain " << n << '\n'
            : std::cout << "v contains " << n << '\n'; */

};

Rol intToRol(int rol) {
    switch (rol) {
        case 0: return Rol::PASTELERO;
        case 1: return Rol::COCINERO;
        case 2: return Rol::MESERO;
        case 3: return Rol::MANAGER;
        default: return Rol::MESERO;
    }
}

int main() {
    Restaurante restaurante;

    // Cargar empleados desde el CSV
    loadCSV(restaurante);

    int opcion;
    do {
        std::cout << "Sistema de Gestión de Restaurante\n";
        std::cout << "1. Ver lista de empleados\n";
        std::cout << "2. Verificar disponibilidad\n";
        std::cout << "3. Asignar empleados a días del mes\n";
        std::cout << "4. Ver asignaciones\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::vector<Empleado> empleados = restaurante.getEmpleados();
                for (const auto& empleado : empleados) {
                    std::cout << empleado.toString() << std::endl;
                }
                break;
            }
            case 2: {
                int rolInt;
                int dia;
                std::cout << "Ingrese el rol (0 = Pastelero, 1 = Cocinero, 2 = Mesero, 3 = Manager): ";
                std::cin >> rolInt;
                Rol rol = intToRol(rolInt);
                std::cout << "Ingrese el día de la semana (0 = Lunes, ..., 6 = Domingo): ";
                std::cin >> dia;
                if (restaurante.verificarDisponibilidad(rol, dia)) {
                    std::cout << "Hay al menos un " << Empleado::rolToString(rol) << " disponible el día " << dia << ".\n";
                } else {
                    std::cout << "No hay " << Empleado::rolToString(rol) << " disponible el día " << dia << ".\n";
                }
                break;
            }
            case 3:
                restaurante.asignarEmpleados();
                std::cout << "Asignaciones realizadas.\n";
                break;
            case 4:
                restaurante.imprimirAsignaciones();
                break;
            case 5:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opción no válida.\n";
        }
    } while (opcion != 5);

    return 0;
}
