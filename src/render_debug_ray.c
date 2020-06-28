#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"

void print_ray(t_ray ray)
{
	printf("dist = %f, scale = %f, mod_scale = %f, inter = %f,%f z_height : %f,%f\n", ray.dist, ray.scale, ray.mod_scale, ray.inter.x, ray.inter.y, ray.z_height.pos, ray.z_height.size);
}

void print_obj_list(t_obj *obj)
{
	
}