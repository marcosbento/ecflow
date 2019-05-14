/*
** Generated by X-Designer
*/
#ifndef _uimenu_h
#define _uimenu_h

#define XD_MOTIF

#include <xdclass.h>

class menu_form_c: public xd_XmForm_c {
public:
	virtual void create (Widget parent, char *widget_name = NULL);
protected:
	Widget menu_form;
	Widget form_;
	Widget list_;
	Widget add_;
	Widget update_;
	Widget remove_;
	Widget title_;
	Widget actions_;
public:
	static void updateCB( Widget, XtPointer, XtPointer );
	virtual void updateCB( Widget, XtPointer ) = 0;
	static void changedCB( Widget, XtPointer, XtPointer );
	virtual void changedCB( Widget, XtPointer ) = 0;
	static void browseCB( Widget, XtPointer, XtPointer );
	virtual void browseCB( Widget, XtPointer ) = 0;
	static void removeCB( Widget, XtPointer, XtPointer );
	virtual void removeCB( Widget, XtPointer ) = 0;
	static void addCB( Widget, XtPointer, XtPointer );
	virtual void addCB( Widget, XtPointer ) = 0;
	static void menuCB( Widget, XtPointer, XtPointer );
	virtual void menuCB( Widget, XtPointer ) = 0;
};

typedef menu_form_c *menu_form_p;


extern menu_form_p menu_form;


#endif