// #include <iostream>
#include "core.hpp"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //PenguinViewer w;
    //w.show();
    Core a(argc, argv, nullptr);

    return a.exec();
}
