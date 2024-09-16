#include <DApplication>
#include <DWidgetUtil>
#include "main_window.h"
#include <QTranslator>
#include <QDebug>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    //qputenv("QT_SCALE_FACTOR", "1.25");

    DApplication::loadDXcbPlugin();
    DApplication app(argc, argv);

    const QString descriptionText = QApplication::tr("GXDE Calculator is a powerful calculator, beautiful and easy to use.");
    const QString acknowledgementLink = "https://gitee.com/GXDE-OS/gxde-calculator-rebirth/";

    if (app.setSingleInstance("gxde-calculator")) {
        app.setApplicationVersion("1.1");
        app.setProductIcon(QIcon::fromTheme("gxde-calculator"));
        app.setApplicationDescription(descriptionText + "\n");
        app.setApplicationAcknowledgementPage(acknowledgementLink);
        app.setWindowIcon(QIcon::fromTheme("gxde-calculator"));
        app.loadTranslator();

        QLocale locale;
        QTranslator tr;
        tr.load(":/translations/zh_CN.qm");

        if (locale.language() == QLocale::Chinese) {
            app.installTranslator(&tr);
        }

        MainWindow w;
        w.show();

        Dtk::Widget::moveToCenter(&w);

        return app.exec();
    }

    return 0;
}
