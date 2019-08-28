#include <opencv2/opencv.hpp> 
#include <iostream> 
#include <windows.h>
#include <opencv2/highgui/highgui.hpp> 
#include <iostream> 
#include <conio.h> 
#include <stdio.h> 
#include "opencv2/imgproc/imgproc_c.h" 
#include <string.h>
#include <opencv2/highgui/highgui.hpp> 
#include <iostream> 
#include <conio.h> 
#include <stdio.h>  
#include <math.h> 
#include <atlbase.h>


using namespace cv;

IplImage* image;
int number_of_lines = 28;
int Byn_threshold = 170;



int main(int argc, char* argv[])
{

	
	
	cvNamedWindow("1", CV_WINDOW_AUTOSIZE);

	image = cvLoadImage("C:\\Users\\kirushka\\Documents\\учеба\\ПЧЕЛКА\\курсач\\Doc10.png", CV_LOAD_IMAGE_GRAYSCALE);
	int *i = new int[image->height];
	
	int *i1 = new int[image->height];
	for (int k = 0; k < image->height; k++)
	{
		i[k] = 0;
		i1[k] = 0;
	}
	

	
	
	
	//Бинаризация
		for (int y = 0; y < image->height; y++)
		{
			unsigned char* ptr = (unsigned char*)(image->imageData +
				y * image->widthStep);
			for (int x = 0; x < image->width; x++)
			{	
				if (ptr[x] < Byn_threshold)
					ptr[x] = 0;
				else
					ptr[x] = 255;

			}
		}	
		
		//выборка по строкам
		for (int y = 20; y < image->height-20; y++)
		{
			unsigned char* ptr = (unsigned char*)(image->imageData +
				y * image->widthStep);
			for (int x = 20; x < image->width-20; x++)
			{
				if (ptr[x] == 0)
					i[y]++;
				if (x>(image->width / 100) * 0.15 && x < (image->width/100)*6 && ptr[x] == 0)
					i1[y]++;
			}
		}
		
		int punkt = 0;
		bool check = false;
		//определение заполнения
		for (int y = 1; y < image->height; y++)
		{
			if (i1[y] > 5)
			{
				punkt++;
				int q = 0;
				for (int k = y-3; k > (y - image->height / number_of_lines +30); k--)
					q += i[k];
				if (q <= image->height*image->width*0.00001)
				{
					char w[5];
					_itoa(punkt, w, 10);
					check = true;
							printf("%d point is error\n", punkt);
							while (i[y] > 2)
							{
								y++;
							}
						
						continue;
					}
				else 
					while (i[y] > 10)
					{
						y++;
					}

			}

		}
		if (!check)
		{
			printf("all fine\n");
		}
		
		IplImage* image1 = cvCreateImage(cvSize(image->width / 4, image->height / 4), image->depth, image->nChannels);
		cvResize(image, image1, CV_INTER_CUBIC);
		cvShowImage("1", image1);
		
		
		waitKey();
	cvDestroyAllWindows();
	return 0;
}




