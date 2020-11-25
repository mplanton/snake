// Border.h
#ifndef BORDER_H
#define BORDER_H
#include "Thing.h"

class Border : public Thing
{
public:
    enum Type
    {
        HORIZONTAL,
        VERTICAL,
        CORNER
    };

    Border(Type type) : Thing(BORDER)
    {
        // These could be separate subclasses...
        switch(type)
        {
            case HORIZONTAL:
               _c = '-'; 
               break;
            case VERTICAL:
               _c = '|'; 
               break;
            case CORNER:
               _c = '+'; 
               break;
        }
    }
};

#endif // BORDER_H
