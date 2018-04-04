#include "regscreen.h"
#include "ui_regscreen.h"



RegScreen::RegScreen(QWidget *parent, Qt::WindowFlags flags):
    QWidget(parent, flags),
    ui(new Ui::RegScreen)
{
    base=dynamic_cast<MainScreen*>(parent);
    ui->setupUi(this);
}

RegScreen::~RegScreen()
{
    delete ui;
}

void RegScreen::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

void RegScreen::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}

void RegScreen::on_lineEdit_2_selectionChanged()
{

}

void RegScreen::on_lineEdit_2_cursorPositionChanged(int arg1, int arg2)
{
    ui->lineEdit_2->setText("");
}

void RegScreen::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2)
{
    ui->lineEdit_3->setText("");
}

void RegScreen::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    ui->lineEdit->setText("");
}

void RegScreen::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{
    ui->lineEdit_4->setText("");
}

void RegScreen::on_lineEdit_5_cursorPositionChanged(int arg1, int arg2)
{
    ui->lineEdit_5->setText("");
}
