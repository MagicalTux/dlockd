#include <QObject>
#include <QHostAddress>

class DLockManager;

class DLockLocal: public QObject {
	Q_OBJECT;
public:
	DLockLocal(DLockManager&, const QHostAddress &, quint16 port);
};

