#include "AVVideoCapturer.h"
#include <QDebug>
using namespace QtAV;

AVVideoCapturer::AVVideoCapturer(QObject * parent) :
    QObject(parent)
{

}

void AVVideoCapturer::setFrame(const VideoFrame &frame, const qint32 &orientation)
{
    qDebug() << Q_FUNC_INFO;
    Q_UNUSED(frame)
    Q_UNUSED(orientation)
    Q_UNIMPLEMENTED();
}
