#include "QtAV/ZeroCopyChecker.h"

using namespace QtAV;

ZeroCopyChecker *ZeroCopyChecker::instance()
{
    static ZeroCopyChecker m_checker;
    return &m_checker;
}

ZeroCopyChecker::ZeroCopyChecker():
    m_surface(nullptr), m_enabled(false)
{

#if defined(Q_OS_WIN)
    QSurfaceFormat fmt;
    fmt.setMajorVersion(3);
    fmt.setMinorVersion(3);
    fmt.setProfile(QSurfaceFormat::CoreProfile); //whatever this is
    fmt.setRenderableType(QSurfaceFormat::OpenGL);

    QOpenGLContext * ctx = new QOpenGLContext();
    ctx->setFormat(fmt);
    ctx->create();

    m_surface = new QOffscreenSurface();
    m_surface->setFormat(ctx->format());
    m_surface->create();

    ctx->makeCurrent(m_surface);
    initializeOpenGLFunctions();

    bool hasInterop = ctx->hasExtension("WGL_NV_DX_interop");
    bool hasInterop2 = ctx->hasExtension("WGL_NV_DX_interop2");
    setEnabled(hasInterop || hasInterop2);

    delete m_surface;
    delete ctx;
#elif !defined(Q_OS_ANDROID)
    setZeroCopy(true);
#endif
}

bool ZeroCopyChecker::enabled() const
{
    return m_enabled;
}

void ZeroCopyChecker::setEnabled(bool zeroCopy)
{
    if (m_enabled != zeroCopy) {
        m_enabled = zeroCopy;
    }
}
