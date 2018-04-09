#include "mapwidget.h"
#include "onlinescreen.h"
#include "ui_mapwidget.h"

MapWidget::MapWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWidget)
{
    screen=dynamic_cast<OnlineScreen*>(parent);
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    ui->setupUi(this);
}

MapWidget::~MapWidget()
{
    delete ui;
    delete manager;
}

void MapWidget::loadData(const int &r, const double &plat, const double &plon)
{
    radius=r;
    center[0]=plat;
    center[1]=plon;
}

void MapWidget::update()
{
    QString key="AIzaSyCGpZgT47esKrD80T_3w6dx1VCVLHZ12bg";
    calculateScale();
    QString url=QString("https://maps.googleapis.com/maps/api/staticmap?center=")+QString::number(center[0])+","+QString::number(center[1])+"&zoom="+QString::number(mapScale)+"&size=450x450&markers="+"color:orange|size:mid"+userMarkers()+"&markers=color:green|size:small|"+QString::number(center[0])+","+QString::number(center[1])+"&path=color:0x000000FF|weight:1|"+circlePath()+"&key="+key;
    //qDebug()<<url;
    manager->get(QNetworkRequest(QUrl(url)));
}

void MapWidget::calculateScale()
{
    int rad=(radius/10)*10;
    radius=rad;
    int log=log2(radius);
    mapScale=std::max(std::min(25-log-2,20),0);
    if(radius==0)
        mapScale=20;
}

QString MapWidget::circlePath()
{
    QString res;
    double point[2]={center[0], center[1]};
    double deltaH=radius/(111300*cos(point[0]*3.14159265359/180));
    double deltaV=radius/111111.0;
    point[1]+=deltaH;
    if(point[1]>180){
        double pereval=point[1]-180;
        point[1]-=radius/(111300*cos(point[0]));
        point[1]*=-1;
        point[1]=-180+pereval;
    }
    res+=QString::number(point[0])+","+QString::number(point[1])+"|";//1
    //double delta=std::abs(point[1]-center[1]);//only long!
    point[1]=center[1]+deltaH*(1/sqrt(2));
    point[0]=center[0]+deltaV*(1/sqrt(2));
    if(point[1]>180){
        double pereval=point[1]-180;
        point[1]-=deltaH*(1/sqrt(2));
        point[1]*=-1;
        point[1]=-180+pereval;
    }
    if(point[0]>90){
        double pereval=point[0]-90;
        point[0]-=deltaV*(1/sqrt(2));
        point[1]*=-1;
        point[0]=90-pereval;
    }
    res+=QString::number(point[0])+","+QString::number(point[1])+"|";//2
    point[1]=center[1];
    point[0]=center[0]+deltaV;
    if(point[0]>90){
        double pereval=point[0]-90;
        point[0]-=deltaV;
        point[1]*=-1;
        point[0]=90-pereval;
    }
    res+=QString::number(point[0])+","+QString::number(point[1])+"|";//3
    point[1]=center[1]-deltaH*(1/sqrt(2));
    point[0]=center[0]+deltaV*(1/sqrt(2));
    if(point[1]<-180){
        double pereval=-(point[1]+180);
        point[1]+=deltaH*(1/sqrt(2));
        point[1]*=-1;
        point[1]=180-pereval;
    }
    if(point[0]>90){
        double pereval=point[0]-90;
        point[0]-=deltaV*(1/sqrt(2));
        point[1]*=-1;
        point[0]=90-pereval;
    }
    res+=QString::number(point[0])+","+QString::number(point[1])+"|";//4
    point[0]=center[0];
    point[1]=center[1]-deltaH;
    if(point[1]<-180){
        double pereval=-(point[1]+180);
        point[1]+=deltaH;
        point[1]*=-1;
        point[1]=180-pereval;
    }
    res+=QString::number(point[0])+","+QString::number(point[1])+"|";//5
    point[1]=center[1]-deltaH*(1/sqrt(2));
    point[0]=center[0]-deltaV*(1/sqrt(2));
    if(point[1]<-180){
        double pereval=-(point[1]+180);
        point[1]+=deltaH*(1/sqrt(2));
        point[1]*=-1;
        point[1]=180-pereval;
    }
    if(point[0]<-90){
        double pereval=-(point[0]+90);
        point[0]+=deltaV*(1/sqrt(2));
        point[1]*=-1;
        point[0]=-90+pereval;
    }
    res+=QString::number(point[0])+","+QString::number(point[1])+"|";//6
    point[1]=center[1];
    point[0]=center[0]-deltaV;
    if(point[0]<-90){
        double pereval=-(point[0]+90);
        point[0]+=deltaV;
        point[1]*=-1;
        point[0]=-90+pereval;
    }
    res+=QString::number(point[0])+","+QString::number(point[1])+"|";//7
    point[1]=center[1]+deltaH*(1/sqrt(2));
    point[0]=center[0]-deltaV*(1/sqrt(2));
    if(point[1]>180){
        double pereval=point[1]-180;
        point[1]-=deltaH*(1/sqrt(2));
        point[1]*=-1;
        point[1]=-180+pereval;
    }
    if(point[0]<-90){
        double pereval=-(point[0]+90);
        point[0]+=deltaV*(1/sqrt(2));
        point[1]*=-1;
        point[0]=-90+pereval;
    }
    res+=QString::number(point[0])+","+QString::number(point[1])+"|";//8
    point[0]=center[0];
    point[1]=center[1]+deltaH;
    if(point[1]>180){
        double pereval=point[1]-180;
        point[1]-=deltaH;
        point[1]*=-1;
        point[1]=-180+pereval;
    }
    res+=QString::number(point[0])+","+QString::number(point[1]);//9
    return res;
}

QString MapWidget::userMarkers()
{
    QString res="";
    for(int i=0;i<screen->base->onlineUsers.size();i++){
        double dist=screen->base->getDist(screen->user->location,screen->base->onlineUsers[i]->user->location);
        if(screen->base->onlineUsers[i]!=screen&&dist<=screen->user->radius&&dist<=screen->base->onlineUsers[i]->user->radius)
            res+="|"+QString::number(screen->base->onlineUsers[i]->user->location[0])+","+QString::number(screen->base->onlineUsers[i]->user->location[1]);
    }
    return res;
}

void MapWidget::replyFinished(QNetworkReply *reply)
{
    QByteArray data=reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(data,"PNG");
    //QSize newWindowSize=0.7*pixmap.size();
    resize(450,450);
    ui->label->move(0,0);
    ui->label->resize(450,450);
    int r=225;
    QPixmap cutted(r*2,r*2);
    cutted.fill(Qt::transparent);
    QPainter paint(&cutted);
    paint.setClipRegion(QRegion(QRect(0, 0, r*2, r*2), QRegion::Ellipse));
    pixmap=pixmap.scaled(r*2,r*2,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    paint.drawPixmap(0,0,pixmap);
    //cutted=cutted.scaled(450,450,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->label->setPixmap(cutted);
    reply->deleteLater();

}
