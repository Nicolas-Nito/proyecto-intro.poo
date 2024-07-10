#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <random>
#include <fstream> // Add this line to include the <fstream> header
#include <sstream> // Add this line to include the <sstream> header
#include "Empleado.h"
//Extras para que funcione
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class Restaurante {
private:
    std::vector<Empleado> empleados;

public:
    /*
    void agregarEmpleado(const Empleado& empleado)
    
    Agrega empleados al restaurant
    */
    void agregarEmpleado(const Empleado& empleado) {
        empleados.push_back(empleado);
    }

    /*
    void eliminarEmpleado(const std::string& nombre)
    
    Borra empleados por nombre
    */
    void eliminarEmpleado(const std::string& nombre) {
        empleados.erase(std::remove_if(empleados.begin(), empleados.end(),
            [&nombre](const Empleado& e) { return e.getNombre() == nombre; }), empleados.end());
    }


    /*
    Empleado buscarEmpleado(const std::string& nombre) const
    
    Busca empleados por nombre y lo retorna
    */
    Empleado buscarEmpleado(const std::string& nombre) const {
        auto it = std::find_if(empleados.begin(), empleados.end(),
            [&nombre](const Empleado& e) { return e.getNombre() == nombre; });
        return (it != empleados.end()) ? *it : Empleado("", Rol::PASTELERO, {}, {},"","");
    }

    /*
    std::vector<Empleado> getEmpleados() const
    
    Retorna todos los empleados del restaurant
    */
    std::vector<Empleado>& getEmpleados() { return empleados; }

    /*
    bool verificarDisponibilidad(Rol rol, int dia) const
    
    Verifica si existe disponibilidad del rol "rol" en el dia "dia" de la semana (0-6)
    */
    bool verificarDisponibilidad(Rol rol, int dia) const {
        int count = std::count_if(empleados.begin(), empleados.end(),
            [rol, dia](const Empleado& e) { return e.getRol() == rol && e.getDisponibilidad()[dia]; });
        return count > 0;
    }

    /*
    std::vector<Empleado> obtenerEmpleadosDisponibles(int dia) const
    
    Obtiene los empleados disponibles en el dia "dia" (0-6)
    */
    std::vector<Empleado> obtenerEmpleadosDisponibles(int dia) const {
        std::vector<Empleado> disponibles;
        for (const auto& empleado : empleados) {
            if (empleado.getDisponibilidad()[dia]) {
                disponibles.push_back(empleado);
            }
        }
        return disponibles;
    }

    /*
    void exportarCSV()
    
    Exporta el CSV de empleados
    */
    void exportarCSV() const {
        std::ofstream file("empleados.csv");
        if (file.is_open()) {
            file << "Nombre,Rol,Disponibilidad,Vacaciones\n";
            for (const auto& empleado : empleados) {
                file << empleado.getNombre() << "," << empleado.rolToString() << ",";
                for (bool disponible : empleado.getDisponibilidad()) {
                    file << disponible << " ";
                }
                file << ",";
                for (int dia : empleado.getDiasVacaciones()) {
                    file << dia << " ";
                }
                file << "\n";
            }
            file.close();
        }
    }

    /*
    void importCSV()
    
    Lee el CSV de empleados y añade los empleados al vector del restaurant
    */
    void importCSV() {
        std::ifstream file(":/csv/resorce/empleados.csv");
        if (file.is_open()) {
            std::cout << "Finalizar csv" << std::endl;
            std::string line;
            std::getline(file, line); // Ignorar la primera línea
            while (std::getline(file, line)) {
                std::istringstream ss(line);
                std::string nombre, rol, disponibilidad, vacaciones;
                std::getline(ss, nombre, ',');
                std::getline(ss, rol, ',');
                std::getline(ss, disponibilidad, ',');
                std::getline(ss, vacaciones, ',');
                std::vector<bool> disponibilidadVec;
                std::istringstream ssDisponibilidad(disponibilidad);
                std::string token;
                while (std::getline(ssDisponibilidad, token, ' ')) {
                    disponibilidadVec.push_back(token == "1");
                }
                std::vector<int> vacacionesVec;
                std::istringstream ssVacaciones(vacaciones);
                while (std::getline(ssVacaciones, token, ' ')) {
                    vacacionesVec.push_back(std::stoi(token));
                }
                std::string numero_celular;
                std::getline(ss, numero_celular, ',');
                std::string email;
                std::getline(ss, email, ',');
                agregarEmpleado(Empleado(nombre, Empleado::stringToRol(rol), vacacionesVec, disponibilidadVec,numero_celular,email));
            }
            file.close();
        }
        //Imprimo finalizar csv
        
    }
};



#endif // RESTAURANTE_H
