#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <memory>
#include <string>
#include "syntaxvalidator.h"
#include "entrypoint.h"

using std::shared_ptr;
using std::make_shared;
using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_openFile_clicked();
    void on_textBrowser_textChanged();
    void on_save_clicked();
    void on_setOnErr_clicked();

private:
    Ui::MainWindow *ui;
    entryPoint pnt;
};
#endif // MAINWINDOW_H
