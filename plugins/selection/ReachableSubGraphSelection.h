/**
 *
 * This file is part of Tulip (www.tulip-software.org)
 *
 * Authors: David Auber and the Tulip development Team
 * from LaBRI, University of Bordeaux 1 and Inria Bordeaux - Sud Ouest
 *
 * Tulip is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * Tulip is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 */
#ifndef Tulip_REACHABLESUBGRAPHELECTION_H
#define Tulip_REACHABLESUBGRAPHELECTION_H

#include <tulip/TulipPluginHeaders.h>

/** \addtogroup selection */
/*@{*/
/**
 * This selection plugin enables to find all nodes and edges at a fixed distance of a set of nodes.
 * It takes three parameters :
 * - <b>int</b> distance
 * - <b>int</b> direction : 0 means directed, 1 reverse directed, 2 undirected
 * - <b>BooleanProperty *</b> startingnodes : the selected nodes of this BooleanProperty
 * (those whose associated value is true) will be used as starting nodes.
 *
 *  \author David Auber, LaBRI University Bordeaux I France:
 *   auber@tulip-software.org
 */
class ReachableSubGraphSelection:public tlp::BooleanAlgorithm {
public:
  PLUGININFORMATIONS("Reachable Sub-Graph","David Auber","01/12/1999","Alpha","1.0", "Selection")
  ReachableSubGraphSelection(const tlp::PluginContext* context);
  ~ReachableSubGraphSelection();
  bool run();
};
/*@}*/
#endif



