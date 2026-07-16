#include "rtweekend.h"

#include "camera.h"
#include "hittable_list.h"
#include "material.h"
#include "quad.h"
#include "sphere.h"
#include "triangle.h"

int main()
{
    hittable_list world;

    // Materials
    auto ground = make_shared<lambertian>(color(0.80, 0.80, 0.75));
    auto blue = make_shared<lambertian>(color(0.20, 0.45, 0.90));
    auto orange = make_shared<lambertian>(color(0.95, 0.55, 0.15));
    auto metal1 = make_shared<metal>(color(0.90, 0.90, 0.90), 0.05);
    auto glass = make_shared<dielectric>(1.5);

    auto red = make_shared<lambertian>(color(0.90, 0.20, 0.20));

    auto light = make_shared<diffuse_light>(color(12, 12, 12));

    // Ground
    world.add(make_shared<quad>(
        point3(-8, -1, -8),
        vec3(16, 0, 0),
        vec3(0, 0, 16),
        ground));

    // Spheres
    world.add(make_shared<sphere>(point3(-2, 0, -1), 1.0, blue));
    world.add(make_shared<sphere>(point3(0, 0.2, 1.5), 1.2, glass));
    world.add(make_shared<sphere>(point3(2, 0, -0.5), 1.0, metal1));
    world.add(make_shared<sphere>(point3(0, -0.3, -3), 0.7, orange));

    // Triangle
    world.add(make_shared<triangle>(
        point3(-1.5, -1.0, 2.0),
        point3(0.0, 1.2, 2.0),
        point3(1.5, -1.0, 2.0),
        red));

    // Ceiling Light
    world.add(make_shared<quad>(
        point3(-2, 5, -2),
        vec3(4, 0, 0),
        vec3(0, 0, 4),
        light));

    // Lights list
    auto empty = shared_ptr<material>();

    hittable_list lights;
    lights.add(make_shared<quad>(
        point3(-2, 5, -2),
        vec3(4, 0, 0),
        vec3(0, 0, 4),
        empty));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 800;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    cam.background = color(0.65, 0.82, 1.00);

    cam.vfov = 35;
    cam.lookfrom = point3(0, 2, 8);
    cam.lookat = point3(0, 0, 0);
    cam.vup = vec3(0, 1, 0);

    cam.defocus_angle = 0;
    cam.focus_dist = 8.0;

    cam.render(world, lights);
}