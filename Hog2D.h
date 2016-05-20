#ifndef HOG2D_H
#define HOG2D_H

#include <vector>

using std::vector;

struct hogParams_ {
    int cellSize; // size of cells in pixels
    int blockSize; // size of blocks in cells
    int numBins; // number of bins (unoriented)
    int blockOverlap; // number of overlapped cells between adjacent blocks
    bool orientationSigned; // orientation signed or unsigned
    
    void operator=(const hogParams_ &x) const 
    {
        this->cellSize = x.cellSize;
        this->blockSize = x.blockSize;
        this->numBins = x.numBins;
        this->blockOverlap = x.blockOverlap;
        this->orientationSigned = x.orientationSigned;
    }
};

class Hog2D
{
    
public:
    Hog2D(hogParams_);
    ~Hog2D();
    vector<vector<double> > getHog(const double *, const double * , 
            const double *, const hogParams_&);
    
            
private:
    void setData(const double *, const double *, const double *,
            const hogParams_&);
    void getDescriptors(); // core HOG implementation
    int getCoordinateIndex(const int &, const int &, const int &); // 0-based
    
    double * img; // image pointer
    double * grad_x; // pointer to horizontal gradient matrix
    double * grad_y; // pointer to vertical gradient matrix
    struct hogParams_ hogParams; // hog parameters
    vector<vector<int> > desc; // descriptors
    
};

#endif HOG2D_H