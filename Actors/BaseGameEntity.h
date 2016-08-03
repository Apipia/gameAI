//
// Created by anthony on 8/2/16.
//

#ifndef GAMEAI_BASEGAMEENTITY_H
#define GAMEAI_BASEGAMEENTITY_H


class BaseGameEntity
{
private:

    //Every Entity has a unique ID associated with it
    int m_ID;

    //Every time a entity is made, this number is updated. (increased)
    //It's the next valid ID
    static int m_iNextValidID;

    //Set's the ID
    //Verifies that val is >= m_iNextValidID. Then sets the ID to that value and incrementing the valid ID
    void setID(int val);

public:

    BaseGameEntity(int val)
    {
        setID(val);
    }

    virtual ~BaseGameEntity(){}

    virtual void Update()=0; //Every Actor must have an update member function

    int ID()const {return m_ID;}

};


#endif //GAMEAI_BASEGAMEENTITY_H
