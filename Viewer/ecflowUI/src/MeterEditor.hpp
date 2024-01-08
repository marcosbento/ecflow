/*
 * Copyright 2009- ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

#ifndef ecflow_viewer_MeterEditor_HPP
#define ecflow_viewer_MeterEditor_HPP

#include "AttributeEditor.hpp"
#include "VInfo.hpp"
#include "ui_MeterEditorWidget.h"

class MeterEditor;

class MeterEditorWidget : public QWidget, protected Ui::MeterEditorWidget {
    friend class MeterEditor;

public:
    explicit MeterEditorWidget(QWidget* parent = nullptr);
};

class MeterEditor : public AttributeEditor {
    Q_OBJECT

public:
    explicit MeterEditor(VInfo_ptr, QWidget* parent = nullptr);
    ~MeterEditor() override;

protected Q_SLOTS:
    void slotValueChanged(int);

protected:
    void apply() override;
    void resetValue() override;
    bool isValueChanged() override;
    void readSettings();
    void writeSettings();

    MeterEditorWidget* w_;
    int oriVal_;
};

#endif /* ecflow_viewer_MeterEditor_HPP */
