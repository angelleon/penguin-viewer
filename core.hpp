#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QPixmap>
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include <QStandardPaths>
#include <QApplication>
#include <QGraphicsScene>


#include "pmainwindow.hpp"

class Core: public QApplication
{
    Q_OBJECT

public:
    Core(int &argc, char *argv[], PenguinViewer *w=nullptr);
    ~Core();
    int exec();

private:
    int arc;
    char **arv;
    PenguinViewer *w;
    QPixmap *pm;
    QGraphicsScene *scene;
    QDir *currDir;
    QStringList *fileNames;
    QList<QFile*> *openedFiles;
    int fileCount;
    int filePos;
    void changeFile();

public slots:
    void sltOpen();
    void sltNext();
    void sltPrev();
    void sltQuit();

signals:
    void sgnRefreshView(QGraphicsScene*);
};

#endif // CORE_H
