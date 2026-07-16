#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hittable.h"
#include "material.h"

class triangle : public hittable
{
public:
    triangle(
        const point3 &v0,
        const point3 &v1,
        const point3 &v2,
        shared_ptr<material> mat)
        : v0(v0), v1(v1), v2(v2), mat(mat)
    {
        bbox = aabb(v0, v1);
        bbox = aabb(bbox, aabb(v0, v2));
    }

    bool hit(const ray &r, interval ray_t, hit_record &rec) const override
    {
        const double epsilon = 1e-8;

        vec3 edge1 = v1 - v0;
        vec3 edge2 = v2 - v0;

        vec3 h = cross(r.direction(), edge2);
        double a = dot(edge1, h);

        if (std::fabs(a) < epsilon)
            return false;

        double f = 1.0 / a;

        vec3 s = r.origin() - v0;
        double u = f * dot(s, h);

        if (u < 0.0 || u > 1.0)
            return false;

        vec3 q = cross(s, edge1);
        double v = f * dot(r.direction(), q);

        if (v < 0.0 || (u + v) > 1.0)
            return false;

        double t = f * dot(edge2, q);

        if (!ray_t.contains(t))
            return false;

        rec.t = t;
        rec.p = r.at(t);

        vec3 outward_normal = unit_vector(cross(edge1, edge2));
        rec.set_face_normal(r, outward_normal);

        rec.mat = mat;
        rec.u = u;
        rec.v = v;

        return true;
    }

    aabb bounding_box() const override
    {
        return bbox;
    }

private:
    point3 v0;
    point3 v1;
    point3 v2;

    shared_ptr<material> mat;
    aabb bbox;
};

#endif