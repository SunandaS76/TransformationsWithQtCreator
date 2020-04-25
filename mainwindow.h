#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <cmath>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void paintEvent(QPaintEvent *);
  void mousePressEvent(QMouseEvent *event);
  void translateaboutorigin();
  void scaleaboutpoint();
  void rotateaboutpoint();
  void reflection();
private slots:
  void on_pushButton_3_clicked();

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();






private:
  Ui::MainWindow *ui;
  int x1,y1,xx[10],yy[10],xxt[10],yyt[10],xtra[10],ytra[10],xscale[10],yscale[10],xscaleor[10],yscaleor[10],xrotateor[10],yrotateor[10],xrotate[10],yrotate[10],ymin,ymax;
  int original[10][10], scale[10][10],trans[10][10],scaleor[10][10],rotate[10][10],rotateor[10][10],tx,ty,sx,sy,xref[10],yref[10];
  int count,i,j,k,flag,index,flagf,angleindeg,mypointx,mypointy;
  double senorita;
  float angleinrad;
};
#endif // MAINWINDOW_H
