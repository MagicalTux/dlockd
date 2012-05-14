#include <QCoreApplication>
#include <QStringList>

#include "DLockManager.hpp"
#include "DLockLocal.hpp"

int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);
	QStringList args = QCoreApplication::arguments();

	int remote_port = 55822; // for online access
	int local_port = 22855; // for localhost

	if (args.size() >= 2) {
		QStringList p = args.at(1).split(":");
		remote_port = p.at(0).toInt();
		if ((remote_port < 1024) || (remote_port > 65535)) {
			qDebug("invalid remote port %d", remote_port);
			return 1;
		}
		if (p.size() > 1) {
			local_port = p.at(1).toInt();
		} else {
			local_port = remote_port+1;
		}
		if ((local_port < 1024) || (local_port > 65535)) {
			qDebug("invalid local port %d", local_port);
			return 1;
		}
	}

	DLockManager m(remote_port);
	DLockLocal l(m, QHostAddress::LocalHost, local_port);

	return app.exec();
}

