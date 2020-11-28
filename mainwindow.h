#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
class MainWindow : public QWidget
{
    Q_OBJECT
    QPushButton *noBtn;
    QPushButton *yesBtn;
    QLabel *lbl;
    int timerId;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void timerEvent(QTimerEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

public slots:
    void handleYes();
};
#endif // MAINWINDOW_H
