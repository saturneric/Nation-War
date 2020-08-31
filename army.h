//
//  army.h
//  nation_war
//
//  Created by Saturneric on 17/1/16.
//  Copyright © 2017年 Bakantu Eric. All rights reserved.
//

#ifndef army_h
#define army_h

class army {
public:
    int sldmun;
    int amyofe;
    int sldeqp;
    int amycst;
    int armyv;
    class land *pm_lnd;
    class nation *pm_ntn;
    
    int upgrade(void);
    int move(class land *toland);
    int amy_cost(void);
    int fight(void);
    int kill(int num);
    int add(int num);
    int del(void);
    army(class nation *p_ntn, class land *p_lnd, int t_amyofe, int num);
    ~army(void);
};


#endif /* army_h */
