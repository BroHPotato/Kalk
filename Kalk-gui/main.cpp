#include <QApplication>
#include <QWidget>
#include "view.h"
#include "tastierino.h"
#include "window.h"
#include "base.h"

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 view Window;
 Window.show();

 return app.exec();
}
