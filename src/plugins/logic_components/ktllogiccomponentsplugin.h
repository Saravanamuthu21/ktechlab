/***************************************************************************
 *   Copyright (C) 2009 Julian Bäume <julian@svg4all.de>                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef KTLLOGICPLUGIN_H
#define KTLLOGICPLUGIN_H

#include "interfaces/component/icomponentplugin.h"

#include <QVariantList>

namespace KTechLab
{

class KTLLogicFactory;
class LogicElementFactory;

class KTLLogicComponentsPlugin : public IComponentPlugin
{
    Q_OBJECT
public:
    KTLLogicComponentsPlugin( QObject *parent, const QVariantList& args );
    virtual ~KTLLogicComponentsPlugin();
    virtual void unload();

protected:
    /**
     * Get a plugin that is able to handle KTechLab documents.
     * These must implement the \class KDevelop::IDocument interface
     * and support the "application/x-circuit" mime-type.
     *
     ** FIXME: this is bad behaviour for a base-class.
     ** Add the mime-type as a parameter, may be, make this method
     ** virtual and at least allow to specify the result
     ** (for now only the first found plugin is returned)
     * \return the plugin capable of handling KTechLab documents
     */
    IDocumentPlugin *documentPlugin() const;

private:
    void init();

    KTLLogicFactory * m_componentFactory;
};

}

#endif
