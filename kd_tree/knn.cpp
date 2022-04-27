/*
* 寻找k近邻
*/

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree_flann.h>

using namespace std;

pcl::PointCloud<pcl::PointXYZ>::Ptr  pcl_kdtree_k(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud, int pointindice, int K)
{
    pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;
    kdtree.setInputCloud(cloud);

    std::vector<int> pointIdxNKNSearch(K);
    std::vector<float> pointNKNSquaredDistance(K);

    //近邻搜索
    kdtree.nearestKSearch(cloud->points[pointindice], K, pointIdxNKNSearch, pointNKNSquaredDistance);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::copyPointCloud(*cloud, pointIdxNKNSearch, *cloud_out);

    return cloud_out;
}


int main(int argc,char**argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile(argv[1],*cloud);

    auto cloud_knn = pcl_kdtree_k(cloud,0,2);

    system("pause");
    return 0;
}
