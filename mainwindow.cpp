#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include "error.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::reValidate(bool setOnErr)
{
    try{

    auto pStr = make_shared<string>(ui->textBrowser->toPlainText().toStdString());
    auto rez = pnt.validate(pStr);
    if(!rez){
        ui->validateRez->setText(QString::fromStdString(rez.what()));
        if(setOnErr){
            ui->textBrowser->moveCursor(QTextCursor::Start);
            QTextCursor curs = ui->textBrowser->textCursor();
            curs.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, rez.whatStr() - 1);
            curs.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, rez.whatChar() - 1);
            ui->textBrowser->setTextCursor(curs);
        }

    } else
        ui->validateRez->setText("JSON is valid");
    } catch(exception& ex) {QMessageBox::critical(this, "Error", ex.what());}
}

void MainWindow::on_openFile_clicked()
{
    QString fileName = QFileDialog:: getOpenFileName(this, tr("Open File"), "/Users/dmitriiostrometskii/Documents/labs/oop2_parser", "JSON File (*.json)");
    shared_ptr<string> pStr;
    ui->filePath->setText(fileName);
    if(!fileName.isEmpty()) {
        try{
            pnt.setFile(fileName.toStdString());
            pStr = pnt.getDataFromFile();
        } catch(exception& ex) {QMessageBox::critical(this, "Error", ex.what());}

        ui->textBrowser->setText(QString::fromStdString(*pStr));
        ui->textBrowser->setReadOnly(false);
    }
}

void MainWindow::on_textBrowser_textChanged()
{
    try{
        reValidate(false);
    } catch(exception& er){QMessageBox::critical(this, "Error", er.what());}
}






void MainWindow::on_setOnErr_clicked()
{
    reValidate(true);
}

