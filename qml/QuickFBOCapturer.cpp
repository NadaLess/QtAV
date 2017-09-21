#include "QmlAV/QuickFBOCapturer.h"

namespace QtAV {
QuickFBOCapturer::QuickFBOCapturer(QQuickItem *parent) :
    QuickFBORenderer(parent),
    m_capturer(nullptr)
{
}

bool QuickFBOCapturer::receiveFrame(const VideoFrame &frame)
{
    if (m_capturer) {
        m_capturer->setFrame(frame, orientation());
    }

    return QuickFBORenderer::receiveFrame(frame);
}

AVVideoCapturer *QuickFBOCapturer::capturer() const
{
    return m_capturer;
}

void QuickFBOCapturer::setCapturer(AVVideoCapturer *capturer)
{
    if (m_capturer != capturer) {
        m_capturer = capturer;
        Q_EMIT capturerChanged();
    }
}
} // namespace QtAV
