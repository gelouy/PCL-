/*
* 随机下采样
*/

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/random_sample.h>

using namespace std;

pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_filter_ransac_sample(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in, int num)
{
    pcl::RandomSample<pcl::PointXYZ> rs;
    rs.setInputCloud(cloud_in);
    rs.setSample(num);//下采样到固定点

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out(new pcl::PointCloud<pcl::PointXYZ>);
    rs.filter(*cloud_out);

    return cloud_out;

}



//test------------//
int main(int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile(argv[1], *cloud);

    auto cloud_out = pcl_filter_ransac_sample(cloud, 1000);

    cout << "采样前点数：" << cloud->size() << endl;
    cout << "采样后点数：" << cloud_out->size() << endl;

    system("pause");
    return 0;
}

