/*
** Generated by X-Designer
*/
#ifndef _uiask_h
#define _uiask_h

#define XD_MOTIF

#include <xdclass.h>

class ask_shell_c: public xd_XmDialog_c {
public:
	virtual void create (Widget parent, char *widget_name = NULL);
protected:
	Widget ask_shell;
	Widget form_;
	Widget label_;
	Widget value_;
public:
	static void helpCB( Widget, XtPointer, XtPointer );
	virtual void helpCB( Widget, XtPointer ) = 0;
	static void cancelCB( Widget, XtPointer, XtPointer );
	virtual void cancelCB( Widget, XtPointer ) = 0;
	static void okCB( Widget, XtPointer, XtPointer );
	virtual void okCB( Widget, XtPointer ) = 0;
};

typedef ask_shell_c *ask_shell_p;


extern ask_shell_p ask_shell;


#endif