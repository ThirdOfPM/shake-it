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
/*!
 * Предобъявление класса
 */
class OnlineScreen;
/*!
 * Класс, отвечающий за отображение карты
 */
class MapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidget(QWidget *parent = 0);
    ~MapWidget();
/*!
 * Загружает информацию, которая используется для отображения карты
 * \param r радиус
 * \param lat широта
 * \param lon долгота
 */
    void loadData(const int& r, const double& lat, const double& lon );
/*!
 * Обновляет изображение карты
 */
    void update();
private slots:
/*!
 * Слот вызывается, когда  приходит ответ от сервера Google
 * \param reply Ответ сервера
 */
    void replyFinished(QNetworkReply *reply);

private:
    Ui::MapWidget *ui;
    int radius=300; ///< Радиус
    int mapScale; ///< Размер карты
    double center[2]; ///< Координаты центра карты
/*!
 * Указатель на класс для работы с URl запросами
 */
    QNetworkAccessManager *manager;
/*!
 * Хранит указатель на экран, на котором находится карта
 */
    OnlineScreen* screen;
/*!
 * Функция, которая рассчитывает масштаб карты и присваивает его переменной mapScale
 */
    void calculateScale();
/*!
 * Рассчитывает координаты круга и возвращает их в виде строки для подстановки в Google Static Api
 * \return Возвращает координаты круга
 */
    QString circlePath();
/*!
 * Рассчитывает координаты пользователей в зоне, которая видна владельцу карты, и возвращает их в виде строки для подстановки в Google Static Api
 * \return Возвращает координаты пользователей
     */
    QString userMarkers();
};

#endif // MAPWIDGET_H
