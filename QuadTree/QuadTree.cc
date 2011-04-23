/*! \file QuadTree.cc
 * \brief QuadTree class.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#include "wip3dmath.h"

template<class TObject> QuadTree<TObject>::QuadTree(std::list<TObject> items, 
                            int minobjects, double sidelen, double originx, double originy) {
    this->minobjects = minobjects;
    if ( items.count() <= minobjects ) {
        isleaf = true;
        objects = items;
    } else {
        isleaf = false;
        this->x = originx;
        this->y = originy;
        std::list<TObject> directions[4];    // 0 = ne, 1 = nw, 2 = se, 3 = sw.
        typedef typename std::list<TObject>::iterator LTOI;
        for ( LTOI j = items.begin() ; j != items.end() ; j++ ) {
            if ( j->is_north(originx, originy) ) {
                if ( j->is_east(originx, originy) )
                    directions[0].insert(directions[0].end(), *j);
                else
                    directions[1].insert(directions[1].end(), *j);
            } else {
                if ( j->is_east(originx, originy) )
                    directions[2].insert(directions[2].end(), *j);
                else
                    directions[3].insert(directions[3].end(), *j);                
            }
        }

        this->ne = new QuadTree<TObject>(directions[0], minobjects, 
                                         sidelen/2.0, originx+sidelen/4.0, originy+sidelen/4.0);
        this->nw = new QuadTree<TObject>(directions[1], minobjects, 
                                         sidelen/2.0, originx-sidelen/4.0, originy+sidelen/4.0);
        this->se = new QuadTree<TObject>(directions[2], minobjects, 
                                         sidelen/2.0, originx+sidelen/4.0, originy-sidelen/4.0);
        this->sw = new QuadTree<TObject>(directions[3], minobjects, 
                                         sidelen/2.0, originx-sidelen/4.0, originy-sidelen/4.0);
    }
}

template<class TObject> QuadTree<TObject>::~QuadTree() {
    delete this->ne;
    delete this->nw;
    delete this->se;
    delete this->sw;
}

template<class TObject> 
std::list<TObject> 
QuadTree<TObject>::find_near(TObject item) {
    if ( isleaf )
        return objects;

    if ( item.is_north(x, y) ) {
        if ( item.is_east(x, y) )
            return ne->find_near(item);
        else
            return nw->find_near(item);
    } else {
        if ( item.is_east(x, y) )
            return se->find_near(item);
        else
            return sw->find_near(item);
    }
}
