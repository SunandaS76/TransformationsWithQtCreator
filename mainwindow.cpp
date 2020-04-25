#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  i=0;
  ymax=ymin=0;
 // senorita = 1;
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
  QPainter p(this);
 index = ui->comboBox->currentIndex();

 p.setPen(Qt::red);


 /*x1=600+(x1*60);
 y1=300-(y1*60);
 x2=600+(x2*60);
 y2=300-(y2*60);
*/


 p.drawLine(0,500,1600,500);
 p.drawLine(800,0,800,1000);

 char ch[4];
 int xpos=0,i;
 for(i=-10;i<=10;i++)
   {
     sprintf(ch,"%d",i);
     p.drawText(xpos,510,ch);
     xpos+=80;
   }
 int ypos=0;
 for(i=5;i>=-5;i--)
   {
     sprintf(ch,"%d",i);
     p.drawText(803,ypos,ch);
     ypos+=100;
   }


 ui->label_2->setHidden(true);
 ui->label_3->setHidden(true);
 ui->label_4->setHidden(true);
 ui->label_5->setHidden(true);
 ui->label_6->setHidden(true);
 ui->textEdit->setHidden(true);
 ui->textEdit_2->setHidden(true);
 ui->textEdit_3->setHidden(true);
 if(index == 1)
   {
     ui->label_2->setHidden(false);
     ui->label_3->setHidden(false);
     ui->label_4->setHidden(true);
     ui->label_5->setHidden(true);
     ui->label_6->setHidden(true);
     ui->textEdit->setHidden(false);
     ui->textEdit_2->setHidden(false);
     ui->textEdit_3->setHidden(true);
   }
 if(index == 2)
   {
     ui->label_2->setHidden(true);
     ui->label_3->setHidden(true);
     ui->label_4->setHidden(false);
     ui->label_5->setHidden(false);
     ui->label_6->setHidden(true);
     ui->textEdit->setHidden(false);
     ui->textEdit_2->setHidden(false);
     ui->textEdit_3->setHidden(true);
   }
 if(index == 3)
   {
     ui->label_2->setHidden(true);
     ui->label_3->setHidden(true);
     ui->label_4->setHidden(false);
     ui->label_5->setHidden(false);
     ui->label_6->setHidden(true);
     ui->textEdit->setHidden(false);
     ui->textEdit_2->setHidden(false);
     ui->textEdit_3->setHidden(true);
   }
 if(index == 4)
   {
     ui->label_2->setHidden(true);
     ui->label_3->setHidden(true);
     ui->label_4->setHidden(true);
     ui->label_5->setHidden(true);
     ui->label_6->setHidden(false);
     ui->textEdit->setHidden(true);
     ui->textEdit_2->setHidden(true);
     ui->textEdit_3->setHidden(false);
   }
 if(index == 5)
   {
     ui->label_2->setHidden(true);
     ui->label_3->setHidden(true);
     ui->label_4->setHidden(true);
     ui->label_5->setHidden(true);
     ui->label_6->setHidden(false);
     ui->textEdit->setHidden(true);
     ui->textEdit_2->setHidden(true);
     ui->textEdit_3->setHidden(false);
   }
if(flag ==1)
{
    count = ui->spinBox->value();
}
/*else if(flag ==2)
{
    if(i<count)
   {
    xx[i]=x1;
    yy[i]=y1;
    i++;
    }
    xx[i] = xx[0];
    yy[i] = yy[0];
}*/
else if(flag ==3)
{
   // xx[i]=xx[0];
   // yy[i]=yy[0];


    for(j=0;j<count;j++)
    {
        p.setPen(QPen(Qt::blue,3));
        p.drawLine(xx[j],yy[j],xx[j+1],yy[j+1]);

    }

}
if(flag ==4)
{
    for(j=0;j<count;j++)
    {
        p.setPen(QPen(Qt::blue));
        p.drawLine(xx[j],yy[j],xx[j+1],yy[j+1]);

    }
    translateaboutorigin();
    reflection();
}

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
  x1 = event->x();

  y1 = event->y();

  if(i<count)
 {
  xx[i]=x1;
  yy[i]=y1;
  i++;
  }
  xx[i] = xx[0];
  yy[i] = yy[0];
 //update();
  if(index == 5)
    {
  mypointx = event->x();
  mypointy = event->y();
    }
}

