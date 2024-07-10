#ifndef GESTOR_ASIGNACIONES_H
#define GESTOR_ASIGNACIONES_H

#include <vector>
#include <map>
#include "Empleado.h"
#include "Restaurante.h"

class GestorAsignaciones {
private:
    Restaurante& restaurante;
    std::map<int, std::vector<Empleado>> asignaciones; // Empleados asignados a cada día del mes
    std::map<std::string, int> diasTrabajados; // Contador de días trabajados por empleado

    // Función para mezclar empleados
    void shuffleEmpleados(std::vector<Empleado>& empleados);

    // Función para evaluar la asignación de un día
    bool evaluarAsignacion(const std::vector<Empleado>& asignados);

public:
    GestorAsignaciones(Restaurante& restaurante);

    void asignarEmpleados();
    bool mejorarAsignacion();
    int evaluarSolucion();
    void ejecutarAsignaciones(int iteraciones);
    void imprimirAsignaciones() const;
    std::map<int, std::vector<Empleado>> getAsignaciones();
    void dumpAsignacion();
};

#endif // GESTOR_ASIGNACIONES_H
