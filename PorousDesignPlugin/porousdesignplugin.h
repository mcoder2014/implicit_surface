#ifndef POROUSDESIGNPLUGIN_H
#define POROUSDESIGNPLUGIN_H

#include <SurfaceMeshPlugins.h>
#include <interfaces/ModePluginDockWidget.h>

/// Plugin 失败的一个可能原因是有的类的函数没有些函数体，导致生成的so文件
/// 不符合DLL规范

class ControlWidget;
//class Scene;

class PorousDesignPlugin: public SurfaceMeshModePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "PorousDesign.plugin.starlab")
    Q_INTERFACES(ModePlugin)

public:
    QString name() override { return tr("PorousDesignPlugin"); }
    QIcon icon() override { return QIcon(":/imgs/sources/grid.png"); }

    PorousDesignPlugin();
    ~PorousDesignPlugin() override;

    void create() override;
    void destroy() override;
    void decorate() override;
    bool isApplicable() override { return true; }

    QString filter() override { return QString(tr("InsoleDesignPlugin Supported Files (*.csv *.txt)")); }
    bool mousePressEvent(QMouseEvent *mouseEvent) override;
    bool mouseMoveEvent(QMouseEvent *mouseEvent) override;
    bool mouseReleaseEvent(QMouseEvent *mouseEvent) override;

//    Scene *getScene(){return this->m_curScene;}

    ControlWidget* m_controlWidget;
    ModePluginDockWidget* m_controlDockWidget;

private:
//    Scene * m_curScene;
};

#endif // POROUSDESIGNPLUGIN_H
