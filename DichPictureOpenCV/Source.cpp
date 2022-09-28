//Code demo Group 05

//Bao g?m th? vi?n
#include<opencv2/opencv.hpp>
#include<iostream>
//Namespace vô hi?u hóa vi?c s? d?ng cv::function();
using namespace std;
using namespace cv;
int main() {


	Mat image = imread("C:\\Users\\84395\\Music\\MEmu Music\\DichPictureOpenCV\\ptit.jpg");

	int height = image.cols;
	int width = image.rows;
	//nh?n các giá tr? tx và ty ?? d?ch
	float tx = float(width) / 6;
	float ty = float(height) / 6;
	//t?o ma tr?n d?ch s? d?ng tx và ty
	float warp_values[] = { 1.0, 0.0, tx, 0.0, 1.0, ty };
	Mat translation_matrix = Mat(2, 3, CV_32F, warp_values);
	Mat translated_image;
	//áp d?ng phép bi?n ??i affine cho hình ?nh g?c b?ng cách s? d?ng ma tr?n d?ch
	warpAffine(image, translated_image, translation_matrix, image.size());
	imshow("Anh da duoc dich", translated_image);
	imshow("AnhGoc", image);
	waitKey(0);
	imwrite("Anhduocdich.jpg", translated_image);
}
