#pragma once

#include "Mountable.h"
#include "..\..\..\Object Types\PositionObject.h"
#include <unordered_map>

namespace Space_Fighter {

	namespace Ships {

		namespace SubComponents {

			/*
			A MountObject is able to mount and manage Mountables.*/
			class MountObject {
			public:
				/*
				The information about a mounting point for a Mountable.*/
				typedef ObjectTypes::PositionObject mount_point;
				/*
				The type used to identify a particular mounting point.*/
				typedef unsigned __int8 mount_id;
				/*
				The map type used to store the mounted Mountables.*/
				typedef std::unordered_map<mount_id, Mountable> mount_map;

				MountObject(const mount_id mount_max, mount_point * const points, Mountable * const mounts = nullptr);
				MountObject(const MountObject & orig);
				/*
				Attempts to mount the passed mountable onto the selected mount.
				Returns true if the attempt succeeds. Attempts fail if the
				mount is already filled or if the specified mount is greater
				than mount_max.*/
				bool mount(const Mountable & mountable, const mount_id point);
				/*
				Attempts to unmount the specified mountable. Returns true if a
				Mountable is unmounted. "value" can be given if the mountable
				which was just removed is to be retrieved.*/
				bool unmount(const mount_id point, Mountable * value = nullptr);

			private:

				/*
				The maximum mount identifier allowed on this MountObject.*/
				const mount_id mount_max;
				/*
				The map of Mountables mounted on this mount object.*/
				mount_map mounts;
				/*
				The array of information for each mount_point.*/
				mount_point * const points;

			};

		}

	}

}
