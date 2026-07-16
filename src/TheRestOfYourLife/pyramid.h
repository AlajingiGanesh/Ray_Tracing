#ifndef PYRAMID_H
#define PYRAMID_H

#include "hittable_list.h"
#include "triangle.h"

class pyramid : public hittable
{
public:
    pyramid(
        const point3 &center,
        double size,
        double height,
        shared_ptr<material> mat)
    {
        double h = size / 2.0;

        point3 b0(center.x() - h, center.y(), center.z() - h);
        point3 b1(center.x() + h, center.y(), center.z() - h);
        point3 b2(center.x() + h, center.y(), center.z() + h);
        point3 b3(center.x() - h, center.y(), center.z() + h);

        point3 top(center.x(), center.y() + height, center.z());

        // Base
        mesh.add(make_shared<triangle>(b0, b1, b2, mat));
        mesh.add(make_shared<triangle>(b0, b2, b3, mat));

        // Sides
        mesh.add(make_shared<triangle>(b0, b1, top, mat));
        mesh.add(make_shared<triangle>(b1, b2, top, mat));
        mesh.add(make_shared<triangle>(b2, b3, top, mat));
        mesh.add(make_shared<triangle>(b3, b0, top, mat));
    }

    bool hit(const ray &r, interval ray_t, hit_record &rec) const override
    {
        return mesh.hit(r, ray_t, rec);
    }

    aabb bounding_box() const override
    {
        return mesh.bounding_box();
    }

private:
    hittable_list mesh;
};

#endif