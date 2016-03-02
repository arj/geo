#ifndef ENTITY_H
#define ENTITY_H

namespace geo {
namespace geometry {

//! The Entity class is the base class of all geometrical and topological
//! classes and enriches them with a unique id and attributes.
//! Furthermore, the entity keeps the connection to the World.
class Entity {
  
public:
    //! Creates a new entity with an id.
    Entity(int id);

public:
    setId();
};

}
};

#endif