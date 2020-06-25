#include "pmainwindow.hpp"
#include "ui_pmainwindow.h"

PMainWindow::PMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PMainWindow)
{
    ui->setupUi(this);
    PGraphicsView *gv =new PGraphicsView(this);
    QGraphicsView *prevGv = ui->graphicsView;
    ui->centralWidget->layout()->replaceWidget(ui->graphicsView, gv);
            //removeWidget(ui->graphicsView);
    ui->graphicsView = gv;
    prevGv->deleteLater();

    /*
    QWidget *prevCW = ui->centralWidget;
    ui->centralWidget = new PCentralWidget(this);
    ui->centralWidget->setLayout(new QVBoxLayout(ui->centralWidget));
    ui->centralWidget->layout()->addWidget(gv);
    prevCW->deleteLater();
    */
}

PMainWindow::~PMainWindow()
{
    delete ui;
}

QAction *PMainWindow::actionOpen() {
    return ui->actionOpen;
}

QAction *PMainWindow::actionNext() {
    return ui->actionNext;
}

QAction *PMainWindow::actionPrev() {
    return ui->actionPrev;
}

QAction *PMainWindow::actionQuit() {
    return ui->actionClose;
}

void PMainWindow::sltRefreshView(QGraphicsScene *scene) {
    ui->graphicsView->setScene(scene);
    //ui->graphicsView->
}

void PMainWindow::keyPressEvent(QKeyEvent *event) {
    auto key = event->key();
    if (key == Qt::Key::Key_P || key == Qt::Key::Key_Left) {
        ui->actionPrev->activate(QAction::Trigger);
    }
    if (key == Qt::Key::Key_N || key == Qt::Key::Key_Right) {
        ui->actionNext->activate(QAction::Trigger);
    }
    qDebug() << "Handling key event in window: " << event->text();
    QMainWindow::keyPressEvent(event);
}

QSize PMainWindow::renderSize() {
    return ui->graphicsView->size();
}
