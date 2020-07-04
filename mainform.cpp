#include "mainform.h"
#include "ui_mainform.h"
#include <QDateTime>
#include <QDebug>
//#include <QThread>
#include <QString>
//#include <QtConcurrent/qtconcurrentrun.h>
#include <QComboBox>
#include <QSpinBox>
#include <QRadioButton>
#include <QDateTimeEdit>
#include <QDial>
#include <QLCDNumber>
#include "form2.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::on_btnButton_clicked()
{


    auto start = QDateTime::currentMSecsSinceEpoch();
    //ui->lLog->setText(QString::number(QDateTime::currentMSecsSinceEpoch()) + '\n');

    ui->table1->setColumnCount(200);
    ui->table1->setRowCount(10000);

    for (int c = 0; c < 200; ++c) {
        ui->table1->horizontalHeader()->setSectionResizeMode( c, QHeaderView::ResizeToContents );
    }

    //QStringList header;
    //header <<"#"<<"Name"<<"Text";
    //ui->table1->setHorizontalHeaderLabels(header);

    for (int r = 0; r < 10000; ++r) {
        for (int c = 0; c < 200; ++c) {
            //QString s = ;
            ui->table1->setItem(r, c, new QTableWidgetItem(QString::number(rand() % 1000000), 1));
        }
    }

    auto end = QDateTime::currentMSecsSinceEpoch();
    ui->lLog->setText(QString::number(start) + '\n' +
                      QString::number(end) + '\n' +
                      QString::number(end - start));
}

void MainForm::on_pushButton_clicked()
{
    ui->table1->setRowCount(0);
    ui->table1->setColumnCount(0);
}

void MainForm::on_pushButton_2_clicked()
{
    ui->table1->setColumnCount( 7 );
    ui->table1->setRowCount( 6 );
    ui->table1->setCellWidget ( 0, 0, new QComboBox( ui->table1 ) );
    ui->table1->setCellWidget ( 0, 1, new QSpinBox( ui->table1 ) );
    ui->table1->setCellWidget ( 0, 2, new QRadioButton( ui->table1 ) );
    ui->table1->setCellWidget ( 0, 3, new QDateTimeEdit( ui->table1 ) );
    ui->table1->setCellWidget ( 0, 4, new QDial( ui->table1 ) );
    ui->table1->setCellWidget ( 0, 5, new QLCDNumber( ui->table1 ) );
    ui->table1->setItem ( 0, 6, new QTableWidgetItem (QString("skjd hfjadf hsalkjd hflkhwaflakdshuf"), 0));
    ui->table1->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch );
    ui->table1->horizontalHeader()->setSectionResizeMode( 1, QHeaderView::ResizeToContents );

    ui->table1->horizontalHeader()->setSectionResizeMode( 6, QHeaderView::ResizeToContents );
}

void MainForm::on_btnNewMidChild_clicked()
{
    Form2 *form2 = new Form2;
    ui->mdiArea->addSubWindow(form2);
    form2->show();
}

void MainForm::on_table1_cellChanged(int row, int column)
{
    //qDebug() << "changed";
}
