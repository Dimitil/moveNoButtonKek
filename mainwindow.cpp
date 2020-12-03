#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QEvent>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(500, 500, 640, 480);
    setWindowTitle("Press yes");

    lbl = new QLabel("Do you like your salary?", this);
    noBtn  = new QPushButton("No", this);
    yesBtn = new QPushButton("Yes, of course", this);

    lbl -> move(rect().center().x() - lbl-> width()/2, rect().center().y());
    noBtn -> move(rect().x() + 20, rect().height() - noBtn ->height());
    yesBtn -> move(rect().width()  - yesBtn -> width(),
                   rect().height() - yesBtn -> height());

    connect(yesBtn, SIGNAL (released()), this, SLOT (handleYes()));
    noBtn -> installEventFilter(this);
}

void MainWindow::handleYes()
{
    qDebug() << "yes pressed";
    QMessageBox::information(nullptr, "Yes", "Of course!");
}

MainWindow::~MainWindow()
{
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if ( event->type() == QEvent::Enter) {
        timerId = startTimer(25); //singleShot вместо таймера можно
    }
}


void MainWindow::timerEvent(QTimerEvent *event)
{
    killTimer(timerId);
    int step = 30;
    int newX = rand()% ( rect().width() - noBtn->width() );
    int newY = rand()% ( rect().height() - noBtn->height() );
    for(int i = 0; i < step; i++) {
        noBtn->move( noBtn->x() + (newX - noBtn->x())/step,
                     noBtn->y() + (newY - noBtn->y())/step);
        repaint();
    }
}
