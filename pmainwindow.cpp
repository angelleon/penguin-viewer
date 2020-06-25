#include "pmainwindow.hpp"
#include "ui_penguinviewer.h"

PenguinViewer::PenguinViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PenguinViewer)
{
    ui->setupUi(this);
    PGraphicsView *gv =new PGraphicsView(this);
    //QGraphicsView *prevGv = ui->graphicsView;
    //ui->centralWidget->layout()->replaceWidget(ui->graphicsView, gv);
            //removeWidget(ui->graphicsView);
    //ui->graphicsView = gv;
    //prevGv->deleteLater();

    QWidget *prevCW = ui->centralWidget;
    ui->centralWidget = new PCentralWidget(this);
    ui->centralWidget->setLayout(new QVBoxLayout(ui->centralWidget));
    ui->centralWidget->layout()->addWidget(gv);
    prevCW->deleteLater();
    //ui->centralWidget
    //connect(ui->actionOpen, &QAction::triggered, )
}

PenguinViewer::~PenguinViewer()
{
    delete ui;
}

QAction *PenguinViewer::actionOpen() {
    return ui->actionOpen;
}

QAction *PenguinViewer::actionNext() {
    return ui->actionNext;
}

QAction *PenguinViewer::actionPrev() {
    return ui->actionPrev;
}

QAction *PenguinViewer::actionQuit() {
    return ui->actionClose;
}

void PenguinViewer::sltRefreshView(QGraphicsScene *scene) {
    ui->graphicsView->setScene(scene);
}

void PenguinViewer::keyPressEvent(QKeyEvent *event) {
    auto key = event->key();
    if (key == Qt::Key::Key_P || key == Qt::Key::Key_Left) {
        ui->actionPrev->activate(QAction::Trigger);
    }
    if (key == Qt::Key::Key_N || key == Qt::Key::Key_Right) {
        ui->actionNext->activate(QAction::Trigger);
    }
    qDebug() << "Handling key event in window";
    QMainWindow::keyPressEvent(event);
}

QSize PenguinViewer::renderSize() {
    return ui->graphicsView->size();
}
