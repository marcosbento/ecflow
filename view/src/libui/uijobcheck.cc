/*
** Generated by X-Designer
*/
/*
**LIBS: -lXm -lXt -lX11
*/

#include <stdlib.h>
#include <X11/Xatom.h>
#include <X11/Intrinsic.h>
#include <X11/Shell.h>

#include <Xm/Xm.h>
#include <Xm/DialogS.h>
#include <Xm/Form.h>
#include <Xm/PushB.h>
#include <Xm/RowColumn.h>
#include <Xm/ScrollBar.h>
#include <Xm/Text.h>
#include <Xm/TextF.h>

#include "uijobcheck.h"

jobcheck_p jobcheck_form = (jobcheck_p) NULL;



void jobcheck_form_c::create (Widget parent, char *widget_name)
{
	Widget children[3];      /* Children to manage */
	Arg al[64];                    /* Arg List */
	register int ac = 0;           /* Arg Count */
	Widget scrolledText4 = (Widget)NULL;
	Widget button3 = (Widget)NULL;

	if ( !widget_name )
		widget_name = "jobcheck_form";

	XtSetArg(al[ac], XmNautoUnmanage, FALSE); ac++;
	jobcheck_form = XmCreateForm ( parent, widget_name, al, ac );
	ac = 0;
	_xd_rootwidget = jobcheck_form;
	XtSetArg(al[ac], XmNeditable, FALSE); ac++;
	XtSetArg(al[ac], XmNcursorPositionVisible, FALSE); ac++;
	XtSetArg(al[ac], XmNeditMode, XmMULTI_LINE_EDIT); ac++;
	text_ = XmCreateScrolledText ( jobcheck_form, "text_", al, ac );
	ac = 0;
	scrolledText4 = XtParent ( text_ );

	XtSetArg(al[ac], XmNhighlightThickness, 1); ac++;// 201106
	XtSetArg(al[ac], XmNshadowThickness, 1); ac++;
	XtSetArg(al[ac], XmNeditable, FALSE); ac++;
	XtSetArg(al[ac], XmNcursorPositionVisible, FALSE); ac++;
	name_ = XmCreateTextField ( jobcheck_form, "name_", al, ac );
	ac = 0;// 201106

	XtSetArg(al[ac], XmNspacing, 0); ac++;
	XtSetArg(al[ac], XmNmarginWidth, 0); ac++;
	XtSetArg(al[ac], XmNmarginHeight, 0); ac++;
	XtSetArg(al[ac], XmNorientation, XmHORIZONTAL); ac++;
	tools_ = XmCreateRowColumn ( jobcheck_form, "tools_", al, ac );
	ac = 0;
	button3 = XmCreatePushButton ( tools_, "Update", al, ac );

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	// XtSetArg(al[ac], XmNtopWidget, tools_); ac++;
	XtSetArg(al[ac], XmNtopWidget, name_); ac++; // 201106
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 0); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 0); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 0); ac++;
	XtSetValues ( scrolledText4,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 0); ac++;
	XtSetValues ( tools_,al, ac );
	ac = 0;
	XtManageChild(text_);
	XtAddCallback (button3, XmNactivateCallback,&jobcheck_form_c:: refreshCB, (XtPointer) this);
	children[ac++] = button3;
	XtManageChildren(children, ac);
	ac = 0;
	children[ac++] = tools_;
	XtManageChildren(children, ac);
}

void jobcheck_form_c::refreshCB( Widget widget, XtPointer client_data, XtPointer call_data )
{
	jobcheck_form_p instance = (jobcheck_form_p) client_data;
	instance->refreshCB ( widget, call_data );
}

