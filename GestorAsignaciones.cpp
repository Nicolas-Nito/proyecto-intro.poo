#include "GestorAsignaciones.h"
#include <algorithm>
#include <random>
#include <iostream>

GestorAsignaciones::GestorAsignaciones(Restaurante& restaurante)
    : restaurante(restaurante) {}

void GestorAsignaciones::shuffleEmpleados(std::vector<Empleado>& empleados) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(empleados.begin(), empleados.end(), g);
}

bool GestorAsignaciones::evaluarAsignacion(const std::vector<Empleado>& asignados) {
    std::map<Rol, int> conteo;
    for (const auto& empleado : asignados) {
        conteo[empleado.getRol()]++;
    }
    return conteo[Rol::PASTELERO] >= 1 && conteo[Rol::COCINERO] >= 1 && conteo[Rol::MESERO] >= 3 && conteo[Rol::MANAGER] >= 1;
}

void GestorAsignaciones::asignarEmpleados() {
    asignaciones.clear();
    diasTrabajados.clear();
    for (int dia = 1; dia <= 31; ++dia) {
        std::vector<Empleado> asignados;
        std::vector<Empleado> disponibles = restaurante.obtenerEmpleadosDisponibles((dia - 1) % 7);
        for (const auto& rol : {Rol::PASTELERO, Rol::COCINERO, Rol::MESERO, Rol::MANAGER}) {
            int requeridos = (rol == Rol::MESERO) ? 3 : 1;
            int count = 0;
            for (const auto& empleado : disponibles) {
                std::vector<int> vacaciones = empleado.getDiasVacaciones();
                if (empleado.getRol() == rol && 
                    std::find(vacaciones.begin(), vacaciones.end(), dia) == vacaciones.end() &&
                    diasTrabajados[empleado.getNombre()] < MAX_DAYS) {
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

bool GestorAsignaciones::mejorarAsignacion() {
    // Intentar intercambiar empleados asignados con empleados no asignados para mejorar
    for (int dia = 1; dia <= 31; ++dia) {
        auto& empleadosAsignados = asignaciones[dia];
        for (size_t i = 0; i < empleadosAsignados.size(); ++i) {
            Empleado& empleadoAsignado = empleadosAsignados[i];
            std::vector<Empleado> restauranteEmpleados = restaurante.getEmpleados();
            for (auto& empleado : restauranteEmpleados) {
                std::vector<int> vacaciones = empleado.getDiasVacaciones();
                if (empleado.getRol() == empleadoAsignado.getRol() && empleado.getNombre() != empleadoAsignado.getNombre() && // Mismo rol, distinto empleado
                    std::find(empleadosAsignados.begin(), empleadosAsignados.end(), empleado) == empleadosAsignados.end() && // No asignado a este dia
                    diasTrabajados[empleado.getNombre()] < MAX_DAYS && diasTrabajados[empleadoAsignado.getNombre()] > 0 && 
                    empleado.getDisponibilidad()[(dia - 1) % 7] &&
                    std::find(vacaciones.begin(), vacaciones.end(), dia) == vacaciones.end()) { // Empleado disponible para cubrir
                    
                    // Intentar asignar el empleadoAsignado a un día incompleto (swap)
                    bool asignado = false;
                    for (int diaIncompleto = 1; diaIncompleto <= 31; ++diaIncompleto) {
                        if (diaIncompleto == dia) continue; // Evitar reasignar al mismo día
                        auto& asignacionIncompleta = asignaciones[diaIncompleto];
                        int requeridos = (empleadoAsignado.getRol() == Rol::MESERO) ? 3 : 1;
                        int count = std::count_if(asignacionIncompleta.begin(), asignacionIncompleta.end(),
                            [rol = empleadoAsignado.getRol()](const Empleado& e) { return e.getRol() == rol; });
                        std::vector<int> vacacionesAsignado = empleadoAsignado.getDiasVacaciones();
                        if (count < requeridos && // Faltan del Rol
                            std::find(asignacionIncompleta.begin(), asignacionIncompleta.end(), empleadoAsignado) == asignacionIncompleta.end() && // No asignado a este día
                            empleadoAsignado.getDisponibilidad()[(diaIncompleto - 1) % 7] && // Disponibilidad del empleado para este día
                            std::find(vacacionesAsignado.begin(), vacacionesAsignado.end(), diaIncompleto) == vacacionesAsignado.end()  // No está de vacaciones ese día
                            ) {
                            
                            // Asignar el empleadoAsignado al día incompleto
                            asignacionIncompleta.push_back(empleadoAsignado);

                            // Guardar cambios y retornar true
                            asignado = true;
                            break;
                        }
                    }

                    // Revertir el cambio si no se mejora
                    if (!asignado) {
                        continue; // No revertir porque no se hizo ningún cambio
                    } else {
                        // Actualizar la asignación original con el empleado disponible
                        diasTrabajados[empleado.getNombre()]++;
                        empleadosAsignados[i] = empleado;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int GestorAsignaciones::evaluarSolucion() {
    int diasCompletos = 0;
    for (const auto& asignacion : asignaciones) {
        if (evaluarAsignacion(asignacion.second)) {
            diasCompletos++;
        }
    }
    return diasCompletos;
}

void GestorAsignaciones::ejecutarAsignaciones(int iteraciones) {
    int mejorDiasCompletos = 0;
    std::map<int, std::vector<Empleado>> mejorAsignaciones;

    for (int i = 0; i < iteraciones; ++i) {
        shuffleEmpleados(restaurante.getEmpleados());
        asignarEmpleados();
        while (mejorarAsignacion()) {} // Intentar mejorar la asignación
        int diasCompletos = evaluarSolucion();
        if (diasCompletos > mejorDiasCompletos) {
            mejorDiasCompletos = diasCompletos;
            mejorAsignaciones = asignaciones;
            if (mejorDiasCompletos == 31) {
                break; // Encontramos la solución óptima
            }
        }
    }
    asignaciones = mejorAsignaciones;
    std::cout << "Mejor solución: " << mejorDiasCompletos << " días completos.\n";
}

void GestorAsignaciones::imprimirAsignaciones() const {
    for (const auto& asignacion : asignaciones) {
        std::cout << "Día " << asignacion.first << ": ";
        for (const auto& empleado : asignacion.second) {
            std::cout << empleado.getNombre() << " (" << empleado.rolToString() << "), ";
        }
        std::cout << "\n";
    }
}

std::map<int, std::vector<Empleado>> GestorAsignaciones::getAsignaciones() const {
    return asignaciones;
}

void GestorAsignaciones::dumpAsignacion(){
    std::ofstream file("asignaciones.csv");
    if (file.is_open()) {
        file << "Dia,Nombre,Rol\n";
        for (const auto& asignacion : asignaciones) {
            for (const auto& empleado : asignacion.second) {
                file << asignacion.first << "," << empleado.getNombre() << "," << empleado.rolToString() << "\n";
            }
        }
        file.close();
    }
}