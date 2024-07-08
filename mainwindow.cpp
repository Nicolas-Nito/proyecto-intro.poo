#include "mainwindow.h"
#include "./ui_mainwindow.h"

//Agregados
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar botones con funciones
    connect(ui->btnVerEmpleados, &QPushButton::clicked, this, &MainWindow::verEmpleados);
    connect(ui->btnVerDisponibilidad, &QPushButton::clicked, this, &MainWindow::verDisponibilidad);
    connect(ui->btnAsignarEmpleados, &QPushButton::clicked, this, &MainWindow::prepararAsignarEmpleados);
    //connect(ui->btnConfirmarAsignacion, &QPushButton::clicked, this, &MainWindow::confirmarAsignarEmpleados);
    connect(ui->btnVerAsignaciones, &QPushButton::clicked, this, &MainWindow::verAsignaciones);
    connect(ui->btnConfirmarDiaAsignacion, &QPushButton::clicked, this, &MainWindow::confirmarVerAsignaciones);
    connect(ui->btnSalir, &QPushButton::clicked, this, &QMainWindow::close);

    loadCSV();
    restaurante.ejecutarAsignaciones(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadCSV()
{
    // Aquí iría tu lógica para cargar los empleados desde el CSV
    // La puedes adaptar directamente de tu función existente
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

}


void MainWindow::verEmpleados()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->listWidgetEmpleados->clear();
    for (const auto& empleado : restaurante.getEmpleados()) {
        ui->listWidgetEmpleados->addItem(QString::fromStdString(empleado.toString()));
    }
}

void MainWindow::verDisponibilidad()
{
    ui->stackedWidget->setCurrentIndex(1);
    int rolIndex = ui->comboRol->currentIndex();
    Rol rol = intToRol(rolIndex);
    int dia = ui->comboDia->currentIndex();

    bool disponible = restaurante.verificarDisponibilidad(rol, dia);
    QString message = disponible ? "Disponible" : "No disponible";
    ui->textVerificarDisp->setText(message);
}

void MainWindow::prepararAsignarEmpleados()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->textAsignacionesResult->setText("Asignaciones realizadas.");
}



void MainWindow::verAsignaciones()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::confirmarVerAsignaciones()
{
    int dia = ui->spinBoxDiaAsignacion->value();
    auto asignaciones = restaurante.getAsignaciones();
    if (asignaciones.find(dia) != asignaciones.end()) {
        QString asignacionesStr;
        //asignacionesStr += "Día " + QString::number(dia) + ": ";
        for (const auto& empleado : asignaciones[dia]) {
            //TODO: NICO AQUI PUEDES CAMBIAR LO QUE SE MUESTRA EN LOS TRABAJADORES ASIGNADOS
            asignacionesStr += QString::fromStdString(empleado.getNombre()) + " (" + QString::fromStdString(empleado.rolToString()) + ")\n";
        }
        ui->listWidgetAsignaciones->setText(asignacionesStr);
    } else {
        ui->listWidgetAsignaciones->setText("No hay asignaciones para el día seleccionado.");
    }
}


//Extras
Rol MainWindow::intToRol(int rol) {
    switch (rol) {
        case 0: return Rol::PASTELERO;
        case 1: return Rol::COCINERO;
        case 2: return Rol::MESERO;
        case 3: return Rol::MANAGER;
        default: return Rol::MESERO;
    }
}
