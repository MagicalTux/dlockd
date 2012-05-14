#include <QObject>

class DLockManager: public QObject {
	Q_OBJECT;
public:
	DLockManager(quint16 port);

private:
	quint16 port;
};

