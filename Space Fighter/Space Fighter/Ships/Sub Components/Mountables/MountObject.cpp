#include "MountObject.h"

Space_Fighter::Ships::SubComponents::MountObject::MountObject(const mount_id mount_max, mount_point * const points, Mountable * const mounts)
	: mount_max(mount_max), points(new mount_point[mount_max]), mounts(mount_max) {
	mount_id i;
	for (i = 0; i < mount_max; i++)
		this->points[i] = points[i];

	if (mounts)
		for (i = 0; i < mount_max; i++)
			this->mounts[i] = mounts[i];
}

Space_Fighter::Ships::SubComponents::MountObject::MountObject(const MountObject & orig)
	: mount_max(orig.mount_max), points(new mount_point[mount_max]), mounts(orig.mounts) {
	for (mount_id i = 0; i < mount_max; i++) {
		points[i] = orig.points[i];
	}
}

bool Space_Fighter::Ships::SubComponents::MountObject::mount(const SubComponents::Mountable & mountable, const mount_id point) {
	if (point >= mount_max || mounts.count(point))
		return false;
	mounts[point] = mountable;
	return true;
}

bool Space_Fighter::Ships::SubComponents::MountObject::unmount(const mount_id point, Mountable * value) {
	if (point >= mount_max || !mounts.count(point))
		return false;
	if (value)
		*value = mounts[point];
	mounts.erase(point);
	return true;
}
