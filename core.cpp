#include "core.hpp"

Core::Core(int &argc, char *argv[], PMainWindow *w) : QApplication(argc, argv)
{
    if (w == nullptr)
        this->w = new PMainWindow();
    else
        this->w = w;
    connect(this->w->actionOpen(), &QAction::triggered, this, &Core::sltOpen);
    connect(this, &Core::sgnRefreshView, this->w, &PMainWindow::sltRefreshView);
    connect(this->w->actionNext(), &QAction::triggered, this, &Core::sltNext);
    connect(this->w->actionPrev(), &QAction::triggered, this, &Core::sltPrev);
    connect(this->w->actionQuit(), &QAction::triggered, this, &Core::sltQuit);
    pm = new QPixmap();
    scene = new QGraphicsScene(this);
    fileNames = new QStringList();
    openedFiles = new QList<QFile*>();
    fileCount = 0;
    filePos = -1;
}

Core::~Core()
{

}

int Core::exec()
{
    this->w->showMaximized();
    return QApplication::exec();
}

void Core::sltOpen()
{
    auto fileList = QFileDialog::getOpenFileNames(
                this->w,
                "Choose one or more pictures",
                QStandardPaths::standardLocations(QStandardPaths::HomeLocation).first(),
                //"Pictures (*.JPG, *.jpg, *.jpeg, *.png)"
                "");
    fileNames = new QStringList(fileList);
    qDebug() << *fileNames;
    if (fileNames->length() == 0) {
        qDebug() << "No files to open";
        return;
    }
    fileCount = fileNames->length();
    filePos = 0;
    changeFile();
}

void Core::sltNext() {
    if (fileCount <= 1)
        return;

    if (filePos == fileNames->length()-1) {
        filePos = -1;
    }
    filePos++;
    changeFile();
}

void Core::sltPrev() {
    if (fileCount <= 1)
        return;
    if (filePos == 0)
        filePos = fileNames->length();
    filePos--;
    changeFile();
}

void Core::sltQuit() {
    QApplication::quit();

}

void Core::changeFile() {
    int width = w->renderSize().width()-1;
    int height = w->renderSize().height()-1;
    if (width == 0 || height == 0)
        return;
    QString actualFile = fileNames->at(filePos);
    qDebug() << "Rendering " << actualFile;
    QPixmap pm(actualFile);
    if (pm.width()/(float) width >= pm.height() / (float) height) {
        qDebug() << "Render width: " << width;
        pm = pm.scaledToWidth(width, Qt::TransformationMode::SmoothTransformation);
    } else {
        qDebug() << "Render height: " << height;
        pm = pm.scaledToHeight(height, Qt::TransformationMode::SmoothTransformation);
    }
    QRectF sceneRect = scene->sceneRect();
    scene->clear();

    QGraphicsPixmapItem *pmItem = scene->addPixmap(pm);
    QPointF center(sceneRect.width()/2, sceneRect.height()/2);
    int xOffset = pm.width() / 2;
    int yOffset = pm.height() / 2;
    QPointF pmPos(center.x() - xOffset, center.y() - yOffset);
    pmPos.setX(0);
    pmPos.setY(0);
    pmItem->setPos(pmPos);
    scene->addRect(sceneRect);
    scene->update(sceneRect);
    emit sgnRefreshView(scene);
    QFileInfo fileInfo(actualFile);
    QString counter;
    if (fileNames->length() > 1)
        counter.append(QString(" (%1/%2)").arg(filePos + 1).arg(fileNames->length()));
    w->setWindowTitle(fileInfo.fileName() + counter);
}
