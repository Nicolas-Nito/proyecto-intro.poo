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
    QFile file(":/csv/empleados.csv");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo CSV");
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine(); // Ignorar la primera línea

    while (!in.atEnd()) {
        line = in.readLine();
        QStringList fields = line.split(',');

        if (fields.size() < 6) continue; // Asegurarse de que haya suficientes campos

        QString nombre = fields.at(0);
        QString rol = fields.at(1);
        QString disponibilidad = fields.at(2);
        QString vacaciones = fields.at(3);
        QString numero_celular = fields.at(4);
        QString email = fields.at(5);

        std::vector<bool> disponibilidadVec;
        QStringList disponibilidadTokens = disponibilidad.split(' ');
        for (const QString& token : disponibilidadTokens) {
            disponibilidadVec.push_back(token == "1");
        }

        std::vector<int> vacacionesVec;
        QStringList vacacionesTokens = vacaciones.split(' ');
        for (const QString& token : vacacionesTokens) {
            vacacionesVec.push_back(token.toInt());
        }

        restaurante.agregarEmpleado(Empleado(nombre.toStdString(), Empleado::stringToRol(rol.toStdString()), vacacionesVec, disponibilidadVec, numero_celular.toStdString(), email.toStdString()));
    }

    file.close();
    //QMessageBox::information(this, "Importación", "Archivo CSV importado exitosamente");

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
            asignacionesStr += QString::fromStdString(empleado.getNombre()) + " (" + QString::fromStdString(empleado.rolToString()) + "), contacto: " + QString::fromStdString(empleado.getNumeroCelular()) + " | " + QString::fromStdString(empleado.getCorreoElectronico()) + "\n";
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
