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
#include <Xm/List.h>
#include <Xm/ScrollBar.h>


#include "uiusers.h"

users_form_p users_form = (users_form_p) NULL;



void users_form_c::create (Widget parent, char *widget_name)
{
	Widget children[3];      /* Children to manage */
	Arg al[64];                    /* Arg List */
	register int ac = 0;           /* Arg Count */
	Widget form2 = (Widget)NULL;
	Widget scrolledList1 = (Widget)NULL;

	if ( !widget_name )
		widget_name = "users_form";

	XtSetArg(al[ac], XmNautoUnmanage, FALSE); ac++;
	users_form = XmCreateForm ( parent, widget_name, al, ac );
	ac = 0;
	_xd_rootwidget = users_form;
	XtSetArg(al[ac], XmNautoUnmanage, FALSE); ac++;
	form2 = XmCreateForm ( users_form, "form2", al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNselectionPolicy, XmMULTIPLE_SELECT); ac++;
	XtSetArg(al[ac], XmNlistSizePolicy, XmRESIZE_IF_POSSIBLE); ac++;
	list_ = XmCreateScrolledList ( form2, "list_", al, ac );
	ac = 0;
	scrolledList1 = XtParent ( list_ );


	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetValues ( form2,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetValues ( scrolledList1,al, ac );
	ac = 0;

	XtManageChild(list_);
	children[ac++] = form2;
	XtManageChildren(children, ac);
}

void users_form_c::sendCB( Widget widget, XtPointer client_data, XtPointer call_data )
{
	users_form_p instance = (users_form_p) client_data;
	instance->sendCB ( widget, call_data );
}

