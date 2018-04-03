#ifndef SCROLABLEMESSAGESLAYOUT_H
#define SCROLABLEMESSAGESLAYOUT_H

#include <QWidget>

namespace Ui {
class ScrolableMessagesLayout;
}

class ScrolableMessagesLayout : public QWidget
{
    Q_OBJECT

public:
    Ui::ScrolableMessagesLayout *ui;

    explicit ScrolableMessagesLayout(QWidget *parent = 0);
    ~ScrolableMessagesLayout();

private:

};

#endif // SCROLABLEMESSAGESLAYOUT_H
