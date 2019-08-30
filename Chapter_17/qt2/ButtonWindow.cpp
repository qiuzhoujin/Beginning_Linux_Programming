#include "ButtonWindow.moc"
#include <QPushButton>
#include <QApplication>
#include <QMainWindow>
#include <iostream>
using namespace std;

ButtonWindow::ButtonWindow(QWidget *parent, const char *name)
{
	setWindowTitle("This is the window Title");
	QPushButton *button = new QPushButton("Click Me!", this);
	button->setGeometry(50, 30, 70, 20);
	connect(button, SIGNAL(clicked()), this, SLOT(Clicked()));
}

ButtonWindow::~ButtonWindow()
{
}

void ButtonWindow::Clicked(void)
{
	std::cout << "clicked!\n";
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	ButtonWindow *window = new ButtonWindow();

	app.setActiveWindow(window);
	window->show();

	return app.exec();
}
