//http://www.sfml-dev.org/forum/viewtopic.php?p=31068&sid=f909e9ba50a9a58f126febb2a56557a8

#include "Constants.h"
#include <Box2D.h>
#include <SFML/Graphics.hpp>

struct b2AABB;

class DebugDraw : public b2Draw {
private:
    sf::RenderTarget &target;
    
public: 
    DebugDraw(sf::RenderTarget &target);
    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
    void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
    void DrawTransform(const b2Transform& xf);
    void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);
    void DrawAABB(b2AABB* aabb, const b2Color& color);
};
