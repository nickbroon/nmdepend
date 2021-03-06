// Copyright (c) 2004 E.J. Pronk and R.E.W. van Beusekom
//
// This file is part of Nmdepend.
// 
// Nmdepend is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// Nmdepend is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Nmdepend; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#ifndef CALLBACK_H
#define CALLBACK_H

#include "Entity.h"
#include <iostream>

using namespace std;

class DependencyAddedEvent
{
public:
	virtual ~DependencyAddedEvent() {}
	virtual void operator()(Entity&, Entity&) = 0;
};

class SymbolAdded
{
public:
	virtual ~SymbolAdded() {}
	virtual void operator()(const std::string&)
	{
	}
};

std::string Demangled(const std::string& name);

struct PrintSymbols : public SymbolAdded
{
	virtual void operator()(const std::string& symbol)
	{
		std::cout << symbol << std::endl;
	}
};

struct PrintSymbolsAndDemangle : public SymbolAdded
{
	void operator()(const std::string& symbol)
	{
		std::cout << Demangled(symbol) << std::endl;
	}
};

#endif
