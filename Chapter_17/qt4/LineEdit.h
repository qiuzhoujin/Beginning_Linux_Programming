#include <QMainWindow>
#include <QLineEdit>
//#include <QString>

class LineEdit : public QMainWindow
{
	Q_OBJECT

	public:
		LineEdit(QWidget *parent = 0, const char *name = 0);
		QLineEdit *password_entry;
	private slots:
		void Clicked();
};
