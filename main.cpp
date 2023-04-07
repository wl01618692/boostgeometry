#pragma once
#include <iostream>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <vector>
#include <boost/geometry/index/rtree.hpp>

namespace BG = boost::geometry;
namespace BGM = boost::geometry::model;
typedef BG::model::point<double, 2, BG::cs::cartesian> point_t; // 2D point, double
typedef BG::model::polygon<point_t> polygon_t; // polygon, 1 outer, 0 or more inner
typedef BG::model::multi_point<point_t> mpoint_t; // collection of point
typedef BG::model::linestring<point_t> linestring_t; // vector of points
typedef BG::model::multi_linestring<linestring_t> mlinestring_t; // vectors of lineString
typedef BG::model::box<point_t> box_t; // box, consist of 2 points
typedef BG::model::multi_polygon<polygon_t> mpolygon_t; // multigon, collection of polygon_t
typedef BG::model::ring<point_t> ring_t; // a closed line which should not be self-intersecting, clockwise closed
typedef BG::model::segment<point_t> segment_t; // segment consist of 2 points

class A {
public:
    A() {
        std::cout << "create" << std::endl;
    }

   ~A() {
     std::cout << "destroy" << std::endl;
   }
};

int main() {
    A a;
    {
        std::vector<A> vec;
        vec.push_back(a);
    }
    int t = 9;

    struct student {
        char mark;
        long num;
        float score;
    };

    union test {
        char mark;
        int num;
        int score;
    };

    std::cout << sizeof(union test) << std::endl;
    int* p;
    double* k;
    std::cout << sizeof(p) << " " << sizeof(k) << std::endl;
    std::vector<double> w;
    w.push_back(2);
    w.push_back(3);
    std::cout << *w.begin().base();
}

int main3() {

//    int x = 0;
//    decltype(x) y = 1;           // y -> int
//    decltype(x + y) z = 0;       // z -> int
//    const int &i = x;
//    decltype(i) j = y;           // j -> const int &
//    const decltype(z) *p = &z;  // *p  -> const int, p  -> const int *
//    decltype(z) *pi = &z;       // *pi -> int      , pi -> int *
//    decltype(pi) *pp = &pi;      // *pp -> int *    , pp -> int * *


    // 如果exp是一个不被括号()包围的表达式，或者是一个类成员访问表达式，或者是一个单独的变量，decltype(exp)的类型和exp一致
    //    如果exp是函数调用，则decltype(exp)的类型就和函数返回值的类型一致
    //    如果exp是一个左值，或被括号()包围，decltype(exp)的类型就是exp的引用，假设exp的类型为T，则decltype(exp)的类型为T&

}

