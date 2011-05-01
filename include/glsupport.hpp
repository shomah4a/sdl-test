#ifndef GLSUPPORT_HPP
#define GLSUPPORT_HPP

#include <boost/fusion/include/vector.hpp>
#include <vector>

namespace fusion = boost::fusion;


typedef fusion::vector<unsigned char,
                       unsigned char,
                       unsigned char,
                       unsigned char> Color;


/// 描画するもの
class GLDrawable
{
public:
    virtual void set_render_state(void) const {}
    virtual void draw(void) const = 0;
    virtual void reset_render_state(void) const {}

protected:
private:
};



/// 描画用クラス
class GLDraw
{
public:
    GLDraw(unsigned char r=0,
           unsigned char g=0,
           unsigned char b=0,
           unsigned char a=0): color(r, g, b, a){}

    // 描画要素追加
    void put_drawable(const GLDrawable& drawable);

    // 描画
    void draw(void);

    // 描画要素全排除
    void clear_drawables();

private:

    // 色とか
    const Color color;

    // 描画するものたち
    std::vector<const GLDrawable*> drawables;
};


#endif
