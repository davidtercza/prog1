#include "Simple_window.h"
#include "Graph.h"


double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{

	using namespace Graph_lib;

    int xmax = 600;
    int ymax = 400;
    Simple_window win {Point{100,100}, xmax, ymax, "My Window"};
    
    int x_orig = xmax/2;
    int y_orig = ymax/2;
    Point origo = {x_orig,y_orig};
    
    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;
    Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};
	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
    y.set_color(Color::red);
    x.set_color(Color::red);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function sin_func ( [] (double x) { return sin(x); },
						rmin, rmax, origo, n_points, xscale, yscale);

	Rectangle r {Point{100,50}, 150, 60};
	r.set_fill_color(Color::cyan);

	Polygon poly;
	poly.add(Point(200,150));
	poly.add(Point(250,200));
	poly.add(Point(100,200));
	poly.set_fill_color(Color::yellow);


	Text t {Point{100,200}, "Hello graphics!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii {Point{200,200}, "brendon.jpg"};

	win.attach(ii);
    win.attach(x);
    win.attach(y);
    win.attach(s);
    win.attach(sq);
	win.attach(sin_func);
	win.attach(r);
	win.attach(poly);
	win.attach(t);
	
    win.wait_for_button();


}