/*
** Generated by X-Designer
*/
#ifndef _uisearch_h
#define _uisearch_h

#define XD_MOTIF

#include <xdclass.h>

class search_shell_c: public xd_XmDialog_c {
public:
	virtual void create (Widget parent, char *widget_name = NULL);
	Widget regex_, icase_, subst_, fname_, toggle11_, toggle12_, toggle13_;
protected:
	Widget search_shell;
	Widget form_;
	Widget button_search;
	Widget button_close;
	Widget what_text_;
	Widget what_;
	Widget where_rowcol_;
	Widget where_;
	Widget status_rowcol_;
	Widget status_;
	Widget type_rowcol_;
	Widget type_;
	Widget special_rowcol_;
	Widget special_;
	Widget timed_, misc_;
	Widget timed_rowcol_, timed_rowcol2_, misc_rowcol_;
	Widget timed_text_since_, timed_text_from_;
public:
	static void radioCB( Widget, XtPointer, XtPointer );
	virtual void radioCB( Widget, XtPointer ) = 0;

	static void miscCB( Widget, XtPointer, XtPointer );
	virtual void miscCB( Widget, XtPointer ) = 0;
	static void timedCB( Widget, XtPointer, XtPointer );
	virtual void timedCB( Widget, XtPointer ) = 0;
	static void specialCB( Widget, XtPointer, XtPointer );
	virtual void specialCB( Widget, XtPointer ) = 0;
	static void typeCB( Widget, XtPointer, XtPointer );
	virtual void typeCB( Widget, XtPointer ) = 0;
	static void statusCB( Widget, XtPointer, XtPointer );
	virtual void statusCB( Widget, XtPointer ) = 0;
	static void whereCB( Widget, XtPointer, XtPointer );
	virtual void whereCB( Widget, XtPointer ) = 0;
	static void whatCB( Widget, XtPointer, XtPointer );
	virtual void whatCB( Widget, XtPointer ) = 0;
	static void mapCB( Widget, XtPointer, XtPointer );
	virtual void mapCB( Widget, XtPointer ) = 0;
	static void closeCB( Widget, XtPointer, XtPointer );
	virtual void closeCB( Widget, XtPointer ) = 0;
	static void searchCB( Widget, XtPointer, XtPointer );
	virtual void searchCB( Widget, XtPointer ) = 0;
};

typedef search_shell_c *search_shell_p;


extern search_shell_p search_shell;


#endif