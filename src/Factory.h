#ifndef FACTORY_H_
#define FACTORY_H_ 

#include <string>
#include <set>
#include "SymbolStore.h"
#include "ObjectPackage.h"
#include "Callback.h"

class ObjectFile;
class Entity;

class Factory
{
	friend class Analyser;
public:
	Factory(DependencyAddedEvent&,
			DependencyAddedEvent&,
			SymbolAdded&);
	ObjectPackage* CreatePackage(const std::string& name);
	ObjectFile* CreateObject(const std::string& name);
private:
	std::set<ObjectPackage> m_PackageSet;
	std::vector<Entity*> m_ObjectFiles;
	SymbolStore m_symbols;
	DependencyAddedEvent& m_ObjectGraph;
	DependencyAddedEvent& m_PackageGraph;
	SymbolAdded& on_symbol_added;
};

#endif

