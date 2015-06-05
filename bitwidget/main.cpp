#include <QApplication>
#include "bitwidget.h"

int main(int argc, char *argv[] )
{
 QApplication app(argc, argv);
 BitWidget bw;
 bw.show();
 return app.exec();
}


