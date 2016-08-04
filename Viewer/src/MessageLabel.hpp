//============================================================================
// Copyright 2016 ECMWF.
// This software is licensed under the terms of the Apache Licence version 2.0
// which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
// In applying this licence, ECMWF does not waive the privileges and immunities
// granted to it by virtue of its status as an intergovernmental organisation
// nor does it submit to any jurisdiction.
//
//============================================================================

#ifndef MESSAGELABEL_HPP_
#define MESSAGELABEL_HPP_

#include <QWidget>

class QHBoxLayout;
class QLabel;
class QProgressBar;

class MessageLabel : public QWidget
{
public:
	explicit MessageLabel(QWidget *parent=0);

    enum Type {NoType,InfoType,WarningType,ErrorType,TipType};

	void showInfo(QString);
	void showWarning(QString);
    void showError(QString);
    void showTip(QString);
	void startLoadLabel();
	void stopLoadLabel();
    void startProgress(int max=0);
    void stopProgress();
    void progress(QString text,int value);
	void setShowTypeTitle(bool);
	void clear();
    void setNarrowMode(bool);

private:
	void showMessage(const Type&,QString);

	bool showTypeTitle_;
    bool narrowMode_;
	Type currentType_;
	QLabel *pixLabel_;
	QLabel* msgLabel_;
	QLabel* loadLabel_;
	QHBoxLayout* layout_;
    QWidget* progWidget_;
    QLabel*  progLabel_;
    QProgressBar* progBar_;

};

#endif

