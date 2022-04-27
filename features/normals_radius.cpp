/*
* 计算半径内点的法线特征
*/
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/features/normal_3d_omp.h>

using namespace std;
pcl::PointCloud<pcl::Normal>::Ptr pcl_feature_normals_radius(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in, float radius)
{

    pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> ne;//创建法线估计对象
    ne.setInputCloud(cloud_in);//设置法线估计输入点云
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());	//创建一个空的kdtree
    ne.setSearchMethod(tree);
    pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);
    ne.setRadiusSearch(radius);	//设置半径邻域的大小
    ne.compute(*normals);

    return normals;

}

int main(int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile(argv[1], *cloud);

    auto normals = pcl_feature_normals_radius(cloud,2);

    system("pause");
    return 0;
}
