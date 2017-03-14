#include <QtGui>

class CustomView : public QGraphicsView
{
protected:
    void mousePressEvent(QMouseEvent *event)
    {
        qDebug() << "Custom view clicked.";
        QGraphicsView::mousePressEvent(event);
    }
};

class CustomItem : public QGraphicsRectItem
{
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        qDebug() << "Custom item clicked.";
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomItem item,item2;
    QGraphicsScene scene;
    item.setRect(20,20,60,60);
    item2.setRect(80,20,60,60);
    scene.setSceneRect(0,0,100,100);
    scene.addItem(&item);
    scene.addItem(&item2);
    CustomView view;
    view.setScene(&scene);
    view.show();
    return a.exec();
}
