#include "pgraphicsview.hpp"

PGraphicsView::PGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    setDragMode(QGraphicsView::NoDrag);
    QRect geo = geometry();
    geo.setWidth(geo.width() - 20);
    geo.setHeight(geo.height() - 20);
    setGeometry(geo);
}

void PGraphicsView::keyPressEvent(QKeyEvent *event) {
    qDebug() << "Handling key event in graphics view " << event->text();
    QGraphicsView::keyPressEvent(event);
}
