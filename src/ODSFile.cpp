

#include "ODSFile.hpp"
#include <QDebug>

static const QString nameValue = "name";
static const QString typeValue = "type";
static const QString groupPkValue = "group_pk";
static const QString fileSizeValue = "file_size";
static const QString fileIdValue = "fileID";
static const QString expirationDateValue = "expiration_date";
static const QString classificationValue = "classification";
static const QString logMeValue = "log_me";
static const QString commentValue = "comment";
static const QString logDeValue = "log_de";


ODSFile::ODSFile(QObject *parent) {}

ODSFile::ODSFile(QVariantMap fileMap) :
				QObject() {

}

QString ODSFile::name() const {
	return mName;
}
void ODSFile::setName(QString newName) {
	if (newName != mName) {
		mName = newName;
		emit nameChanged(newName);
	}
}

QString ODSFile::expires() const {
	return mExpires;
}
void ODSFile::setExpires(QString newExpires) {
	if (newExpires != mExpires) {
		mExpires = newExpires;
		emit expiresChanged(newExpires);
	}
}

QString ODSFile::comment() const {
	return mComment;
}
void ODSFile::setComment(QString newComment) {
	if (newComment != mComment) {
		mComment = newComment;
		emit commentChanged(newComment);
	}
}

QString ODSFile::createdBy() const {
	return mCreatedBy;
}
void ODSFile::setCreatedBy(QString newCreatedBy) {
	if (newCreatedBy != mCreatedBy) {
		mCreatedBy = newCreatedBy;
		emit createdByChanged(newCreatedBy);
	}
}

QString ODSFile::createdAt() const {
	return mCreatedAt;
}
void ODSFile::setCreatedAt(QString newCreatedAt) {
	if (newCreatedAt != mCreatedAt) {
		mCreatedAt = newCreatedAt;
		emit createdByChanged(newCreatedAt);
	}
}

int ODSFile::id() const {
	return mId;
}
void ODSFile::setId(int id) {
	if (id != mId) {
		mId = id;
		emit idChanged(id);
	}
}

int ODSFile::level() const {
	return mLevel;
}
void ODSFile::setLevel(int level) {
	if (level != mLevel) {
		mLevel = level;
		emit levelChanged(level);
	}
}

int ODSFile::containerId() const {
	return mContainerId;
}
void ODSFile::setContainerId(int containerId) {
	if (containerId != mContainerId) {
		mContainerId = containerId;
		emit containerIdChanged(containerId);
	}
}

int ODSFile::fileSize() const {
	return mContainerId;
}
void ODSFile::setFileSize(int fileSize) {
	if (fileSize != mContainerId) {
		mContainerId = fileSize;
		emit fileSizeChanged(fileSize);
	}
}

int ODSFile::classification() const {
	return mClassification;
}
void ODSFile::setClassification(int classification) {
	if (classification != mClassification) {
		mClassification = classification;
		emit classificationChanged(classification);
	}
}


ODSFile::~ODSFile() {
	//
}

