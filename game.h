//
//  game.h
//  nation_war
//
//  Created by Saturneric on 17/1/17.
//  Copyright © 2017年 Bakantu Eric. All rights reserved.
//

#ifndef game_h
#define game_h

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <GLUT/glut.h>

#include "nation.h"
#include "factory.h"
#include "army.h"
#include "land.h"
#include "event.h"


using namespace std;

extern list<class factory *> ftc_vec;
extern list<class nation *> ntn_vec;
extern list<class land *> land_vec;
extern list<class army *> amy_vec;
extern list<class event *> event_vec;
extern list<class route *> route_vec;

class route {
    
public:
    class land *f_lnd;
    class land *t_lnd;
    int distance;
    route(class land *f_lnd, class land *t_lnd, int distance);
};

class armymove {
    class land *templnd;
    class land *tolnd;
    int lastdistance;
    class army *parmy;
    list<class route *>::iterator proute;
    list<class route *> way;
    
public:
    int golnd(void);
    armymove(class land *templand, class land *toland, list<class route *>way, class army *parmy);
};

int getway(class land *f_lnd, class land *t_lnd, int tdistance, list<class route *>tway);
list<class route *> findway(class land *f_lnd, class land *t_lnd);
int addarmymove(class land *templand, class land *toland, class army *parmy);
#endif /* game_h */

int engine(void);
