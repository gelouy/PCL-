#include <pcl/io/pcd_io.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

	pcl::PCDReader reader;
	reader.read(argv[1],*cloud);

	cout << "点云数量：" << cloud->size() << endl;

	system("pause");
	return 0;
}
