//
// Created by zhangjiayuan on 23-4-14.
//

#ifndef BOOSTGEOMETRY_BOOST_GEOMETRY_H
#define BOOSTGEOMETRY_BOOST_GEOMETRY_H
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/polygon/polygon.hpp>
#include <boost/geometry/index/rtree.hpp>
void bg_test();
void gtl_test();
namespace BP = boost::polygon;
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
typedef BP::polygon_45_with_holes_data<int32_t> B45PolygonWHoles;

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;
typedef bg::model::d2::point_xy<double, boost::geometry::cs::cartesian> DPoint;
typedef bg::model::box<DPoint> DBox; //矩形
typedef std::pair<DBox, unsigned> Value;

#endif //BOOSTGEOMETRY_BOOST_GEOMETRY_H
