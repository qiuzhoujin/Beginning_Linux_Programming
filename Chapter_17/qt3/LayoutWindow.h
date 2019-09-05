#include <QMainWindow>

class LayoutWindow : public QMainWindow
{
	Q_OBJECT
	
	public:
		LayoutWindow(QWidget *parent = 0, const char *name = 0);
		virtual ~LayoutWindow();
};
