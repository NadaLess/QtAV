#ifndef OPENGLCHECKER_H
#define OPENGLCHECKER_H
#include <QtAV_Global.h>
#include <QOpenGLFunctions>
#include <QOffscreenSurface>

namespace QtAV {

class Q_AV_EXPORT ZeroCopyChecker : protected QOpenGLFunctions
{
public:
    static ZeroCopyChecker* instance();
    bool enabled() const;
    void setEnabled(bool enabled);

private:
    explicit ZeroCopyChecker();

    QOffscreenSurface * m_surface;
    bool m_enabled;
};
}

#endif // OPENGLCHECKER_H
