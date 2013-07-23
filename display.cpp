#include"display.h"

void displaycloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr)
{
 //Convert a pcl::PointCloud<T> object to a PointCloud2 binary data blob. 
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new    pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  viewer->addPointCloud<pcl::PointXYZ> (cloud_ptr, "sample cloud"); 
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 0.2, "sample cloud");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();
  //viewer->removeAllPointClouds();
  //viewer->updatePointCloud(cloud_ptr,"cloud");
char ch='c';
   while (!viewer->wasStopped ())
//while(ch!='q')    
{//ch=std::cin.get();
    viewer->spinOnce (100);
   
 
   
}

 
}


void displayNormal(pcl::PointCloud <pcl::PointXYZ>::Ptr cloud_ptr, pcl::PointCloud <pcl::Normal>::Ptr normals)
{
boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new    pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  //viewer->addPointCloud<pcl::PointXYZ> (cloud_ptr, "sample cloud"); 
   viewer->addPointCloudNormals<pcl::PointXYZ ,pcl::Normal> (cloud_ptr, normals, 10, 0.05, "normals");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 0.2, "sample cloud");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();

while (!viewer->wasStopped ())
   {   
 viewer->spinOnce (100);
      
}

}




void loadcloud(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud_ptr)
{ 
    pcl::io::loadPCDFile("milk_cartoon.pcd",*cloud_ptr);
 
}
