

#include "ODSRoom.hpp"
#include <QDebug>

//static const QString isGroupValue = "is_group";
//static const QString fileSizeValue = "file_size";
static const QString nodesValue = "nodes";
static const QString nameValue = "name";
//static const QString isAssignedValue = "is_assigned";
//static const QString parentValue = "parent";
//static const QString typeValue = "type";
static const QString groupPkValue = "group_pk";


ODSRoom::ODSRoom(QObject *parent) {}

ODSRoom::ODSRoom(QVariantMap roomMap) :
				QObject(), mRoomsMap(roomMap) {
	mName = mRoomsMap.value(nameValue, "").toString();
	mId = mRoomsMap.value(groupPkValue, 0).toInt();
	mDisplayType = "R";
	mDisplayIcon = "../images/rooms-icon.png";
	mNodes = mRoomsMap.value(nodesValue).toList();
	mChildren = mNodes.size();
	mDisplayTitle = mName;
	if (mChildren > 0) {
		mDisplaySubtitle = tr("contains ") + QString::number(mChildren) + tr(" Files / Folders");
	} else {
		mDisplaySubtitle = tr("empty Room");
	}

}

QString ODSRoom::name() const {
	return mName;
}
void ODSRoom::setName(QString newName) {
	if (newName != mName) {
		mName = newName;
		emit nameChanged(newName);
	}
}

int ODSRoom::id() const {
	return mId;
}
void ODSRoom::setId(int id) {
	if (id != mId) {
		mId = id;
		emit idChanged(id);
	}
}

int ODSRoom::level() const {
	return mLevel;
}
void ODSRoom::setLevel(int level) {
	if (level != mLevel) {
		mLevel = level;
		emit levelChanged(level);
	}
}

int ODSRoom::children() const {
	return mChildren;
}

QString ODSRoom::displayType() const {
	return mDisplayType;
}

QString ODSRoom::displayIcon() const {
	return mDisplayIcon;
}

QString ODSRoom::displayTitle() const {
	return mDisplayTitle;
}

QString ODSRoom::displaySubtitle() const {
	return mDisplaySubtitle;
}

QVariantList ODSRoom::nodes() const {
	return mNodes;
}


ODSRoom::~ODSRoom() {
	// TODO Auto-generated destructor stub
}

