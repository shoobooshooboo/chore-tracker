#ifndef BACKEND_H
#define BACKEND_H
#include <QObject>
#include <QtQml>


class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString testText READ get_text NOTIFY text_changed)

public:
    Backend();
    QString get_text();
    Q_INVOKABLE void change_text(int x);

private:
    QString _text = "Times toggled: 0";

signals:
    void text_changed();
};

#endif // BACKEND_H
