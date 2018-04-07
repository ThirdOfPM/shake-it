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

    ui->label_2->setText("");
}

void RegScreen::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2)
{

    ui->label_2->setText("");
}

void RegScreen::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

    ui->label_2->setText("");
}

void RegScreen::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{

    ui->label_2->setText("");
}

void RegScreen::on_lineEdit_5_cursorPositionChanged(int arg1, int arg2)
{
    ui->label_2->setText("");
}

void RegScreen::on_pushButton_clicked()
{
    if(ui->lineEdit->text()==""||ui->lineEdit_2->text()==""||ui->lineEdit_3->text()==""||ui->lineEdit_4->text()==""||ui->lineEdit_5->text()==""){
        ui->label_2->setText("Заполните все поля!");
        return;
    }
    QString login=ui->lineEdit->text();
    if(ui->lineEdit_2->text()!=ui->lineEdit_3->text()){
        ui->label_2->setText("Пароли не совпадают!");
        return;
    }
    base->sdb->open();
    QSqlQuery query;
    query.prepare("SELECT id,login FROM main");
    query.exec();
    QSqlRecord rec = query.record();
    int last_id=0;
    while (query.next()) {
        if(login==query.value(rec.indexOf("login")).toString()){
            ui->label_2->setText("Пользователь с таким логином уже существует!");
            base->sdb->close();
            return;
        }else{
            last_id=query.value(rec.indexOf("id")).toInt();
        }
    }
    QString password=ui->lineEdit_2->text();
    double coords[2]={ui->lineEdit_4->text().toDouble(), ui->lineEdit_5->text().toDouble()};;
    QString pass_hash=QString::fromUtf8(QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha3_512));
    query.prepare("INSERT INTO main(id,login,pass_hash,lat,long,friend_list,black_list) VALUES (:id,:login,:pass_hash,:lat,:long,0,0);");//
    query.bindValue(":id",QString::number(last_id+1));
    query.bindValue(":login",login);
    query.bindValue(":pass_hash",pass_hash);
    query.bindValue(":lat",QString::number(coords[0]));
    query.bindValue(":long",QString::number(coords[1]));
    query.exec();
    query.prepare("CREATE TABLE mesg_"+QString::number(last_id+1)+" ("
                  "mesg TEXT,"
                  "data TEXT,"
                  "sender_id TEXT"
                  ");");
    query.exec();
    base->sdb->close();
    this->close();
}
