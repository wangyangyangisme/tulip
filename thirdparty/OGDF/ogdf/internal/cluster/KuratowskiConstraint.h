/*
 * $Revision: 2059 $
 * 
 * last checkin:
 *   $Author: klein $ 
 *   $Date: 2010-10-16 16:49:07 +0200 (Sat, 16 Oct 2010) $ 
 ***************************************************************/
 
/** \file
 * \brief Declaration of a constraint class for the Branch&Cut algorithm
 * for the Maximum C-Planar SubGraph problem.
 * 
 * These constraints represent the planarity-constraints belonging to the
 * ILP formulation. These constraints are dynamically separated.
 * For the separation the planarity test algorithm by Boyer and Myrvold is used.
 * 
 * \author Mathias Jansen
 * 
 * 
 * \par License:
 * This file is part of the Open Graph Drawing Framework (OGDF).
 *
 * Copyright (C). All rights reserved.
 * See README.txt in the root directory of the OGDF installation for details.
 * 
 * \par
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * Version 2 or 3 as published by the Free Software Foundation
 * and appearing in the files LICENSE_GPL_v2.txt and
 * LICENSE_GPL_v3.txt included in the packaging of this file.
 *
 * \par
 * In addition, as a special exception, you have permission to link
 * this software with the libraries of the COIN-OR Osi project
 * (http://www.coin-or.org/projects/Osi.xml), all libraries required
 * by Osi, and all LP-solver libraries directly supported by the
 * COIN-OR Osi project, and distribute executables, as long as
 * you follow the requirements of the GNU General Public License
 * in regard to all of the software in the executable aside from these
 * third-party libraries.
 * 
 * \par
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * \par
 * You should have received a copy of the GNU General Public 
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 * 
 * \see  http://www.gnu.org/copyleft/gpl.html
 ***************************************************************/

#ifndef OGDF_KURATOWSKI_CONSTRAINT_H
#define OGDF_KURATOWSKI_CONSTRAINT_H

#include <ogdf/planarity/BoyerMyrvold.h>
#include <ogdf/internal/cluster/Cluster_EdgeVar.h>
#include <ogdf/internal/cluster/basics.h>
//#include <ogdf/internal/cluster/MaxCPlanar_Master.h>
//#include <abacus/master.h>

#include <abacus/constraint.h>

namespace ogdf {


class KuratowskiConstraint : public ABA_CONSTRAINT {
	
public:

	KuratowskiConstraint(ABA_MASTER *master, int nEdges, SListPure<nodePair> &ks);
	
	virtual ~KuratowskiConstraint();
	
	// Computes and returns the coefficient for the given variable
	virtual double coeff(ABA_VARIABLE *v);
	
	void printMe(ostream& out) {
		out << "[KuraCon: ";
		forall_listiterators(nodePair, it, m_subdivision) {
			(*it).printMe(out);
			out << ",";
		}
		out << "]";
	}
	
private:

	// The subdivision containing edges forming a SubGraph that is not planar
	List<nodePair> m_subdivision;
	
};

}

#endif
