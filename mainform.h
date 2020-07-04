#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>

namespace Ui {
    class MainForm;
}

class MainForm : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainForm(QWidget *parent = 0);
        ~MainForm();

    private slots:
        void on_btnButton_clicked();

        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

        void on_btnNewMidChild_clicked();

        void on_table1_cellChanged(int row, int column);

    private:
        Ui::MainForm *ui;
};

#endif // MAINFORM_H
