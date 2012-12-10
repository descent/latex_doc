#ifndef QKBDCNCT_QWS_H
#define QKBDCNCT_QWS_H

#include "qkbd_qws.h"

#ifdef QT_QWS_CNCT

class QWSCnctKbPrivate;

class QWSCnctKeyboardHandler : public QWSKeyboardHandler
{
 public:
  QWSCnctKeyboardHandler(const QString&);
  virtual ~QWSCnctKeyboardHandler();
private:
   QWSCnctKbPrivate *d;
};

#endif // QT_QWS_CNCT

#endif // QKBDCNCT_QWS_H

