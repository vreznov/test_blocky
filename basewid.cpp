#include "basewid.h"

baseWid::baseWid(QWidget *parent) : QWidget(parent)
{
    mInit();
}

baseWid::baseWid(QWidget *parent, baseWid *fml_lgc_parent) : QWidget(parent)
{
    mInit();
    lgc_parent=fml_lgc_parent;
    if(lgc_parent!=NULL)
    {
        lgc_parent->sons.append(this);
        lgc_parent->resize_self();
    }
}

baseWid::~baseWid()
{
}

void baseWid::mInit()
{
    setText();
}

baseWid::setText(QString fml_qs)
{
    if(fml_qs!=QString::null)
    {
        qs_text = fml_qs;
    }
    QFont wordfont;
    wordfont.setFamily("宋体");
    wordfont.setPointSize(font_size);
    QFontMetrics fm(wordfont);
    font_rect = fm.boundingRect( qs_text);
    wid = 20+font_rect.width()+20;//这个就获得了字符串所占的像素宽度

    resize_self();
}

void baseWid::resize_self()
{
    heig = this->getSonsHeight();
    if(heig==0) heig=100;
    this->resize(wid,heig);
}

/* getSonsHeight
 * brief: 获取所有子对象的高度和
 * return: 子对象的高度和
 * */
int baseWid::getSonsHeight()
{
    int sumH=0;
    lstw::Iterator iter=sons.begin();
    while(iter!=sons.end())
    {
        sumH+=(*iter)->size().height();
        ++iter;
    }

    return sumH;
}

void baseWid::setPos(int fml_ix, int fml_iy)
{
    tx=fml_ix;
    ty=fml_iy;
    this->setGeometry(tx,ty,wid,heig);
}

void baseWid::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen(Qt::blue,4);
    painter.setPen(pen);
    painter.drawText(text_left,text_top,qs_text);
    painter.drawRect(this->rect());
}

void baseWid::mouseMoveEvent(QMouseEvent *event)
{
    tx=this->pos().x()+event->x();
    ty=this->pos().y()+event->y();
    this->setPos(tx,ty);

//    qDebug()<<this->pos().x()<<this->pos().y()<<endl;
}
