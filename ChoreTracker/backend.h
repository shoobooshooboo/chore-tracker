#ifndef BACKEND_H
#define BACKEND_H
#include <QObject>
#include <QtQml>
#include <vector>
#include <QList>
#include <QTextStream>
#include <QFile>

class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString toggledCount READ get_toggledCount NOTIFY toggledCount_changed)
    Q_PROPERTY(std::vector<QString> choresList READ get_choresList NOTIFY choresList_changed)
    Q_PROPERTY(QString dynamicText READ get_dynamicText WRITE set_dynamicText NOTIFY dynamicText_changed)

public:
    Backend();
    //toggledCount
    QString get_toggledCount();
    Q_INVOKABLE void increment_toggledCount();

    //dynamicList
    std::vector<QString> get_choresList();
    Q_INVOKABLE int get_chores_count();
    Q_INVOKABLE QString get_chore(int index);

    //dynamicText
    QString get_dynamicText();
    void set_dynamicText(QString &newText);


private:
    int _toggledCount = 0;
    QString _dynamicText;
    std::vector<QString> _choresList;

signals:
    void toggledCount_changed();
    void choresList_changed();
    void dynamicText_changed();
};

#endif // BACKEND_H