int main2() {

    // clockwise
    polygon_t poly1;
    BG::append(poly1.outer(), point_t(0.0, 0.0));
    BG::append(poly1.outer(), point_t(0.0, 3.0));
    BG::append(poly1.outer(), point_t(3.0, 3.0));

    poly1.inners().resize(1);
    BG::append(poly1.inners()[0], point_t(1.0, 1.0));
    BG::append(poly1.inners()[0], point_t(4.0, 1.0));
    BG::append(poly1.inners()[0], point_t(4.0, 4.0));
    BG::append(poly1.inners()[0], point_t(1.0, 4.0));
    BG::append(poly1.inners()[0], point_t(1.0, 1.0));

    mpoint_t mpt1;
    BG::append(mpt1, point_t(1.0, 4.0));
    BG::append(mpt1, point_t(1.0, 4.0));
    std::size_t count = BG::num_points(mpt1);
    std::cout << count << std::endl;



    box_t box1;
    box_t box2(point_t(0.0, 0.0), point_t(5.0, 5.0));

    BG::set<BG::min_corner, 0>(box1, 1.0);
    BG::set<BG::min_corner, 1>(box1, 2.0);
    box1.max_corner().set<0>(3.0);
    box1.max_corner().set<1>(4.0);

    double min_x = BG::get<BG::min_corner, 0>(box1);
    double min_y = BG::get<BG::min_corner, 1>(box1);
    double max_x = box1.max_corner().get<0>();
    double max_y = box1.max_corner().get<1>();
    std::cout << min_x << min_y << max_x << max_y << std::endl;

    mpolygon_t mpoly1;
    mpoly1.resize(2);

    BG::append(mpoly1[0].outer(), point_t(0.0, 0.0));
    BG::append(mpoly1[0].outer(), point_t(0.0, 5.0));
    BG::append(mpoly1[0].outer(), point_t(5.0, 5.0));
    BG::append(mpoly1[0].outer(), point_t(5.0, 0.0));
    BG::append(mpoly1[0].outer(), point_t(0.0, 0.0));

    mpoly1[0].inners().resize(1);
    BG::append(mpoly1[0].inners()[0], point_t(1.0, 1.0));
    BG::append(mpoly1[0].inners()[0], point_t(4.0, 1.0));
    BG::append(mpoly1[0].inners()[0], point_t(4.0, 4.0));
    BG::append(mpoly1[0].inners()[0], point_t(1.0, 4.0));
    BG::append(mpoly1[0].inners()[0], point_t(1.0, 1.0));

    BG::append(mpoly1[1].outer(), point_t(5.0, 5.0));
    BG::append(mpoly1[1].outer(), point_t(5.0, 6.0));
    BG::append(mpoly1[1].outer(), point_t(6.0, 6.0));
    BG::append(mpoly1[1].outer(), point_t(6.0, 5.0));
    BG::append(mpoly1[1].outer(), point_t(5.0, 5.0));

    segment_t seg1;
    segment_t seg2(point_t(0.0, 0.0), point_t(5.0, 5.0));
    BG::set<0, 0>(seg1, 1.0);
    BG::set<0, 1>(seg1, 2.0);
    BG::set<1, 0>(seg1, 3.0);
    BG::set<1, 1>(seg1, 4.0);

    double x0 = BG::get<0, 0>(seg1);
    double y0 = BG::get<0, 1>(seg1);
    double x1 = BG::get<1, 0>(seg1);
    double y1 = BG::get<1, 1>(seg1);

    /// test wkt
    point_t point = BG::make<point_t>(3, 6);
    BG::model::polygon<point_t> polygon;
    BG::append(BG::exterior_ring(polygon), BG::make<point_t>(0, 0));
    BG::append(BG::exterior_ring(polygon), BG::make<point_t>(0, 4));
    BG::append(BG::exterior_ring(polygon), BG::make<point_t>(4, 4));
    BG::append(BG::exterior_ring(polygon), BG::make<point_t>(4, 0));
    BG::append(BG::exterior_ring(polygon), BG::make<point_t>(0, 0));

    std::cout << boost::geometry::wkt(point) << std::endl;
    std::cout << boost::geometry::wkt(polygon) << std::endl;

    /// test read_wkt
    point_t a;
    boost::geometry::model::linestring<point_t> b;
    boost::geometry::model::polygon<point_t> c;
    boost::geometry::model::box<point_t> d;
    boost::geometry::model::segment<point_t> e;

    boost::geometry::read_wkt("POINT(1 2)", a);
    boost::geometry::read_wkt("LINESTRING(0 0,2 2,3 1)", b);
    boost::geometry::read_wkt("POLYGON((0 0,0 7,4 2,2 0,0 0))", c);
    boost::geometry::read_wkt("BOX(0 0,3 3)", d);
    boost::geometry::read_wkt("SEGMENT(1 0,3 4)", e);

    // clockwise
    polygon_t poly2;
    BG::append(poly2.outer(), point_t(0.0, 0.0));
    BG::append(poly2.outer(), point_t(0.0, 4.0));
    BG::append(poly2.outer(), point_t(4.0, 4.0));
    BG::append(poly2.outer(), point_t(4.0, 0.0));

    // clockwise
    polygon_t poly3;
    BG::append(poly3.outer(), point_t(0.0, 0.0));
    BG::append(poly3.outer(), point_t(0.0, 2.0));
    BG::append(poly3.outer(), point_t(2.0, 2.0));
    BG::append(poly3.outer(), point_t(2.0, 0.0));

    std::cout << BG::intersects(poly2, poly3) << std::endl;
    std::cout << BG::within(poly2, poly3) << std::endl;

    std::cout << 123321 << std::endl;

    return 0;
}
