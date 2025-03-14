#ifndef BACKEND_H
#define BACKEND_H
#include <QObject>
#include <QtQml>
#include <vector>
#include <QList>


class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString toggledCount READ get_toggledCount NOTIFY toggledCount_changed)
    Q_PROPERTY(std::vector<QString> choresList READ get_choresList NOTIFY choresList_changed)

public:
    Backend();
    //toggledCount
    QString get_toggledCount();
    Q_INVOKABLE void increment_toggledCount();

    //dynamicList
    std::vector<QString> get_choresList();
    Q_INVOKABLE int get_chores_count();
    Q_INVOKABLE QString get_chore(int index);

private:
    int _toggledCount = 0;
    std::vector<QString> _choresList;

signals:
    void toggledCount_changed();
    void choresList_changed();
};

#endif // BACKEND_H
