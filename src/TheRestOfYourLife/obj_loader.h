#ifndef OBJ_LOADER_H
#define OBJ_LOADER_H

#include "hittable_list.h"
#include "triangle.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class obj_loader : public hittable
{
public:
    obj_loader(
        const std::string &filename,
        const point3 &position,
        double scale,
        shared_ptr<material> mat)
    {
        load(filename, position, scale, mat);
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

    void load(
        const std::string &filename,
        const point3 &position,
        double scale,
        shared_ptr<material> mat)
    {
        std::ifstream file(filename);

        if (!file.is_open())
        {
            std::cerr << "Failed to open OBJ file: "
                      << filename << std::endl;
            return;
        }

        std::vector<point3> vertices;
        std::string line;

        while (std::getline(file, line))
        {

            if (line.empty())
                continue;

            std::stringstream ss(line);
            std::string prefix;
            ss >> prefix;

            // Vertex
            if (prefix == "v")
            {

                double x, y, z;
                ss >> x >> y >> z;

                vertices.emplace_back(
                    position.x() + x * scale,
                    position.y() + y * scale,
                    position.z() + z * scale);
            }

            // Face
            else if (prefix == "f")
            {

                std::string s1, s2, s3;
                ss >> s1 >> s2 >> s3;

                auto parse_index = [](const std::string &token)
                {
                    std::stringstream ts(token);
                    std::string index;
                    std::getline(ts, index, '/');
                    return std::stoi(index) - 1;
                };

                int i0 = parse_index(s1);
                int i1 = parse_index(s2);
                int i2 = parse_index(s3);

                if (i0 >= 0 && i1 >= 0 && i2 >= 0 &&
                    i0 < static_cast<int>(vertices.size()) &&
                    i1 < static_cast<int>(vertices.size()) &&
                    i2 < static_cast<int>(vertices.size()))
                {
                    mesh.add(make_shared<triangle>(
                        vertices[i0],
                        vertices[i1],
                        vertices[i2],
                        mat));
                }
            }
        }

        file.close();
    }
};

#endif