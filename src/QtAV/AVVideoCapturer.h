#ifndef AVVIDEOCAPTURER_H
#define AVVIDEOCAPTURER_H

#include <QObject>
#include <QtAV/VideoFrame.h>

namespace QtAV {

class Q_AV_EXPORT AVVideoCapturer: public QObject
{
    Q_OBJECT
public:
    AVVideoCapturer(QObject * parent = nullptr);

    virtual void setFrame(const QtAV::VideoFrame & frame, const qint32 & orientation);
};

}

#endif // AVVIDEOCAPTURER_H
