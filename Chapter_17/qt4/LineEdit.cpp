#include "LineEdit.moc"
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QLayout>
#include <iostream>

LineEdit::LineEdit(QWidget *parent, const char *name)
{
	QWidget *widget = new QWidget(this);
	setCentralWidget(widget);
	QGridLayout *grid = new QGridLayout(widget);
	grid->setSpacing(2);
	grid->setVerticalSpacing(3);

	QLineEdit *username_entry = new QLineEdit(widget);
	password_entry = new QLineEdit(widget);
	password_entry->setEchoMode(QLineEdit::Password);

	grid->addWidget(new QLabel("Username", widget), 0, 0, 0);
	grid->addWidget(new QLabel("Password", widget), 1, 0, 0);

	grid->addWidget(username_entry, 0, 1, 0);
	grid->addWidget(password_entry, 1, 1, 0);

	QPushButton *button = new QPushButton("Ok", widget);
	grid->addWidget(button, 2, 1, Qt::AlignRight);

	resize(350, 200);

	connect(button, SIGNAL(clicked()), this, SLOT(Clicked()));
}

void LineEdit::Clicked(void)
{
	QByteArray ba(password_entry->text().toAscii());

	std::cout << ba.data() << "\n";
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	LineEdit *window = new LineEdit();

	app.setActiveWindow(window);
	window->show();

	return app.exec();
}
