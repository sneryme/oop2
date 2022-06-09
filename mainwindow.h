#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "region.h"
#include "model.h"
#include "read_file.h"
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QMainWindow>
#include "sort.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_create_table_clicked();
    void on_btn_check_stolb_clicked();

private:
    QList<Region>* list;
    read_file* rfile;
    Sort* ssort;
    Model *model;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
