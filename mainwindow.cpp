#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setStyleSheet("background-color: black;");
    int gridRow = 8;
    int gridCol = 16;
    QGridLayout* tempGrid = new QGridLayout();
    ui->gridGame->addLayout(tempGrid,gridRow-1,gridCol-1);


}

void MainWindow::addTile(QPixmap* texturePath)
{
    QLabel* label = new QLabel();
    label->setPixmap(*texturePath);
    label->setMinimumSize(64,64);
    label->setScaledContents(true);
    ui->gridGame->addWidget(label);
    label->show();



}

MainWindow::~MainWindow()
{
    delete ui;
}
