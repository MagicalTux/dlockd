#include <QMetaObject>
#include <QCoreApplication>

#include "DLockManager.hpp"

DLockManager::DLockManager(quint16 _port) {
	port = _port;
}

void DLockManager::terminate() {
	qDebug("Exiting cleanly");
	QCoreApplication::quit();
}
