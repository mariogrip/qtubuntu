// Copyright © 2012 Canonical Ltd
// FIXME(loicm) Add copyright notice here.

#include <qpa/qplatformintegrationplugin.h>
#include "integration.h"

QT_BEGIN_NAMESPACE

class QHybrisIntegrationPlugin : public QPlatformIntegrationPlugin {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QPA.QPlatformIntegrationFactoryInterface.5.1"
                    FILE "hybrislegacy.json")

 public:
  QStringList keys() const;
  QPlatformIntegration* create(const QString&, const QStringList&);
};

QStringList QHybrisIntegrationPlugin::keys() const {
  QStringList list;
  list << "hybrislegacy";
  return list;
}

QPlatformIntegration* QHybrisIntegrationPlugin::create(
    const QString& system, const QStringList& paramList) {
  Q_UNUSED(paramList);
  if (system.toLower() == "hybrislegacy")
    return new QHybrisIntegration();
  return 0;
}

QT_END_NAMESPACE

#include "main.moc"
