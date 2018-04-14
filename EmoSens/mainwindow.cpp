#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "datacollectiondialog.h"
#include "visualizedialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->recognitionButton->setVisible(false);
    //ui->trainButton->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dataCollectButton_clicked()
{
    QString ip = ui->ipEdit->text();
    qDebug() <<ip;

    DataCollectionDialog *d = new DataCollectionDialog(this, ip);
    d->show();
}

void MainWindow::on_visualizationButton_clicked()
{
    visualizeDialog *v = new visualizeDialog(this);
    v->show();
}
