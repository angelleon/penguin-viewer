#include "pgraphicsview.hpp"

PGraphicsView::PGraphicsView(QWidget *parent) : QGraphicsView(parent)
{

}

void PGraphicsView::keyPressEvent(QKeyEvent *event) {
    qDebug() << "Handling key event in graphis view " << event->key();
    QGraphicsView::keyPressEvent(event);
}