void MainWindow::translateaboutorigin()
{
  int translate[10][10],scalematrix[10][10];
  float rotatematrix[10][10];
  tx = (ui->textEdit->toPlainText().toInt())*80;
  ty = (ui->textEdit_2->toPlainText().toInt())*100;
  sx = ui->textEdit->toPlainText().toInt();
  sy = ui->textEdit_2->toPlainText().toInt();
  angleindeg = ui->textEdit_3->toPlainText().toInt();
  angleinrad = 3.14*angleindeg/180;
  for(i=0;i<count;i++)
    {
      for(j=0;j<count;j++)
        {
          if(i == j)
            {
              translate[i][j] = 1;
              rotatematrix[i][j] = 1;
              scalematrix[i][j] = 1;

            }
          else
            {
            translate[i][j] = 0;
            rotatematrix[i][j] = 0;
            scalematrix[i][j] = 0;
            }
        }
    }
  translate[count-1][0] = tx;
  translate[count-1][1] = ty;
  rotatematrix[0][0] = rotatematrix[1][1] = cos(angleinrad);
  rotatematrix[0][1] = sin(angleinrad);
  rotatematrix[1][0] = -sin(angleinrad);
  scalematrix[0][0] = sx;
  scalematrix[1][1] = sy;



  for (i=0;i<count;i++) {

      xxt[i] = (xx[i] - 800);
      yyt[i] = (500 - yy[i]);
    }



  for(i=0;i<count;i++)
    {
      for(j=0;j<count;j++)
        {
          if(j==0)
          original[i][j] = xxt[i];
          else if(j==1)
            original[i][j] = yyt[i];
          else
            original[i][j] = 1;
        }
    }


  for(i=0;i<count;i++)
    {

      for(j=0;j<count;j++)
        {
         scale[i][j] = 0;
          trans[i][j] = 0;
         rotate[i][j] = 0;
          for(k=0;k<count;k++)
            {
          trans[i][j]+= original[i][k]*translate[k][j];
          scale[i][j]+= original[i][k]*scalematrix[k][j];
          rotate[i][j]+=original[i][k]*rotatematrix[k][j];
            }
        }
    }

  for(i=0;i<count;i++)
    {
        xtra[i] = trans[i][0]+800;
        ytra[i] = 500-trans[i][1];
        xscale[i] = scale[i][0]+800;
        yscale[i] = 500-scale[i][1];
        xrotate[i] = rotate[i][0]+800;
        yrotate[i] = 500-rotate[i][1];
    }
  xtra[count] = xtra[0];
  ytra[count] = ytra[0];
  xscale[count] = xscale[0];
  yscale[count] = yscale[0];
  xrotate[count] = xrotate[0];
  yrotate[count] = yrotate[0];
  QPainter p(this);
  if(index == 1)
    {
  for(j=0;j<count;j++)
  {
      p.setPen(QPen(Qt::red,4));
      p.drawLine(xtra[j],ytra[j],xtra[j+1],ytra[j+1]);

  }
    }
  if(index == 2)
    {
  for(j=0;j<count;j++)
  {
      p.setPen(QPen(Qt::red,4));
      p.drawLine(xscale[j],yscale[j],xscale[j+1],yscale[j+1]);

  }
}


  if(index == 4)
    {
      for(j=0;j<count;j++)
        {
      p.setPen(QPen(Qt::red,4));
      p.drawLine(xrotate[j],yrotate[j],xrotate[j+1],yrotate[j+1]);
      }
    }


  if(index == 3)
    {
      scaleaboutpoint();
    }

  if(index == 5)
    {
      rotateaboutpoint();
    }
}

void MainWindow::scaleaboutpoint()
{
  //scale about first point
  int translate[10][10],scalematrix[10][10],translaterev[10][10];

  tx = xx[0];
  ty = yy[0];
  angleindeg = ui->textEdit_3->toPlainText().toInt();
  angleinrad = 3.14*angleindeg/180;
  for(i=0;i<count;i++)
    {
      for(j=0;j<count;j++)
        {
          if(j==0)
          original[i][j] = xx[i];
          else if(j==1)
            original[i][j] = yy[i];
          else
            original[i][j] = 1;
        }
    }


  for(i=0;i<count;i++)
    {
      for(j=0;j<count;j++)
        {
          if(i == j)
            {
              translate[i][j] = 1;
              scalematrix[i][j] = 1;
              translaterev[i][j] = 1;
            }
          else
            {
            translate[i][j] = 0;
            scalematrix[i][j] = 0;
            translaterev[i][j] = 0;
            }
        }
    }
  translate[count-1][0] = tx;
  translate[count-1][1] = ty;
  scalematrix[0][0] = sx;
  scalematrix[1][1] = sy;
  translaterev[count-1][0] = -tx;
  translaterev[count-1][1] = -ty;



  for(i=0;i<count;i++)
    {

      for(j=0;j<count;j++)
        {

          trans[i][j] = 0;
          for(k=0;k<count;k++)
            {
          trans[i][j]+= original[i][k]*translaterev[k][j];

            }
        }
    }

  for(i=0;i<count;i++)
    {

      for(j=0;j<count;j++)
        {
          scale[i][j] = 0;
          for(k=0;k<count;k++)
            {

          scale[i][j]+= trans[i][k]*scalematrix[k][j];

            }
        }
    }

  for(i=0;i<count;i++)
    {

      for(j=0;j<count;j++)
        {

          scaleor[i][j] = 0;
          for(k=0;k<count;k++)
            {
          scaleor[i][j]+= scale[i][k]*translate[k][j];

            }
        }
    }



  for(i=0;i<count;i++)
    {

        xscaleor[i] = scaleor[i][0];
        yscaleor[i] = scaleor[i][1];

    }

  xscaleor[count] = xscaleor[0];
  yscaleor[count] = yscaleor[0];



  QPainter s(this);
  if(index == 3)
    {
  for(j=0;j<count;j++)
  {
      s.setPen(QPen(Qt::red,4));
      s.drawLine(xscaleor[j],yscaleor[j],xscaleor[j+1],yscaleor[j+1]);

  }

    }


}

