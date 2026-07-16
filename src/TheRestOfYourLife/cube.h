#ifndef CUBE_H
#define CUBE_H

#include "hittable_list.h"
#include "triangle.h"

class cube : public hittable
{
public:
    cube(
        const point3 &center,
        double size,
        shared_ptr<material> mat)
    {
        double h = size * 0.5;

        // Vertices
        point3 v0(center.x() - h, center.y() - h, center.z() - h);
        point3 v1(center.x() + h, center.y() - h, center.z() - h);
        point3 v2(center.x() + h, center.y() + h, center.z() - h);
        point3 v3(center.x() - h, center.y() + h, center.z() - h);

        point3 v4(center.x() - h, center.y() - h, center.z() + h);
        point3 v5(center.x() + h, center.y() - h, center.z() + h);
        point3 v6(center.x() + h, center.y() + h, center.z() + h);
        point3 v7(center.x() - h, center.y() + h, center.z() + h);

        // Front
        mesh.add(make_shared<triangle>(v4, v5, v6, mat));
        mesh.add(make_shared<triangle>(v4, v6, v7, mat));

        // Back
        mesh.add(make_shared<triangle>(v1, v0, v3, mat));
        mesh.add(make_shared<triangle>(v1, v3, v2, mat));

        // Left
        mesh.add(make_shared<triangle>(v0, v4, v7, mat));
        mesh.add(make_shared<triangle>(v0, v7, v3, mat));

        // Right
        mesh.add(make_shared<triangle>(v5, v1, v2, mat));
        mesh.add(make_shared<triangle>(v5, v2, v6, mat));

        // Top
        mesh.add(make_shared<triangle>(v3, v7, v6, mat));
        mesh.add(make_shared<triangle>(v3, v6, v2, mat));

        // Bottom
        mesh.add(make_shared<triangle>(v0, v1, v5, mat));
        mesh.add(make_shared<triangle>(v0, v5, v4, mat));
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