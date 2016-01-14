#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QVector<QString>names;
    QVector<bool>metal;
    QVector<bool>nonmetal;
    QVector<bool>solid;
    QVector<bool>liquid;
    QVector<bool>gas;
    QVector<bool>sblock;
    QVector<bool>pblock;
    QVector<bool>dblock;
    QVector<bool>radio;
    QVector<bool>nonradio;
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
