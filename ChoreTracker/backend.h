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
#include "household_manager.hpp"
#include "user_manager.hpp"

class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString username READ get_user_name NOTIFY userDataChanged)
    Q_PROPERTY(QString curHouseholdName READ get_cur_household_name NOTIFY curHouseholdChanged)
    Q_PROPERTY(QVariantList householdNames READ getHouseholdNames NOTIFY householdNamesChanged)
    Q_PROPERTY(QVariantList householdUsers READ getHouseholdUsers NOTIFY householdUsersChanged)

    Q_PROPERTY(QVariantList choreNames READ getChoreNames NOTIFY curHouseholdChanged)
    Q_PROPERTY(QVariantList choreLocations READ getChoreLocations NOTIFY curHouseholdChanged)
    Q_PROPERTY(QVariantList choreDates READ getChoreDates NOTIFY curHouseholdChanged)
    Q_PROPERTY(QVariantList choreStatuses READ getChoreStatuses NOTIFY curHouseholdChanged)
    Q_PROPERTY(QVariantList choreDueDates READ getChoreDueDates NOTIFY curHouseholdChanged)
    Q_PROPERTY(QVariantList choreDoesReccurs READ getChoreDoesReccurs NOTIFY curHouseholdChanged)
    Q_PROPERTY(QVariantList choreReccurances READ getChoreReccurances NOTIFY curHouseholdChanged)
    Q_PROPERTY(int curChoreIndex READ getCurChoreIndex WRITE setCurChoreIndex NOTIFY curChoreIndexChanged)

public:
    Q_INVOKABLE Backend();

    Q_INVOKABLE void set_household(int index);
    Q_INVOKABLE void set_chore(int index);

    QString get_user_name() const;
    QString get_cur_household_name();

    QVariantList getHouseholdNames();
    QVariantList getHouseholdUsers();

    QVariantList getChoreNames();
    QVariantList getChoreLocations();
    QVariantList getChoreDates();
    QVariantList getChoreStatuses();
    QVariantList getChoreDueDates();
    QVariantList getChoreDoesReccurs();
    QVariantList getChoreReccurances();

    int getCurChoreIndex();
    void setCurChoreIndex(int index);

    Q_INVOKABLE void set_chore_status(int index, bool status);
    Q_INVOKABLE void add_chore(QString name, QString location, QString dueDate, bool doesRecurr, QString recurrence);
    Q_INVOKABLE void edit_chore(QString name, QString location, QString dueDate, bool doesRecurr, QString recurrence);
    Q_INVOKABLE void delete_chore();
private:
    User *_user;
    std::shared_ptr<Household> _curHouseHold;
    int _curChoreIndex = -1;

    // User *_testUser;
    // User *_testUser1;
    // User *_testUser2;
    // User *_testUser3;
    // User *_testUser4;
    // std::shared_ptr<Household> _houseHold1;
    // std::shared_ptr<Household> _houseHold2;
    // std::shared_ptr<Household> _houseHold3;

    //void hardCodedConstructor();
signals:
    void userDataChanged();
    void householdNamesChanged();
    void householdUsersChanged();
    void curHouseholdChanged();
    void curChoreIndexChanged();
};
#endif // BACKEND_H
