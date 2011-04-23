/*! \file QuadTree.h
 * \brief Header file for QuadTree.cc.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_TREE_QUADTREE_QUADTREE_H_)
#define _WIP3DMATH_TREE_QUADTREE_QUADTREE_H_

#include <list>

namespace wip3dmath {

template<class TObject> class QuadTree {
 public:
    // TObject must expose methods is_east, is_west, is_north, is_south that
    // produce uniform results. 
    // is_north and is_south are mutually exclusive.
    // is_east and is_west are mutually exclusive.
    // No pair of real numbers should be either both or neither of one of the above pairs.
    // bool is_north(double x, double y);
    // sidelen should be the length of one side of the square enclosing all items provided.

    QuadTree(std::list<TObject> items, int minobjects, double sidelen, double originx=0.0, double originy=0.0);
    ~QuadTree();
    std::list<TObject> find_near(TObject item);
 private:
    int minobjects;
    bool isleaf;    // if (!isleaf) objects empty and nw, ne, se, sw valid pointers.
                    // else nw, ne, se, sw are not valid pointers, and objects contains
                    // at least minobjects elements.
    double            x, y;
    QuadTree<TObject> *nw, *ne, *se, *sw;
    std::list<TObject> objects;
};

}; // namespace wip3dmath

#endif /* !defined(_WIP3DMATH_TREE_QUADTREE_QUADTREE_H_) */
