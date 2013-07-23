
#ifndef _SEGMENTATION_H
#define _SEGMENTATION_H

#include <pcl/io/pcd_io.h>
#include <pcl/search/search.h>
#include <pcl/search/kdtree.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/passthrough.h>
#include <pcl/segmentation/region_growing.h>
#include <pcl/filters/extract_indices.h>

 pcl::PointCloud <pcl::PointXYZ>::Ptr RegionGrowingSegmentation(pcl::PointCloud <pcl::PointXYZ>::Ptr cloud_ptr,pcl::PointCloud <pcl::Normal>::Ptr normals);
 void NormalCalculation(pcl::PointCloud <pcl::PointXYZ>::Ptr cloud_ptr, pcl::PointCloud <pcl::Normal>::Ptr &normals);

#endif
