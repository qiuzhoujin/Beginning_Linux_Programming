#include "ComboBox.moc"
#include <QApplication>
#include <QLayout>
#include <iostream>

ComboBox::ComboBox(QWidget *parent, const char *name)
{
	QWidget *widget = new QWidget(this);
	setCentralWidget(widget);

	QVBoxLayout *vbox = new QVBoxLayout(widget);
	vbox->setSpacing(10);

	QComboBox *editablecombo = new QComboBox(widget);
	editablecombo->setEditable(TRUE);
	vbox->addWidget(editablecombo);
	QComboBox *readonlycombo = new QComboBox(widget);
	readonlycombo->setEditable(FALSE);
	vbox->addWidget(readonlycombo);

	static const char* items[] = { "Macbeth", "Twelfth Night", "Othello", 0 };
	for (int i = 0; i < 3; i++)
	{
		editablecombo->insertItem(i, items[i]);
		readonlycombo->insertItem(i, items[i]);
	}

	connect(editablecombo, SIGNAL(textChanged(const QString&)),
			this, SLOT(Changed(const QString&)));
	resize(350, 200);
}

void ComboBox::Changed(const QString& s)
{
	QByteArray ba(s.toAscii());
	std::cout << ba.data() << "\n";
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	ComboBox *window = new ComboBox();

	app.setActiveWindow(window);
	window->show();

	return app.exec();
}

