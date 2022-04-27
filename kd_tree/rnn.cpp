/*
* 寻找R近邻
*/

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree_flann.h>

using namespace std;

pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_kdtree_radius(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud, int pointindice, float radius)
{

    pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;
    kdtree.setInputCloud(cloud);

    std::vector<int> pointIdxRadiusSearch;
    std::vector<float> pointRadiusSquaredDistance;

    kdtree.radiusSearch(cloud->points[pointindice], radius, pointIdxRadiusSearch, pointRadiusSquaredDistance);
    //近邻搜索
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::copyPointCloud(*cloud, pointIdxRadiusSearch, *cloud_out);

    return cloud_out;
}

int main(int argc,char**argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile(argv[1],*cloud);

    auto cloud_knn = pcl_kdtree_radius(cloud,0,2);

    system("pause");
    return 0;
}
