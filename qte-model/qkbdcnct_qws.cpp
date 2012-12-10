#include "qkbdcnct_qws.h"

#ifdef QT_QWS_CNCT

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>

#include <qsocketnotifier.h>

class QWSCnctKbPrivate : public QObject
{
    Q_OBJECT
public:
    QWSCnctKbPrivate( QWSCnctKeyboardHandler *h, const QString& );
    virtual ~QWSCnctKbPrivate();

    bool isOpen() { return buttonFD > 0; }

private slots:
    void readKeyboardData();

private:
    QString terminalName;
    int buttonFD;
    int kbdIdx;
    int kbdBufferLen;
    unsigned char *kbdBuffer;
    QSocketNotifier *notifier;
    QWSCnctKeyboardHandler *handler;
};

QWSCnctKeyboardHandler::QWSCnctKeyboardHandler(const QString &device)
{
    d = new QWSCnctKbPrivate( this, device );
}

QWSCnctKeyboardHandler::~QWSCnctKeyboardHandler()
{
    delete d;
}

QWSCnctKbPrivate::QWSCnctKbPrivate( QWSCnctKeyboardHandler *h, const QString &device ) : handler(h)
{
 terminalName = device.isEmpty()?"/dev/cnct_buttons":device.latin1();
 buttonFD = -1;
 notifier = 0;

 if ((buttonFD = open(terminalName, O_RDWR | O_NDELAY, 0)) < 0)
 {
  qWarning("Cannot open %s\n", terminalName.latin1());
 }

 if ( buttonFD >= 0 ) 
 {
  notifier = new QSocketNotifier( buttonFD, QSocketNotifier::Read, this );
  connect( notifier, SIGNAL(activated(int)),this,SLOT(readKeyboardData()) );
 }

 /*
 kbdBufferLen = 80;
 kbdBuffer = new unsigned char [kbdBufferLen];
 kbdIdx = 0;
 */
}

QWSCnctKbPrivate::~QWSCnctKbPrivate()
{
 if ( buttonFD > 0 ) 
 {
  ::close( buttonFD );
  buttonFD = -1;
 }
 delete notifier;
 notifier = 0;
 //delete [] kbdBuffer;
}

void QWSCnctKbPrivate::readKeyboardData()
{
 unsigned char b;
 int n=read(buttonFD,&b,sizeof(b));

 if (n) // read button ok
 {
  int keycode = Qt::Key_unknown;
  int unicode=0;
  switch ( b & 0x7f ) 
  {
   case 0x01:
   {
    //keycode = Qt::Key_F1;
    //qDebug("Qt::Key_F1");
    //unicode=0;
    keycode = 'Q';
    unicode='Q';
    break;
   }
   case 0x02:
   {
    //keycode = Qt::Key_F2;
    //qDebug("Qt::Key_F2");
    //unicode=0;


    keycode = Qt::Key_Backspace;
    unicode=0;
    break;
   }
   default:
    qDebug("Unrecognised key sequence %d", b );
  }
  if ( b & 0x80 ) // release
  {
   handler->processKeyEvent( unicode, keycode, 0, FALSE, FALSE );
   //cout << "button release" << endl;
  }
  else
  {
   handler->processKeyEvent( unicode, keycode, 0, TRUE, FALSE );  // TRUE mean pressed
   //cout << "button press" << endl;
  }
 }
}

#include "qkbdcnct_qws.moc"

#endif // QT_QWS_CNCT

