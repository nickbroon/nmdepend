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

#ifndef ENTITY_H
#define ENTITY_H

#include <string>

template<class P>
class IParent
{
public:
  IParent() : m_Parent(NULL)
  {
  }
  
  void SetParent(P& p)
  {
    m_Parent = &p;
  }
  P* Parent()
  {
    return m_Parent;
  }
private:
  P* m_Parent;
};

class Entity
{
public:
  Entity(const std::string&);
  const std::string& Name() const;
  friend std::ostream& operator<<(std::ostream& out, const Entity& e)
  {
    return out << e.m_Name;
  }
private:
  std::string m_Name;
};

#endif

