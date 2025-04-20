#ifndef BACKEND_H
#define BACKEND_H
#include <QObject>
#include <QtQml>
#include <vector>
#include <QList>
#include <QTextStream>
#include <QFile>
#include "user.hpp"
#include "household.hpp"

class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString toggledCount READ get_toggledCount NOTIFY toggledCount_changed)
    Q_PROPERTY(std::vector<QString> choresList READ get_choresList NOTIFY choresList_changed)
    Q_PROPERTY(QString dynamicText READ get_dynamicText WRITE set_dynamicText NOTIFY dynamicText_changed)


    Q_PROPERTY(QString userName READ get_user_name NOTIFY userDataChanged)
    Q_PROPERTY(QVariantList householdNames READ getHouseholdNames NOTIFY householdNamesChanged)
    Q_PROPERTY(QVariantList householdUsers READ getHouseholdUsers NOTIFY householdUsersChanged)


public:
    Q_INVOKABLE Backend();
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

    Q_INVOKABLE QString get_user_name() const;

    Q_INVOKABLE QVariantList getHouseholdNames();
    Q_INVOKABLE QVariantList getHouseholdUsers();

private:
    int _toggledCount = 0;
    QString _dynamicText;
    std::vector<QString> _choresList;


    User *_user;
    User *_testUser;
    User *_testUser1;
    User *_testUser2;
    User *_testUser3;
    User *_testUser4;
    std::shared_ptr<Household> _houseHold1;
    std::shared_ptr<Household> _houseHold2;
    std::shared_ptr<Household> _houseHold3;


signals:
    void toggledCount_changed();
    void choresList_changed();
    void dynamicText_changed();
    void userDataChanged();
    void householdNamesChanged();
    void householdUsersChanged();
};
#endif // BACKEND_H
