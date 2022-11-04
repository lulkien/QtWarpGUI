#include "TabListModel.h"
#include "Constants.h"
#include "Common.h"

TabListModel::TabListModel()
{
    LOG;
    initialize();
}

TabListModel::~TabListModel()
{
    LOG;
    for (int i = 0; i < this->mTabList.count(); i++)
    {
        if (nullptr != this->mTabList.at(i))
        {
            delete this->mTabList.at(i);
        }
    }
    this->mTabList.clear();
}

int TabListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mTabList.count();
}

QVariant TabListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= rowCount())
        return QVariant();
    TabInfo *item = mTabList.at(index.row());
    switch (role) {
    case Name:
        return item->name;
    case Icon:
        return item->icon;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> TabListModel::roleNames() const
{
    QHash<int, QByteArray> table;
    table[Name] = "Name";
    table[Icon] = "Icon";
    return table;
}

void TabListModel::initialize()
{
    LOG;
    beginResetModel();
    this->mTabList.clear();
    this->mTabList.append(new TabInfo("Home", Constants::instance().HOME_ICO()));
    this->mTabList.append(new TabInfo("User", Constants::instance().USER_ICO()));
    this->mTabList.append(new TabInfo("Setup", Constants::instance().SETUP_ICO()));
    this->mTabList.append(new TabInfo("Info", Constants::instance().INFO_ICO()));
    endResetModel();
}
