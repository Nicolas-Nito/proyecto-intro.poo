#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>

enum class Rol {
    PASTELERO,
    COCINERO,
    MESERO,
    MANAGER
};

class Empleado {
private:
    std::string nombre;
    Rol rol;
    std::vector<int> diasVacaciones; // Días del mes  en los que el empleado tomará vacaciones (1-31)
    std::vector<bool> disponibilidad; // Disponibilidad para cada día de la semana
    std::string numero_celular;
    std::string correo_electronico;

public:
    Empleado(const std::string& nombre, Rol rol, const std::vector<int>& diasVacaciones, const std::vector<bool>& disponibilidad, const std::string& numero_celular, const std::string& correo_electronico)
        : nombre(nombre), rol(rol), diasVacaciones(diasVacaciones), disponibilidad(disponibilidad), numero_celular(numero_celular), correo_electronico(correo_electronico) {}

    std::string getNombre() const { return nombre; }
    Rol getRol() const { return rol; }
    std::vector<int> getDiasVacaciones() const { return diasVacaciones; }
    std::vector<bool> getDisponibilidad() const { return disponibilidad; }
    std::string getNumeroCelular() const { return numero_celular; }
    std::string getCorreoElectronico() const { return correo_electronico; }

    void setNombre(const std::string& nombre) { this->nombre = nombre; }
    void setRol(Rol rol) { this->rol = rol; }
    void setDiasVacaciones(const std::vector<int>& diasVacaciones) { this->diasVacaciones = diasVacaciones; }
    void setDisponibilidad(const std::vector<bool>& disponibilidad) { this->disponibilidad = disponibilidad; }

    std::string toString() const {
        std::string diasVacacionesStr;
        for (int dia : diasVacaciones) {
            diasVacacionesStr += std::to_string(dia) + " ";
        }
        return nombre + " - " + rolToString() + " - Días de vacaciones: " + diasVacacionesStr;
    }

    std::string rolToString() const {
        return rolToString(rol);
    }

    static std::string rolToString(Rol rol) {
        switch (rol) {
            case Rol::PASTELERO: return "Pastelero";
            case Rol::COCINERO: return "Cocinero";
            case Rol::MESERO: return "Mesero";
            case Rol::MANAGER: return "Manager";
            default: return "Desconocido";
        }
    }
    
    bool operator==(const Empleado& other) const {
        return nombre == other.nombre && rol == other.rol;
    }
    
    static Rol stringToRol(const std::string& rol) {
        if (rol == "Pastelero") return Rol::PASTELERO;
        if (rol == "Cocinero") return Rol::COCINERO;
        if (rol == "Mesero") return Rol::MESERO;
        if (rol == "Manager") return Rol::MANAGER;
        return Rol::MESERO;
    }
};

#endif // EMPLEADO_H