void MainWindow::rotateaboutpoint()
{
  //rotate about first point
  int translate[10][10],translaterev[10][10];
  float rotatematrix[10][10];
  tx = mypointx;
  ty = mypointy;
  sx = ui->textEdit->toPlainText().toInt();
  sy = ui->textEdit_2->toPlainText().toInt();

  for(i=0;i<count;i++)
    {
      for(j=0;j<count;j++)
        {
          if(j==0)
          original[i][j] = xx[i];
          else if(j==1)
            original[i][j] = yy[i];
          else
            original[i][j] = 1;
        }
    }


  for(i=0;i<count;i++)
    {
      for(j=0;j<count;j++)
        {
          if(i == j)
            {
              translate[i][j] = 1;
              rotatematrix[i][j] = 1;
              translaterev[i][j] = 1;
            }
          else
            {
            translate[i][j] = 0;
            rotatematrix[i][j] = 0;
            translaterev[i][j] = 0;
            }
        }
    }
  translate[count-1][0] = tx;
  translate[count-1][1] = ty;
  rotatematrix[0][0] = rotatematrix[1][1] = cos(angleinrad);
  rotatematrix[0][1] = sin(angleinrad);
  rotatematrix[1][0] = -sin(angleinrad);
  translaterev[count-1][0] = -tx;
  translaterev[count-1][1] = -ty;



  for(i=0;i<count;i++)
    {

      for(j=0;j<count;j++)
        {

          trans[i][j] = 0;
          for(k=0;k<count;k++)
            {
          trans[i][j]+= original[i][k]*translaterev[k][j];

            }
        }
    }


  for(i=0;i<count;i++)
    {

      for(j=0;j<count;j++)
         {
          rotate[i][j] = 0;
          for(k=0;k<count;k++)
            {

          rotate[i][j]+= trans[i][k]*rotatematrix[k][j];

            }
        }
    }

  for(i=0;i<count;i++)
    {

      for(j=0;j<count;j++)
        {

          rotateor[i][j] = 0;
          for(k=0;k<count;k++)
            {
          rotateor[i][j]+= rotate[i][k]*translate[k][j];

            }
        }
    }


  for(i=0;i<count;i++)
    {

        xrotateor[i] = rotateor[i][0];
        yrotateor[i] = rotateor[i][1];

    }

  xrotateor[count] = xrotateor[0];
  yrotateor[count] = yrotateor[0];



  QPainter s(this);
  if(index == 5)
    {
  for(j=0;j<count;j++)
  {
      s.setPen(QPen(Qt::red,4));
      s.drawLine(xrotateor[j],yrotateor[j],xrotateor[j+1],yrotateor[j+1]);

  }

    }

}

void MainWindow::reflection()
{
  for (i=0;i<count;i++) {
      if(index == 6)
        {
      xref[i] = - (xx[i] - 800);
      yref[i] = (500 - yy[i]);
        }
      if(index == 8)
        {
          xref[i] = (500 - yy[i]);
          yref[i] = (xx[i] - 800);
        }
      if(index == 7)
        {
      xref[i] = (xx[i] - 800);
      yref[i] = - (500 - yy[i]);
        }
    }
  for (i=0;i<count;i++) {

      xref[i] = (xref[i] + 800);
      yref[i] = (500 - yref[i]);
    }
  xref[i] = xref[0];
  yref[i] = yref[0];
  QPainter s(this);
  if(index == 6)
    {
  for(j=0;j<count;j++)
  {
      s.setPen(QPen(Qt::red,4));
      s.drawLine(xref[j],yref[j],xref[j+1],yref[j+1]);

  }
    }
  if( index == 7 )
    for(j=0;j<count;j++)
    {
        s.setPen(QPen(Qt::red,4));
        s.drawLine(xref[j],yref[j],xref[j+1],yref[j+1]);

    }
  if( index == 8 )
    for(j=0;j<count;j++)
    {
        s.setPen(QPen(Qt::red,4));

        s.drawLine(xref[j],yref[j],xref[j+1],yref[j+1]);

    }
}



void MainWindow::on_pushButton_3_clicked()
{
  flag = 4;

  //ui->pushButton_3->hide();
  update();
}

void MainWindow::on_pushButton_clicked()
{
  flag =1;
  //ui->pushButton->hide();
  update();
}

void MainWindow::on_pushButton_2_clicked()
{
  flag =3;
  //ui->pushButton_2->hide();
  update();
}


