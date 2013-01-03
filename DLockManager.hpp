#include <QObject>

class DLockManager: public QObject {
	Q_OBJECT;

public:
	DLockManager(quint16 port);

public slots:
	void terminate();

private:
	quint16 port;
};

