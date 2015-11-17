//============================================================================
// Copyright 2014 ECMWF.
// This software is licensed under the terms of the Apache Licence version 2.0
// which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
// In applying this licence, ECMWF does not waive the privileges and immunities
// granted to it by virtue of its status as an intergovernmental organisation
// nor does it submit to any jurisdiction.
//
//============================================================================

#include "StringMatchCombo.hpp"

#include <QVariant>

StringMatchCombo::StringMatchCombo(QWidget* parent) : QComboBox(parent)
{
	//addItem("Exact match","=");
	addItem("Contains",NodeQueryStringOption::ContainsMatch);
	addItem("Matches",NodeQueryStringOption::WildcardMatch);
	addItem("Regexp",NodeQueryStringOption::RegexpMatch);

	setCurrentIndex(1);
}

NodeQueryStringOption::MatchMode StringMatchCombo::matchMode(int index) const
{
	if(index >=0 && index < count())
	{
		return static_cast<NodeQueryStringOption::MatchMode>(itemData(index).toInt());
	}
	return NodeQueryStringOption::WildcardMatch;
}

NodeQueryStringOption::MatchMode StringMatchCombo::currentMatchMode() const
{
	return matchMode(currentIndex());

}

void StringMatchCombo::setMatchMode(NodeQueryStringOption::MatchMode mode)
{
	int im=static_cast<int>(mode);
	for(int i=0; i < count(); i++)
	{
		if(itemData(i).toInt() == im)
		{
			setCurrentIndex(i);
		}
	}
}
