#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float countBMI(float kg, float cm);
    const QString returnmessage(float BMI);

private slots:
    void on_countButton_clicked();

private:
    Ui::MainWindow *ui;
    const QString UNDERWEIGHT = "You are underweight.";
    const QString OVERWEIGHT = "You are overweight.";
    const QString NORMAL = "Your weight is normal.";
    const QString CANNOT = "Cannot count";
};
#endif // MAINWINDOW_HH
