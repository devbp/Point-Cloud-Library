#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <boost/thread/thread.hpp>
#include <pcl/PolygonMesh.h>
#include <pcl/io/vtk_lib_io.h>
#include <pcl/common/pca.h>

void loadcloud(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud_ptr);
void displaycloud(pcl::PointCloud<pcl::PointXYZ>::Ptr);
void displayNormal(pcl::PointCloud <pcl::PointXYZ>::Ptr cloud_ptr, pcl::PointCloud <pcl::Normal>::Ptr normals);
#endif
