#include <QMainWindow>
#include <QCheckBox>
#include <QAbstractButton>
#include <QRadioButton>

class Buttons : public QMainWindow
{
	Q_OBJECT

	public:
		Buttons(QWidget *parent = 0, const char *name = 0);
	private:
		void PrintActive(QAbstractButton *button);
		QCheckBox *checkbox;
		QRadioButton *radiobutton1, *radiobutton2;
	private slots:
		void Clicked();
};
