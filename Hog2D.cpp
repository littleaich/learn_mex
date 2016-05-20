#include "Hog2D.h"

Hog2D::Hog2D() { }

Hog2D::~Hog2D() { }

int Hog2D::getCoordinateIndex(const int &i, const int &j, 
        const int &numRows)
{
    return j*numRows + i;
}

void Hog2D::setData(const double *im, const double *gx, 
        const double *gy, const hogParams_& hp)
{
    img = im;
    grad_x = gx;
    grad_y = gy;
    hogParams = hp;
}

void Hog2D::getDescriptors()
{
    
}
              
vector<vector<double> > Hog2D::getHog(const double *im, const double *gx , 
            const double *gy, const hogParams_& hp)
{
    setData(im,gx,gy,hp);
    getDescriptors();
    return desc;
}
