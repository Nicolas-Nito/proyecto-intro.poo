#ifndef EMPLEADOS_H
#define EMPLEADOS_H
#include <iostream>
#include <vector>

using namespace std;

enum class Rol
{
    cocinero,
    pastelero,
    mesero,
    manager
};

class Empleado
{
    private:
        /* data */
        int id;
        string nombre;
        double salario;
        vector<bool> disponibilidad;
        int vacacionesDisponibles;
        Rol rol;

    public:
        Empleado(int id, string nombre, double salario, vector<bool> disponibilidad, int vacacionesDisponibles, Rol rol){
            this->id = id;
            this->nombre = nombre;
            this->salario = salario;
            this->disponibilidad = disponibilidad;
            this->vacacionesDisponibles = vacacionesDisponibles;
            this->rol = rol;
        };

        void getEmpleado()
        {
            cout << "ID: " << id << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Salario: " << salario << endl;
            cout << "Disponibilidad: ";
            for (long unsigned int i = 0; i < disponibilidad.size(); i++)
            {
                cout << disponibilidad[i] << " ";
            }
            cout << endl;
            cout << "Vacaciones Disponibles: " << vacacionesDisponibles << endl;
        }
    };




#endif