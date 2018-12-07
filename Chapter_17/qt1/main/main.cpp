#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow();

    app.setActiveWindow(window);

    window->show();

    return app.exec();
}
