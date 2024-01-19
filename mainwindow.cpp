#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->pgB_pgBar->setValue(0);
    ui->pgB_pgBar->setRange(0, 100);
    //ui->pgB_pgBar->setValue(20);
    ui->pb_pgBar->setText("ProgressBar");
    ui->pb_pgBar->setChecked(false);


    ui->cbB_list->currentIndex();//возвращает индекс выбранного элемента списка
    ui->cbB_list->currentText();//возвращает текст выбранного элемента списка
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_rb_list1_clicked()
{
    if (ui->cbB_list->count()>0)
        ui->cbB_list->clear();
    if (ui->rb_list1->isChecked() && ui->cbB_list->count()==0){
        for (int i=1; i<= 10; ++i){
            ui->cbB_list->addItem("Element " + QString::number(i));
        }
    }
}


void MainWindow::on_rb_list2_clicked()
{
    if (ui->rb_list2->isChecked()){
        ui->cbB_list->clear();
        for (int i=1; i<= 10; ++i){
            ui->cbB_list->addItem("Элемент " + QString::number(i));
        }
    }
}


void MainWindow::on_pb_pgBar_toggled(bool checked)
{
    int step =10;
    ui->pgB_pgBar->setValue(val+=step);
    if (val > 100){
        ui->pgB_pgBar->reset();
        val =0;
    }
}

