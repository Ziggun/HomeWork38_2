#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionHide,&QAction::triggered,this,&MainWindow::hideView);
    connect(ui->actionShow,&QAction::triggered,this,&MainWindow::showView);
    connect(ui->plainTextEdit,&QPlainTextEdit::textChanged,[&](){
        ui->textBrowser->setHtml(ui->plainTextEdit->toPlainText());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideView()
{
    ui->splitter->setSizes(QList<int>() << ui->splitter->width() << 0);
}

void MainWindow::showView()
{
    ui->splitter->setSizes(QList<int>() << ui->splitter->width() / 2 << ui->splitter->width() / 2 );
}

