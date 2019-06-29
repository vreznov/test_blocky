#ifndef BASEWID_H
#define BASEWID_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <QPen>
#include <QList>
#include <QPointer>
#include "blockly_stc.h"

#define lstw QList<baseWid*>
/* baseWid
 * 所有显示组件的基类
 * */
class baseWid : public QWidget
{
    Q_OBJECT
public:
    explicit baseWid(QWidget *parent = 0);
    baseWid(QWidget *parent,baseWid* fml_wid_parent);
    ~baseWid();

private:
    void mInit();
    QString qs_text=tr("null cmd");
    int tx,ty;
    int wid=200;
    int heig=100;

    QPointer<baseWid> lgc_parent;
    QList<baseWid*> sons;


public:
    setText(QString fml_qs=QString::null);
    void setPos(int fml_ix,int fml_iy);
    int getSonsHeight();
    void resize_parent();
    void resize_self();

    int font_size=12;
    QRect font_rect;
    int text_left=20;
    int text_top=10;
protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent * event);

signals:

public slots:
};

#endif // BASEWID_H
