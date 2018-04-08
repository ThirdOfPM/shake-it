#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QUrl>
#include <QPainter>
#include <QtNetwork>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>

namespace Ui {
class MapWidget;
}

class OnlineScreen;

class MapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidget(QWidget *parent = 0);
    ~MapWidget();
    void loadData(const int& r, const double& lat, const double& lon );
    void update();
private slots:
    void replyFinished(QNetworkReply *reply);

private:
    Ui::MapWidget *ui;
    int radius=300;
    int mapScale;
    double center[2];
    QNetworkAccessManager *manager;
    OnlineScreen* screen;

    void calculateScale();
    QString circlePath();
    QString userMarkers();
};

#endif // MAPWIDGET_H
