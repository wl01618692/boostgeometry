//
// Created by zhangjiayuan on 23-4-14.
//

#include "boost_geometry.h"
#include <boost/geometry/index/rtree.hpp>
void bg_test() {
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

    //创建R树 linear quadratic rstar三种算法
    bgi::rtree<Value, bgi::quadratic<16>> rtree;//采用quadratic algorithm，节点中元素个数最多16个

    //填充元素
    for (unsigned i = 0; i < 10; ++i)
    {
        DBox b(DPoint(i + 0.0f, i + 0.0f), DPoint(i + 0.5f, i + 0.5f));
        rtree.insert(std::make_pair(b, i));//r树插入外包围矩形 i为索引
    }

    //查询与矩形相交的矩形索引
    DBox query_box(DPoint(0, 0), DPoint(5, 5));
    std::vector<Value> result_s;
    rtree.query(bgi::intersects(query_box), std::back_inserter(result_s));

    //查找5个离点最近的索引
    std::vector<Value> result_n;
    rtree.query(bgi::nearest(DPoint(0, 0), 5), std::back_inserter(result_n));
//    rt.query(index::contains(box), std::back_inserter(result));
//    rt.query(index::covered_by(box), std::back_inserter(result));
//    rt.query(index::covers(box), std::back_inserter(result));
//    rt.query(index::disjont(box), std::back_inserter(result));
//    rt.query(index::intersects(box), std::back_inserter(result));
//    rt.query(index::overlaps(box), std::back_inserter(result));
//    rt.query(index::within(box), std::back_inserter(result));
    int jj =0 ;
}


#include <boost/polygon/polygon.hpp>
#include <cassert>
namespace gtl = boost::polygon;
using namespace boost::polygon::operators;

void gtl_test() {
    typedef gtl::polygon_data<int> Polygon;
    typedef gtl::polygon_traits<Polygon>::point_type Point;
    Point pts[] = {gtl::construct<Point>(0, 0),
                   gtl::construct<Point>(10, 0),
                   gtl::construct<Point>(10, 10),
                   gtl::construct<Point>(0, 10)};
    Polygon poly;
    gtl::set_points(poly, pts, pts+4);

    //now lets see what we can do with this polygon
    assert(gtl::area(poly) == 100.0f);
    assert(gtl::contains(poly, gtl::construct<Point>(5, 5)));
    assert(!gtl::contains(poly, gtl::construct<Point>(15, 5)));
    gtl::rectangle_data<int> rect;
    assert(gtl::extents(rect, poly)); //get bounding box of poly
    assert(gtl::equivalence(rect, poly)); //hey, that's slick
    assert(gtl::winding(poly) == gtl::COUNTERCLOCKWISE);
    assert(gtl::perimeter(poly) == 40.0f);

    //add 5 to all coords of poly
    gtl::convolve(poly, gtl::construct<Point>(5, 5));
    //multiply all coords of poly by 2
    gtl::scale_up(poly, 2);
    gtl::set_points(rect, gtl::point_data<int>(10, 10),
                    gtl::point_data<int>(30, 30));
    assert(gtl::equivalence(poly, rect));
}
