#include <QApplication>
#include <QLabel>
#include <QLayout>

#include "LayoutWindow.moc"

LayoutWindow::LayoutWindow(QWidget *parent, const char *name)
{
	setWindowTitle("Layouts");
	QWidget *widget = new QWidget(this);
	setCentralWidget(widget);

	QHBoxLayout *horizontal = new QHBoxLayout(widget);
	QVBoxLayout *vertical = new QVBoxLayout();

	QLabel* label1 = new QLabel("Top", widget);
	QLabel* label2 = new QLabel("Bottom", widget);
	QLabel* label3 = new QLabel("Right", widget);

	vertical->addWidget(label1);
	vertical->addWidget(label2);
	horizontal->addLayout(vertical);
	horizontal->addWidget(label3);
	resize(150, 100);
}

LayoutWindow::~LayoutWindow()
{
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	LayoutWindow *window = new LayoutWindow();

	app.setActiveWindow(window);
	window->show();

	return app.exec();
}
