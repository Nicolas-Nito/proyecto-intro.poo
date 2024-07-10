#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Restaurante.h"
#include "GestorAsignaciones.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void verEmpleados();
    void verDisponibilidad();
    void prepararAsignarEmpleados();
    //void confirmarAsignarEmpleados();
    void verAsignaciones();
    void confirmarVerAsignaciones();


private:
    Ui::MainWindow *ui;
    Restaurante restaurante;
    GestorAsignaciones* gestor;
    void loadCSV();
    Rol intToRol(int rol);
};
#endif // MAINWINDOW_H
