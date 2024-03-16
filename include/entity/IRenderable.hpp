#if !defined(IRENDARABLE_COMPONENT_HPP)
#define IRENDARABLE_COMPONENT_HPP

template <class T>
class IRenderable
{

public:
    virtual ~IRenderable(){};
    void draw(){};
    void render(){};
    void update(){};
    void clean(){};
};

#endif // IRENDARABLE_COMPONENT_HPP
