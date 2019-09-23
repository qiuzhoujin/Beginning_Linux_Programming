#include "Buttons.moc"
#include <QButtonGroup>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QLayout>
#include <iostream>

Buttons::Buttons(QWidget *parent, const char *name)
{
	QWidget *widget = new QWidget(this);
	setCentralWidget(widget);

	QVBoxLayout *vbox = new QVBoxLayout(widget);
	vbox->setSpacing(10);

	checkbox = new QCheckBox("CheckButton", widget);
	vbox->addWidget(checkbox);

	QButtonGroup *buttongroup = new QButtonGroup(0);

	radiobutton1 = new QRadioButton("RadioButton1", widget);
	buttongroup->addButton(radiobutton1);
	vbox->addWidget(radiobutton1);

	radiobutton2 = new QRadioButton("RadioButton2", widget);
	buttongroup->addButton(radiobutton2);
	vbox->addWidget(radiobutton2);

	QPushButton *button = new QPushButton("Ok", widget);
	vbox->addWidget(button);

	resize(350, 200);

	connect(button, SIGNAL(clicked()), this, SLOT(Clicked()));
}

void Buttons::PrintActive(QAbstractButton *button)
{
	QByteArray ba(button->text().toAscii());
	if (button->isChecked())
		std::cout << ba.data() << " is checked\n";
	else
		std::cout << ba.data() << " is not checked\n";
}

void Buttons::Clicked(void)
{
	PrintActive(checkbox);
	PrintActive(radiobutton1);
	PrintActive(radiobutton2);
	std::cout << "\n";
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	Buttons *window = new Buttons();

	app.setActiveWindow(window);
	window->show();

	return app.exec();
}
