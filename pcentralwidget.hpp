#ifndef PCENTRALWIDGET_HPP
#define PCENTRALWIDGET_HPP

#include <QWidget>
#include <QDebug>


class PCentralWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PCentralWidget(QWidget *parent = nullptr);
    ~PCentralWidget();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // PCENTRALWIDGET_HPP
