#ifndef SCROLABLEMESSAGESLAYOUT_H
#define SCROLABLEMESSAGESLAYOUT_H

#include <QWidget>

namespace Ui {
class ScrolableMessagesLayout;
}
/*!
 * Класс, отвечающий за прокручивание MessageWidget
 */
class ScrolableMessagesLayout : public QWidget
{
    Q_OBJECT

public:
/*!
 * Указатель на класс формы QtDesigner
 */
    Ui::ScrolableMessagesLayout *ui;
/*!
 * Конструктор по умолчанию
 */
    explicit ScrolableMessagesLayout(QWidget *parent = 0);
/*!
 * Деструктор по умолчанию
 */
    ~ScrolableMessagesLayout();
};

#endif // SCROLABLEMESSAGESLAYOUT_H
