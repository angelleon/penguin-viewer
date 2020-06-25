#ifndef PGRAPHICSVIEW_HPP
#define PGRAPHICSVIEW_HPP

#include <QObject>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QDebug>

class PGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    PGraphicsView(QWidget *parent=nullptr);
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // PGRAPHICSVIEW_HPP
