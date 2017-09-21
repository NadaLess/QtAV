#include "AVVideoCapturer.h"

using namespace QtAV;

AVVideoCapturer::AVVideoCapturer(QObject * parent) :
    QObject(parent)
{

}

void AVVideoCapturer::setFrame(const VideoFrame &frame, const qint32 &orientation)
{
    Q_UNUSED(frame)
    Q_UNUSED(orientation)
    Q_UNIMPLEMENTED();
}
