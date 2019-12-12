#include <QMainWindow>
#include <QComboBox>

class ComboBox : public QMainWindow
{
	Q_OBJECT

	public:
		ComboBox(QWidget *parent = 0, const char *name = 0);

	private slots:
		void Changed(const QString& s);
};

