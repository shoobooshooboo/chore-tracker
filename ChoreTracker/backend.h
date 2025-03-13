#ifndef BACKEND_H
#define BACKEND_H
#include <QObject>
#include <QtQml>


class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString toggledCount READ get_toggledCount NOTIFY toggledCount_changed)

public:
    Backend();
    QString get_toggledCount();
    Q_INVOKABLE void increment_toggledCount();

private:
    int _toggledCount = 0;

signals:
    void toggledCount_changed();
};

#endif // BACKEND_H
