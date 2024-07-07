#include "Empleado.h"

int main()
{
    Empleado empleado1(1, "Juan", 1000, {true, true, true, true, true, true, true}, 10, Rol::cocinero);
    empleado1.getEmpleado();

    return 0;
}