#ifndef FRAME_H
#define FRAME_H

#include <QWidget>
#include <QFrame>
#include <QResizeEvent>

class Frame : public QFrame
{
    Q_OBJECT

    public:
        explicit Frame(QWidget *parent = nullptr);

    public slots:
        void resizeEvent(QResizeEvent *);
};

#endif // FRAME_H
