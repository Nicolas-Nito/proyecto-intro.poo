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

    /*
    void shuffleEmpleados(std::vector<Empleado>& empleados)
    
    Randomiza el orden del vector de empleados
    */
    void shuffleEmpleados(std::vector<Empleado>& empleados);

    /*
    bool evaluarAsignacion(const std::vector<Empleado>& asignados)
    
    Determina si el dia al que corresponde la asignación esta "completo" o "incompleto"
    */
    bool evaluarAsignacion(const std::vector<Empleado>& asignados);

public:
    GestorAsignaciones(Restaurante& restaurante);

    /*
    void asignarEmpleados()
    
    Asigna los empleados del restaurant a los dias del mes (1-31) con un algoritmo
    GREEDY.
    */
    void asignarEmpleados();
    
    /*
    bool mejorarAsignacion()
    
    Mejora las asignaciones de empleados bajo un algoritmo HILL CLIMBING FIRST IMPROVEMENT
    */
    bool mejorarAsignacion();
    
    /*
    int evaluarSolucion()
    
    Evalua la solución (dias completos asignados)
    */
    int evaluarSolucion();
    
    /*
    vvoid ejecutarAsignaciones(int iteraciones)
    
    Ejecuta las asignaciones de empleados una cantidad "iteraciones" de iteraciones,
    este loop encuentra una solución y la intenta optimizar.
    */
    void ejecutarAsignaciones(int iteraciones);
    
    /*
    void imprimirAsignaciones()
    
    Print de asignaciones en consola
    */
    void imprimirAsignaciones() const;
    
    /*
    std::map<int, std::vector<Empleado>> getAsignaciones()
    
    Retorna las asignaciones
    */
    std::map<int, std::vector<Empleado>> getAsignaciones();
    
    /*
    void dumpAsignacion()
    
    Crea un CSV en base a las asignaciones realizadas
    */
    void dumpAsignacion();
};

#endif // GESTOR_ASIGNACIONES_H
