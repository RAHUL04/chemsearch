#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString str;
    str=":/hydrogen.txt";

    QFile file(str);
    if(!file.open(QIODevice::ReadOnly))
    {

        return ;
    }
    QDataStream in(&file);

    // ui->plainTextEdit->setPlainText(names[0]+names[1]);
     file.close();

     if(!file.open(QIODevice::ReadOnly))
     {

         return ;
     }
     //in(&file);
      while (!in.atEnd()){
        QString all=file.readLine();

     QString name=all.split(" ").at(0);
     QString metalic=all.split(" ").at(1);
     QString state=all.split(" ").at(2);
     QString block=all.split(" ").at(3);
     QString radioactive=all.split(" ").at(4);

     names.push_back(name);



     if(metalic=="metal")
         metal.push_back(true);
     else
         metal.push_back(false);
     if(metalic=="nonmetal")
     {
         nonmetal.push_back(true);}
     else
         nonmetal.push_back(false);
     if(state=="solid")
         solid.push_back(true);
     else
         solid.push_back(false);
     if(state=="liquid")
         liquid.push_back(true);
     else
         liquid.push_back(false);
     if(state=="gas")
         gas.push_back(true);
     else
         gas.push_back(false);
     if(block=="sblock")
         sblock.push_back(true);
     else
         sblock.push_back(false);
     if(block=="pblock")
         pblock.push_back(true);
     else
         pblock.push_back(false);
     if(block=="dblock")
         dblock.push_back(true);
     else
         dblock.push_back(false);
     if(radioactive=="radio")
     {
         radio.push_back(true);

        }
     else
     {
         radio.push_back(false);
         }
     if(radioactive=="nonradio")
     {
         nonradio.push_back(true);
        }

     else
     {
         nonradio.push_back(false);
        }
      }



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QString metalchoice=ui->comboBox->currentText();
    QString state=ui->comboBox_2->currentText();
    QString block=ui->comboBox_3->currentText();
    QString radiochoice=ui->comboBox_4->currentText();
    QVector<bool>mc;
    QVector<bool>sc;
    QVector<bool>bc;
    QVector<bool>rc;
    QVector<bool>ans;
    if(metalchoice=="Metal")
    {
        mc=metal;

    }
    else if(metalchoice=="Non-metal")
    {
        mc=nonmetal;


    }
    if(state=="Solid")
    {
        sc=solid;
    }
    else if(state=="Gas")
    {
        sc=gas;
    }
    else if(state=="Liquid")
    {
        sc=liquid;
    }
    if(block=="Sblock")
    {
        bc=sblock;
    }
    else if(state=="Pblock")
    {
        bc=pblock;
    }
    else if(state=="Dblock")
    {
        bc=dblock;
    }
    if(radiochoice=="RadioActivity")
    {
        rc = radio;
       // ui->listWidget->addItem("radio");
    }
    else if(radiochoice=="Non-Radioactivity")
    {
        rc=nonradio;
        //ui->listWidget->addItem("nonradio");

    }
if(mc.size()!= 0)
{
    ans=mc;
}
if(sc.size()!=0)
{
   for(int i=0;i<ans.size();i++)
   {
       ans[i]=ans[i]&sc[i];
   }
}
if(bc.size()!=0)
{
   for(int i=0;i<ans.size();i++)
   {
       ans[i]=ans[i]&bc[i];
   }
}
if(rc.size()!=0)
{
   for(int i=0;i<ans.size();i++)
   {
       ans[i]=ans[i]&rc[i];

   }
}
for(int i=0;i<ans.size();i++)
{
    if(ans[i]==true)
        ui->listWidget->addItem(names[i]);
     else
             ui->listWidget->addItem("NO ITEM");
}

}

void MainWindow::on_pushButton_2_clicked()
{
    QString metalchoice=ui->comboBox_5->currentText();
    QString state=ui->comboBox_6->currentText();
    QString block=ui->comboBox_7->currentText();
    QString radiochoice=ui->comboBox_8->currentText();
    QVector<bool>mc;
    QVector<bool>sc;
    QVector<bool>bc;
    QVector<bool>rc;
    QVector<bool>ans;
    if(metalchoice=="Metal")
    {
        mc=metal;

    }
    else if(metalchoice=="Non-metal")
    {
        mc=nonmetal;


    }
    if(state=="Solid")
    {
        sc=solid;
    }
    else if(state=="Gas")
    {
        sc=gas;
    }
    else if(state=="Liquid")
    {
        sc=liquid;
    }
    if(block=="Sblock")
    {
        bc=sblock;
    }
    else if(state=="Pblock")
    {
        bc=pblock;
    }
    else if(state=="Dblock")
    {
        bc=dblock;
    }
    if(radiochoice=="RadioActivity")
    {
        rc = radio;
//ui->listWidget_2->addItem("radio");
    }
    else if(radiochoice=="Non-Radioactivity")
    {
        rc=nonradio;

//ui->listWidget_2->addItem("nonradio");
    }
for(int i=0;i<names.size();i++)
    ans.push_back(false);
if(mc.size()!= 0)
{
    for(int i=0;i<ans.size();i++)
    ans[i]=ans[i] |mc[i];
}
if(sc.size()!=0)
{
   for(int i=0;i<ans.size();i++)
   {
       ans[i]=ans[i] | sc[i];
   }
}
if(bc.size()!=0)
{
   for(int i=0;i<ans.size();i++)
   {
       ans[i]=ans[i] | bc[i];
   }
}
if(rc.size()!=0)
{
   for(int i=0;i<ans.size();i++)
   {
       ans[i]=ans[i]|rc[i];
   }
}
for(int i=0;i<ans.size();i++)
{
    if(ans[i]==true)
        ui->listWidget_2->addItem(names[i]);
     else
             ui->listWidget_2->addItem("NO ITEM");
}

}
