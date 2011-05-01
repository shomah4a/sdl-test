#include <GL/gl.h>
#include <SDL/SDL.h>
#include <SDL/SDL_main.h>
#include <boost/foreach.hpp>
#include <boost/fusion/include/at_c.hpp>
#include <glsupport.hpp>


void GLDraw::put_drawable(const GLDrawable& drawable)
{
    this->drawables.push_back(&drawable);
}


void GLDraw::draw(void)
{
    using boost::fusion::at_c;
    
    ::glClearColor(at_c<0>(this->color),
                   at_c<1>(this->color),
                   at_c<2>(this->color),
                   at_c<3>(this->color));

    BOOST_FOREACH(auto it, this->drawables)
    {
        const auto& obj = (*it);
        obj.set_render_state();
        obj.draw();
        obj.reset_render_state();
    }

    ::SDL_GL_SwapBuffers();
}


void GLDraw::clear_drawables()
{
    this->drawables.clear();
}

