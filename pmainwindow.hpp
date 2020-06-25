#ifndef PENGUINVIEWER_H
#define PENGUINVIEWER_H

#include <QMainWindow>
#include <QAction>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QVBoxLayout>

#include "pgraphicsview.hpp"
#include "pcentralwidget.hpp"

namespace Ui {
class PMainWindow;
}

class PMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PMainWindow(QWidget *parent = 0);
    ~PMainWindow();
    QAction *actionOpen();
    QAction *actionNext();
    QAction *actionPrev();
    QAction *actionQuit();
    QSize renderSize();

private:
    Ui::PMainWindow *ui;

protected:
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void sltRefreshView(QGraphicsScene*);
};

#endif // PENGUINVIEWER_H
