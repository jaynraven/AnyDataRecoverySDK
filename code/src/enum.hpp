#ifndef __ENUM_HPP__
#define __ENUM_HPP__

#include <string>

enum BusType {
    BT_USB,
}

// {
//     "bus_type" : 17,
//     "device_id" : "\\\\?\\scsi#disk&ven_nvme&prod_liteon_ca3-8d128#5&204b5025&0&000000#{53f56307-b6bf-11d0-94f2-00a0c91efb8b}",
//     "device_type" : 1,
//     "disk_type" : 1,
//     "dpt_type" : 1,
//     "guid" : "5e5ecb00-693b-43f7-90c6-0fbc1db61010",
//     "index" : 0,
//     "is_dynamic" : false,
//     "is_external" : false,
//     "is_migrate" : true,
//     "is_support_trim" : true,
//     "is_system_disk" : true,
//     "media_attr" : 1,
//     "name" : "LITEON CA3-8D128-HP",
//     "partition_count" : 4,
//     "product_name" : "LITEON CA3-8D128-HP",
//     "serial_number" : "0023_0356_3009_C796.",
//     "signature" : 0,
//     "total_size" : 128035676160,
//     "usable_end_offset" : 128035659264,
//     "usable_start_offset" : 1048576,
//     "uuid" : "\\\\?\\scsi#disk&ven_nvme&prod_liteon_ca3-8d128#5&204b5025&0&000000#{53f56307-b6bf-11d0-94f2-00a0c91efb8b}",
//     "vendor_name" : ""
// }

struct DiskInfo {
    int bus_type,
    std::string device_id,
    int device_type,
    int disk_type,
    int dpt_type,
    std::string guid,
    int index,
    bool is_dynamic,
    bool is_external,
    bool is_migrate,
    bool is_support_trim,
    bool is_system_disk,
    int media_attr,
    std::string name,
    int partition_count,
    std::string product_name,
    std::string serial_number,
    int signature,
    unsigned long long total_size,
    unsigned long long usable_end_offset,
    unsigned long long usable_start_offset,
    std::string uuid,
    std::string vendor_name
}

// {
//     "bitlocker_status" : 0,
//     "block_size" : 4096,
//     "can_read" : true,
//     "device_id" : "\\\\?\\Volume{3f8f835c-8d22-4b97-b324-af54808bc86f}",
//     "device_type" : 1,
//     "disk_index" : 0,
//     "disk_offset" : 316669952,
//     "disk_type" : 1,
//     "filesystem_type" : 3,
//     "free_size" : 69381144576,
//     "index" : 0,
//     "is_external" : false,
//     "is_lost_partition" : false,
//     "is_set_vmemory" : true,
//     "is_system_partition" : true,
//     "is_used_disk_id" : false,
//     "media_attr" : 1,
//     "mount_point" : "C:",
//     "name" : "\u65b0\u52a0\u5377",
//     "partition_type" : 1,
//     "total_size" : 127717601280,
//     "uuid" : "3f8f835c-8d22-4b97-b324-af54808bc86f"
// }

struct VolumeInfo {
    int bitlocker_status,
    unsigned int block_size,
    bool can_read,
    std::string device_id,
    int device_type,
    int filesystem_type,
    unsigned long long free_size,
    int index,
    bool is_external,
    bool is_lost_partition,
    bool is_set_vmemory,
    bool is_system_partition,
    bool is_used_disk_id,
    int media_attr,
    std::string mount_point,
    std::string name,
    int partition_type,
    unsigned long long total_size,
    std::string uuid
}


std::vector<DiskInfo> EnumDisks() {
    std::vector<DiskInfo> disks;

    

    retirm disks;
}

#endif 