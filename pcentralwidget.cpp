#include "pcentralwidget.hpp"

PCentralWidget::PCentralWidget(QWidget *parent) :
    QWidget(parent)
{
}

PCentralWidget::~PCentralWidget()
{
}

void PCentralWidget::keyPressEvent(QKeyEvent *event) {
    qDebug() << "Handling event in central widget";
    QWidget::keyPressEvent(event);
}
