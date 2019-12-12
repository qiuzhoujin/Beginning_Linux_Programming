SRC=ComboBox

all:
	moc $(SRC).h -o $(SRC).moc
	g++ -o a.out $(SRC).cpp -I/usr/include/qt4/QtGui/ -I/usr/include/qt4/Qt/ -I/usr/include/qt4/ -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread
