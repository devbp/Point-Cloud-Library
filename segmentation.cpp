#include"segmentation.h"

void NormalCalculation(pcl::PointCloud <pcl::PointXYZ>::Ptr cloud_ptr, pcl::PointCloud <pcl::Normal>::Ptr &normals)
{
  pcl::search::Search<pcl::PointXYZ>::Ptr tree = boost::shared_ptr<pcl::search::Search<pcl::PointXYZ> > (new pcl::search::KdTree<pcl::PointXYZ>);
  pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimator;
  normal_estimator.setSearchMethod (tree);
  normal_estimator.setInputCloud (cloud_ptr);
  normal_estimator.setKSearch (50);
  normal_estimator.compute (*normals);

}


 pcl::PointCloud<pcl::PointXYZ>::Ptr RegionGrowingSegmentation(pcl::PointCloud <pcl::PointXYZ>::Ptr cloud_ptr, pcl::PointCloud <pcl::Normal>::Ptr normals)
  {
  pcl::PointCloud<pcl::PointXYZ>::Ptr segment_cloud(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_segment1(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::search::Search<pcl::PointXYZ>::Ptr tree = boost::shared_ptr<pcl::search::Search<pcl::PointXYZ> > (new pcl::search::KdTree<pcl::PointXYZ>);
  pcl::ExtractIndices<pcl::PointXYZ> extract;
  pcl::IndicesPtr indices (new std::vector <int>);
  pcl::PassThrough<pcl::PointXYZ> pass;
  //pass.setInputCloud (cloud);
  //pass.setFilterFieldName ("z");
  //pass.setFilterLimits (0.0, 1.0);
  //pass.filter (*indices);
  pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
  pcl::RegionGrowing<pcl::PointXYZ, pcl::Normal> reg;
  reg.setMinClusterSize (10000);
  reg.setMaxClusterSize (1000000);
  reg.setSearchMethod (tree);
  reg.setNumberOfNeighbours (10);
  reg.setInputCloud (cloud_ptr);
  //reg.setIndices (indices);
  reg.setInputNormals (normals);
  reg.setSmoothnessThreshold (7.0 / 180.0 * M_PI);
  reg.setCurvatureThreshold (1.0);
  std::vector <pcl::PointIndices> clusters;

  reg.extract (clusters);


  std::cout << "Number of clusters is equal to " << clusters.size () << std::endl;
  std::cout << "First cluster has " << clusters[0].indices.size () << " points." << std::endl;
  std::cout << "These are the indices of the points of the initial" <<
  std::endl << "cloud that belong to the first cluster:" << std::endl;
  int counter = 0;
 
  std::vector<int> pointindices;
  int i=0;

while( i<clusters[1].indices.size())
{
pointindices.push_back(clusters[1].indices[i]);
i++;
}
 pcl::copyPointCloud<pcl::PointXYZ>(*cloud_ptr, pointindices, *cloud_segment1);

  while ( counter <clusters[0].indices.size ())
  {
//inliers->indices.push_back()
 indices->push_back(clusters[0].indices[counter]);
    //std::cout << clusters[1].indices[counter] << std::endl;
  
 counter++;
  }
  extract.setInputCloud(cloud_ptr);
  extract.setNegative(false);
  extract.setIndices(indices);
  extract.filter(*segment_cloud);
  pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud = reg.getColoredCloud ();
 
return cloud_segment1;
}
