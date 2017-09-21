#ifndef QTAV_QUICKFBOCAPTURER_H
#define QTAV_QUICKFBOCAPTURER_H

#include <QmlAV/QuickFBORenderer.h>
#include <QtAV/AVVideoCapturer.h>

namespace QtAV {
class QuickFBOCapturer: public QuickFBORenderer
{
    Q_OBJECT
    Q_PROPERTY(AVVideoCapturer* capturer READ capturer WRITE setCapturer NOTIFY capturerChanged)
public:
    explicit QuickFBOCapturer(QQuickItem *parent = 0);

    AVVideoCapturer *capturer() const;
    void setCapturer(AVVideoCapturer *capturer);

protected:
    virtual bool receiveFrame(const VideoFrame &frame) Q_DECL_OVERRIDE;

Q_SIGNALS:
    void capturerChanged();

private:
    AVVideoCapturer *m_capturer;
};
} // namespace QtAV
#endif // QTAV_QUICKFBOCAPTURER_H
