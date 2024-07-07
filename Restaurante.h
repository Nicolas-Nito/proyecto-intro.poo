#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "Empleado.h"

#define MAX_DAYS 3 // Definimos el máximo de días que un empleado puede trabajar en el mes

class Restaurante {
private:
    std::vector<Empleado> empleados;
    std::map<int, std::vector<Empleado>> asignaciones; // Empleados asignados a cada día del mes
    std::map<std::string, int> diasTrabajados; // Contador de días trabajados por empleado

public:
    void agregarEmpleado(const Empleado& empleado) {
        empleados.push_back(empleado);
    }

    void eliminarEmpleado(const std::string& nombre) {
        empleados.erase(std::remove_if(empleados.begin(), empleados.end(),
            [&nombre](const Empleado& e) { return e.getNombre() == nombre; }), empleados.end());
    }

    Empleado buscarEmpleado(const std::string& nombre) const {
        auto it = std::find_if(empleados.begin(), empleados.end(),
            [&nombre](const Empleado& e) { return e.getNombre() == nombre; });
        return (it != empleados.end()) ? *it : Empleado("", Rol::PASTELERO, {}, {});
    }

    std::vector<Empleado> getEmpleados() const { return empleados; }

    bool verificarDisponibilidad(Rol rol, int dia) const {
        int count = std::count_if(empleados.begin(), empleados.end(),
            [rol, dia](const Empleado& e) { return e.getRol() == rol && e.getDisponibilidad()[dia]; });
        return count > 0;
    }

    std::vector<Empleado> obtenerEmpleadosDisponibles(int dia) const {
        std::vector<Empleado> disponibles;
        for (const auto& empleado : empleados) {
            if (empleado.getDisponibilidad()[dia]) {
                disponibles.push_back(empleado);
            }
        }
        return disponibles;
    }

    void asignarEmpleados() {
        asignaciones.clear();
        diasTrabajados.clear();
        for (int dia = 1; dia <= 31; ++dia) { // Si quisieramos cambiar la cantidad de dias, asignar el 31 como variable
            std::vector<Empleado> asignados;
            std::vector<Empleado> disponibles = obtenerEmpleadosDisponibles((dia - 1) % 7); // Obtiene por dia de la semana [0 - 6]
            for (const auto& rol : {Rol::PASTELERO, Rol::COCINERO, Rol::MESERO, Rol::MANAGER}) {
                int requeridos = (rol == Rol::MESERO) ? 3 : 1; // CANTIDAD POR ROL , CAMBIAR ?
                int count = 0;
                for (const auto& empleado : disponibles) {
                    std::vector<int> vacaciones = empleado.getDiasVacaciones();
                    if (empleado.getRol() == rol && 
                        std::find(vacaciones.begin(), vacaciones.end(), dia) == vacaciones.end() &&
                        diasTrabajados[empleado.getNombre()] < MAX_DAYS) { // Cumple rol , no está de vacaciones y no ha trabajado MAX_DAYS dias.
                        asignados.push_back(empleado);
                        diasTrabajados[empleado.getNombre()]++;
                        count++;
                        if (count == requeridos) break;
                    }
                }
                if (count < requeridos) {
                    std::cout << "No hay suficientes " << Empleado::rolToString(rol) << " disponibles para el día " << dia << ".\n";
                }
            }
            asignaciones[dia] = asignados;
        }
    }

    void imprimirAsignaciones() const {
        for (const auto& asignacion : asignaciones) {
            std::cout << "Día " << asignacion.first << ": ";
            for (const auto& empleado : asignacion.second) {
                std::cout << empleado.getNombre() << " (" << empleado.rolToString() << "), ";
            }
            std::cout << "\n";
        }
    }
};

#endif // RESTAURANTE_H
