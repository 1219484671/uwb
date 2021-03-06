#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include "qcustomplot.h"

#define OPENSTATE   0
#define CLOSESTATE  1

#define BASETIME    500

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer = new QTimer(this);
    QList<QString> serialport_list;             //可用串口列表
    bool serial_state;                          //串口状态
    QString  serial_choice;                     //从串口下拉列表中选择的串口名
    QSerialPort *serialport = new QSerialPort();
    QList<int> id_list;
    int max_line_id;
    typedef struct line
    {
        QVector<double> x;
        QVector<double> y;
    }line;
    QList<line> line_list;
    void widgetInit();
    bool openSerialport();
    void closeSerialport();
    void writeSerialport(quint8 *data,int count);
    int addLine(int id);

private slots:
   void changeSerialState();
   void searchSerialport();
   void recordSerialChoice(int choice);
   void readSerialport();
   void syncCoordinateAxis();
};
#endif // MAINWINDOW_H
