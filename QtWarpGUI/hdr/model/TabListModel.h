#ifndef TABLISTMODEL_H
#define TABLISTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QString>
#include <QList>
#include <QHash>
#include <QUrl>

struct TabInfo {
    QString name;
    QUrl icon;
    TabInfo(const QString &name, const QUrl &icon)
    {
        this->name = name;
        this->icon = icon;
    }
};

class TabListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ItemRoles {
        Name = Qt::UserRole + 1,
        Icon,
    };
    TabListModel();
    virtual ~TabListModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    void initialize();

private:
    QList<TabInfo *> mTabList;
};

#endif // TABLISTMODEL_H
