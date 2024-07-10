# Sistema de Gestión de Empleados para Restaurante

Este es un proyecto de QT que implementa un sistema de gestión de empleados para un restaurante. La aplicación permite gestionar la información de los empleados, incluyendo su nombre, rol, días de vacaciones y disponibilidad. Además, permite asignar empleados a turnos de trabajo y optimizar la asignación de personal.

## Requisitos

Para compilar y ejecutar este proyecto necesitas:

- Qt 5.15 o superior (puedes descargarlo desde [aquí](https://www.qt.io/download-qt-installer))
- CMake 3.10 o superior
- Un compilador compatible con C++11 (por ejemplo, GCC, Clang, MSVC)

## Instalación

### Paso 1: Clonar el repositorio

```bash
git clone https://github.com/Nicolas-Nito/proyecto-intro.poo
cd proyecto-intro.poo
```
### Paso 2: Configurar el entorno de QT

Asegúrate de tener configurado el entorno de QT en tu sistema. Puedes hacer esto añadiendo el binario de QT a tu PATH o usando QT Creator, que configura automáticamente el entorno por ti.

### Paso 3: Compilar el proyecto
Si estás usando Qt Creator:

- Abre Qt Creator.
- Selecciona File > Open File or Project... y selecciona el archivo CMakeLists.txt de tu proyecto.
- Configura el proyecto seleccionando el kit de compilación apropiado.
- Haz clic en Configure Project.
- Una vez configurado, haz clic en el botón de Build para compilar el proyecto.

## Uso
Se debe proporcionar un archivo "empleados.csv" en el root del directorio. 
Una vez que la aplicación esté en ejecución, puedes:

- Ver la lista de empleados
- Verificar disponibilidad un dia.
- Asignar empleados a cada dia según su disponibilidad
- Ver la asignación obtenida
