#include <stdio.h>
#include <stdlib.h>
#include "cv.h"
#include <assert.h>
BMPImage* Convolution2D(BMPImage* img,float kernel[3][3]);
int main(int argc, char* argv[])
{
    BMPImage* img = LoadBMPImage("C:\\Users\\DELL\\Desktop\\girl.bmp");
    BMPImage* convdImg1,*convdImg2,*convdImg3;
    /**Write your code here**/
    float const kernel1[3][3] = {{0.089,0.112,0.089},{0.112,0.100,0.112},{0.089,0.112,0.089}};
    float const kernel2[3][3] = {{-0.5,0,0},{0,0,0},{0,0,0.5}};
    float const kernel3[3][3] = {{-0.125,-0.125,-0.125},{-0.125,1,-0.125},{-0.125,-0.125,-0.125}};
    convdImg1 = Convolution2D(img, kernel1);
    if(SaveBMPImage("C:\\Users\\DELL\\Desktop\\gaussian.bmp", convdImg1))
    {
        printf("gaussian.bmp image processed.\n");
    }
    free(convdImg1);
    convdImg2 = Convolution2D(img, kernel2);
    if(SaveBMPImage("C:\\Users\\DELL\\Desktop\\sculpture.bmp", convdImg2))
    {
        printf("sculpture.bmp image processed.\n");
    }
    free(convdImg2);
    convdImg3 = Convolution2D(img, kernel3);
    if(SaveBMPImage("C:\\Users\\DELL\\Desktop\\outline.bmp", convdImg3))
    {
        printf("outline.bmp image processed.\n");
    }
    free(convdImg3);
    return 0;
}
BMPImage* Convolution2D(BMPImage* img,float kernel[3][3])
{
    int i,j;
    int width=img->width;
    int height=img->height;
    BMPImage *start=(BMPImage*)malloc(sizeof(img)),*now;
    for (i=0;i<height;i++)
    {
        for (j=0;j<width;j++)
        {
            now=start+i*width+j;
            if (i==0&&j==0)
            {
                now->imageData->B=(unsigned char)(kernel[1][1]*now->imageData->B+kernel[1][2]*(now+1)->imageData->B+kernel[2][1]*(now+width)->imageData->B+kernel[2][2]*(now+width+1)->imageData->B);
                now->imageData->G=(unsigned char)(kernel[1][1]*now->imageData->G+kernel[1][2]*(now+1)->imageData->G+kernel[2][1]*(now+width)->imageData->G+kernel[2][2]*(now+width+1)->imageData->G);
                now->imageData->R=(unsigned char)(kernel[1][1]*now->imageData->R+kernel[1][2]*(now+1)->imageData->R+kernel[2][1]*(now+width)->imageData->R+kernel[2][2]*(now+width+1)->imageData->R);
            }
            else if(i==0&&j==width-1)
            {
                now->imageData->B=(unsigned char)(kernel[1][1]*now->imageData->B+kernel[1][0]*(now-1)->imageData->B+kernel[2][1]*(now+width)->imageData->B+kernel[2][0]*(now+width-1)->imageData->B);
                now->imageData->G=(unsigned char)(kernel[1][1]*now->imageData->G+kernel[1][0]*(now-1)->imageData->G+kernel[2][1]*(now+width)->imageData->G+kernel[2][0]*(now+width-1)->imageData->G);
                now->imageData->R=(unsigned char)(kernel[1][1]*now->imageData->R+kernel[1][0]*(now-1)->imageData->R+kernel[2][1]*(now+width)->imageData->R+kernel[2][0]*(now+width-1)->imageData->R);
            }
            else if(i==height-1&&j==0)
            {
                now->imageData->B=(unsigned char)(kernel[1][1]*now->imageData->B+kernel[1][2]*(now+1)->imageData->B+kernel[0][1]*(now-width)->imageData->B+kernel[0][2]*(now-width+1)->imageData->B);
                now->imageData->G=(unsigned char)(kernel[1][1]*now->imageData->G+kernel[1][2]*(now+1)->imageData->G+kernel[0][1]*(now-width)->imageData->G+kernel[0][2]*(now-width+1)->imageData->G);
                now->imageData->R=(unsigned char)(kernel[1][1]*now->imageData->R+kernel[1][2]*(now+1)->imageData->R+kernel[0][1]*(now-width)->imageData->R+kernel[0][2]*(now-width+1)->imageData->R);
            }
            else if(i==height-1&&j==width-1)
            {
                now->imageData->B=(unsigned char)(kernel[1][1]*now->imageData->B+kernel[1][0]*(now-1)->imageData->B+kernel[0][1]*(now-width)->imageData->B+kernel[0][0]*(now-width-1)->imageData->B);
                now->imageData->G=(unsigned char)(kernel[1][1]*now->imageData->G+kernel[1][0]*(now-1)->imageData->G+kernel[0][1]*(now-width)->imageData->G+kernel[0][0]*(now-width-1)->imageData->G);
                now->imageData->R=(unsigned char)(kernel[1][1]*now->imageData->R+kernel[1][0]*(now-1)->imageData->R+kernel[0][1]*(now-width)->imageData->R+kernel[0][0]*(now-width-1)->imageData->R);
            }
            else if(i==0&&j>0&&j<width-1)
            {
                now->imageData->B=(unsigned char)(kernel[1][1]*now->imageData->B+kernel[1][2]*(now+1)->imageData->B+kernel[2][1]*(now+width)->imageData->B+kernel[2][2]*(now+width+1)->imageData->B+kernel[1][0]*(now-1)->imageData->B+kernel[2][0]*(now+width-1)->imageData->B);
                now->imageData->G=(unsigned char)(kernel[1][1]*now->imageData->G+kernel[1][2]*(now+1)->imageData->G+kernel[2][1]*(now+width)->imageData->G+kernel[2][2]*(now+width+1)->imageData->G+kernel[1][0]*(now-1)->imageData->G+kernel[2][0]*(now+width-1)->imageData->G);
                now->imageData->R=(unsigned char)(kernel[1][1]*now->imageData->R+kernel[1][2]*(now+1)->imageData->R+kernel[2][1]*(now+width)->imageData->R+kernel[2][2]*(now+width+1)->imageData->R+kernel[1][0]*(now-1)->imageData->R+kernel[2][0]*(now+width-1)->imageData->R);
            }
            else if(i==height-1&&j>0&&j<width-1)
            {
                now->imageData->B=(unsigned char)(kernel[1][1]*now->imageData->B+kernel[1][2]*(now+1)->imageData->B+kernel[0][1]*(now-width)->imageData->B+kernel[0][2]*(now-width+1)->imageData->B+kernel[1][0]*(now-1)->imageData->B+kernel[0][0]*(now-width-1)->imageData->B);
                now->imageData->G=(unsigned char)(kernel[1][1]*now->imageData->G+kernel[1][2]*(now+1)->imageData->G+kernel[0][1]*(now-width)->imageData->G+kernel[0][2]*(now-width+1)->imageData->G+kernel[1][0]*(now-1)->imageData->G+kernel[0][0]*(now-width-1)->imageData->G);
                now->imageData->R=(unsigned char)(kernel[1][1]*now->imageData->R+kernel[1][2]*(now+1)->imageData->R+kernel[0][1]*(now-width)->imageData->R+kernel[0][2]*(now-width+1)->imageData->R+kernel[1][0]*(now-1)->imageData->R+kernel[0][0]*(now-width-1)->imageData->R);
            }
            else if(j==0&&i>0&&i<height-1)
            {
                now->imageData->B=(unsigned char)(kernel[1][1]*now->imageData->B+kernel[1][2]*(now+1)->imageData->B+kernel[2][1]*(now+width)->imageData->B+kernel[2][2]*(now+width+1)->imageData->B+kernel[0][1]*(now-width)->imageData->B+kernel[0][2]*(now-width+1)->imageData->B);
                now->imageData->G=(unsigned char)(kernel[1][1]*now->imageData->G+kernel[1][2]*(now+1)->imageData->G+kernel[2][1]*(now+width)->imageData->G+kernel[2][2]*(now+width+1)->imageData->G+kernel[0][1]*(now-width)->imageData->G+kernel[0][2]*(now-width+1)->imageData->G);
                now->imageData->R=(unsigned char)(kernel[1][1]*now->imageData->R+kernel[1][2]*(now+1)->imageData->R+kernel[2][1]*(now+width)->imageData->R+kernel[2][2]*(now+width+1)->imageData->R+kernel[0][1]*(now-width)->imageData->R+kernel[0][2]*(now-width+1)->imageData->R);
            }
            else if(j==height-1&&i>0&&i<height-1)
            {
                now->imageData->B=(unsigned char)(kernel[1][1]*now->imageData->B+kernel[1][0]*(now-1)->imageData->B+kernel[2][1]*(now+width)->imageData->B+kernel[2][0]*(now+width-1)->imageData->B+kernel[0][1]*(now-width)->imageData->B+kernel[0][0]*(now-width-1)->imageData->B);
                now->imageData->G=(unsigned char)(kernel[1][1]*now->imageData->G+kernel[1][0]*(now-1)->imageData->G+kernel[2][1]*(now+width)->imageData->G+kernel[2][0]*(now+width-1)->imageData->G+kernel[0][1]*(now-width)->imageData->G+kernel[0][0]*(now-width-1)->imageData->G);
                now->imageData->R=(unsigned char)(kernel[1][1]*now->imageData->R+kernel[1][0]*(now-1)->imageData->R+kernel[2][1]*(now+width)->imageData->R+kernel[2][0]*(now+width-1)->imageData->R+kernel[0][1]*(now-width)->imageData->R+kernel[0][0]*(now-width-1)->imageData->R);
            }
            else
            {
                now->imageData->B=(unsigned char)(kernel[1][1]*now->imageData->B+kernel[1][2]*(now+1)->imageData->B+kernel[2][1]*(now+width)->imageData->B+kernel[2][2]*(now+width+1)->imageData->B+kernel[1][0]*(now-1)->imageData->B+kernel[2][0]*(now+width-1)->imageData->B+kernel[0][0]*(now-width-1)->imageData->B+kernel[0][1]*(now-width)->imageData->B+kernel[0][2]*(now-width+1)->imageData->B);
                now->imageData->G=(unsigned char)(kernel[1][1]*now->imageData->G+kernel[1][2]*(now+1)->imageData->G+kernel[2][1]*(now+width)->imageData->G+kernel[2][2]*(now+width+1)->imageData->G+kernel[1][0]*(now-1)->imageData->G+kernel[2][0]*(now+width-1)->imageData->G+kernel[0][0]*(now-width-1)->imageData->G+kernel[0][1]*(now-width)->imageData->G+kernel[0][2]*(now-width+1)->imageData->G);
                now->imageData->R=(unsigned char)(kernel[1][1]*now->imageData->R+kernel[1][2]*(now+1)->imageData->R+kernel[2][1]*(now+width)->imageData->R+kernel[2][2]*(now+width+1)->imageData->R+kernel[1][0]*(now-1)->imageData->R+kernel[2][0]*(now+width-1)->imageData->R+kernel[0][0]*(now-width-1)->imageData->R+kernel[0][1]*(now-width)->imageData->R+kernel[0][2]*(now-width+1)->imageData->R);
            }
        }
    }
    return start;
}
