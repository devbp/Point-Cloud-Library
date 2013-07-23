#include"display.h"
#include"segmentation.h"

int  main()
{
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZ>);
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr1(new pcl::PointCloud<pcl::PointXYZ>);
pcl::PointCloud<pcl::PointXYZ>::Ptr segmented_cloud(new pcl::PointCloud<pcl::PointXYZ>);
//load point cloud
loadcloud(cloud_ptr);

pcl::PointCloud <pcl::Normal>::Ptr normals(new pcl::PointCloud <pcl::Normal>);

//calculate the normal of the point cloud.
NormalCalculation(cloud_ptr,normals);
//display point cloud.
displaycloud(cloud_ptr);
//display the normal of the point cloud.
displayNormal(cloud_ptr, normals);
//segmentation by region growing method.
segmented_cloud=RegionGrowingSegmentation(cloud_ptr,normals);
//display the segmented the cloud.
displaycloud(segmented_cloud);
return 0;

}
