//============================================================================
// Copyright 2014 ECMWF.
// This software is licensed under the terms of the Apache Licence version 2.0
// which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
// In applying this licence, ECMWF does not waive the privileges and immunities
// granted to it by virtue of its status as an intergovernmental organisation
// nor does it submit to any jurisdiction.
//============================================================================

#ifndef TREENODEMODEL_H
#define TREENODEMODEL_H

#include <QAbstractItemModel>

#include "AbstractNodeModel.hpp"
#include "Node.hpp"
#include "VAttribute.hpp"
#include "Viewer.hpp"
#include "VInfo.hpp"

class AttributeFilter;
class NodeFilterDef;
class ServerFilter;
class ServerHandler;
class VModelServer;
class VTreeModelData;
class VTreeNode;
class VTreeServer;

class TreeNodeModel : public AbstractNodeModel
{
Q_OBJECT

public:
   	TreeNodeModel(ServerFilter* serverFilter,NodeFilterDef* filterDef,
                  AttributeFilter *atts,IconFilter* icons,QObject *parent=0);

   	int columnCount (const QModelIndex& parent = QModelIndex() ) const;
   	int rowCount (const QModelIndex& parent = QModelIndex() ) const;

   	Qt::ItemFlags flags ( const QModelIndex & index) const;
   	QVariant data (const QModelIndex& , int role = Qt::DisplayRole ) const;
	QVariant headerData(int,Qt::Orientation,int role = Qt::DisplayRole ) const;

   	QModelIndex index (int, int, const QModelIndex& parent = QModelIndex() ) const;
   	QModelIndex parent (const QModelIndex & ) const;

    QModelIndex nodeToIndex(const VTreeNode*,int column=0) const;
    QModelIndex nodeToIndex(const VNode*,int column=0) const;
    VTreeServer* indexToServer(const QModelIndex & index) const;
    VTreeServer* nameToServer(const std::string&) const;
    VInfo_ptr nodeInfo(const QModelIndex& index);

   	VModelData* data() const;

public Q_SLOTS:
	void slotServerAddBegin(int row);
	void slotServerAddEnd();
    void slotServerRemoveBegin(VModelServer*,int);
    void slotServerRemoveEnd(int);

    void slotNodeChanged(VTreeServer*,const VTreeNode*);
    void slotAttributesChanged(VTreeServer*,const VTreeNode*);
    void slotBeginAddRemoveAttributes(VTreeServer*,const VTreeNode*,int,int);
    void slotEndAddRemoveAttributes(VTreeServer*,const VTreeNode*,int,int);
    void slotBeginFilterUpdateRemove(VTreeServer*,const VTreeNode*,int);
    void slotEndFilterUpdateRemove(VTreeServer*,const VTreeNode*,int);
    void slotBeginFilterUpdateAdd(VTreeServer*,const VTreeNode*,int);
    void slotEndFilterUpdateAdd(VTreeServer*,const VTreeNode*,int);

	//void slotResetBranch(VModelServer*,const VNode*);
    void slotDataChanged(VModelServer*);
    void slotBeginServerScan(VModelServer* server,int);
	void slotEndServerScan(VModelServer* server,int);
	void slotBeginServerClear(VModelServer* server,int);
	void slotEndServerClear(VModelServer* server,int);

Q_SIGNALS:
    void clearBegun(const VTreeNode*);
    void scanEnded(const VTreeNode*);
    void filterUpdateRemoveBegun(const VTreeNode*);
    void filterUpdateAddEnded(const VTreeNode*);
    void filterChangeBegun();
    void filterChangeEnded();

private:
	bool isServer(const QModelIndex & index) const;
	bool isNode(const QModelIndex & index) const;
	bool isAttribute(const QModelIndex & index) const;

    ServerHandler* indexToServerHandler(const QModelIndex & index) const;
    QModelIndex serverToIndex(VModelServer* server) const;
	QModelIndex serverToIndex(ServerHandler*) const;

    QModelIndex nodeToIndex(VTreeServer*,const VTreeNode*,int column=0) const;
    VTreeNode* indexToNode( const QModelIndex & index) const;

	QVariant serverData(const QModelIndex& index,int role) const;
	QVariant nodeData(const QModelIndex& index,int role) const;
	QVariant attributesData(const QModelIndex& index,int role) const;

	//Attribute filter
	VTreeModelData* data_;
	AttributeFilter* atts_;
	IconFilter* icons_;
};


#endif
