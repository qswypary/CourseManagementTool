#ifndef COURSEINFO_H
#define COURSEINFO_H

#include <QString>
#include <QVector>

class CourseInfo
{
private:
    struct InfoColumn {
        QString content;
        bool is_url;
    };

public:
    CourseInfo();
    CourseInfo(QString name, const QVector<QString> &content = QVector<QString>());

    QString get_name() const;

    QString get_info(int info_index) const;
    QString operator[](int i) const;

    void set_url(int info_index, bool value = true);
    bool is_url(int info_index) const;

private:
    QString _name;

    QVector<InfoColumn> _info;
};

#endif // COURSEINFO_H
