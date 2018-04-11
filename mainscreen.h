#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QtSql>

class OnlineScreen;
namespace Ui {
class MainScreen;
}
/*!
 * Класс, отвечающий за главный экран программы
 */
class MainScreen : public QWidget
{
    Q_OBJECT

public:
/*!
 * QList, содержащий указатели на экраны онлайн-пользователей
 */
    QList<OnlineScreen*> onlineUsers;
/*!
 * Указатель на объект для работы с базой данных
 */
    QSqlDatabase* sdb;
/*!
 * Переменная, в которой хранится имя с базой данных
 */
    QString basename="base.sqlite";

    explicit MainScreen(QWidget *parent = 0);
/*!
 * Функция расчёта расстояния в сферической системе координат между двумя точками на поверхности земного шара
 * \param point1 первая точка
 * \param point2 вторая точка
 */
    double getDist(double point1[2],double point2[2]);
    ~MainScreen();

private slots:
/*!
 * Вызывает окно логина
 */
    void on_pushButton_clicked();
/*!
 * Вызывает окно регистрации
 */
    void on_pushButton_2_clicked();
/*!
 * Вызывает окно входа в аккаунт администратора
 */
    void on_pushButton_3_clicked();

    void on_MainScreen_destroyed();
/*!
 * Слот таймера, по которому выполняется обновление гравического интерфейса
 */
    void UitimerEnd();

private:
/*!
 * Перегрузка функции QWidget. Вызывается, когда окно закрывается (закрывает окно онлайн-пользователей)
 * \param event Передается QCloseEvent и он принимается
 */
    void closeEvent(QCloseEvent *event);
    Ui::MainScreen *ui;
/*!
 * Используется для обновления графического интерфейса
 */
    QTimer* uitimer;
};

#endif // MAINSCREEN_H
