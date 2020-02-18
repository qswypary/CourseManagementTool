#include <stdexcept>
#include "CourseInfo.h"

CourseInfo::CourseInfo() = default;

CourseInfo::CourseInfo(QString name, const QVector<QString> &content) :
    _name(name)
{
    for (auto item : content) {
        _info.append(InfoColumn{item, false});
    }
}

QString CourseInfo::get_name() const { return _name; }

QString CourseInfo::get_info(int info_index) const {
    return _info.at(info_index).content;
}
QString CourseInfo::operator[](int i) const {
    return get_info(i);
}

void CourseInfo::set_url(int info_index, bool value) {
    _info[info_index].is_url = value;
}
bool CourseInfo::is_url(int info_index) const {
    return _info.at(info_index).is_url;
}
